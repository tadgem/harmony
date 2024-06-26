//
// Created by liam_ on 9/24/2023.
//
#include "optick.h"
#include "MonoSystem.h"
#include "Assets/AssetManager.h"
#include "MonoProgramComponent.h"
#include "MonoAssembly.h"
#include "Core/Log.hpp"
harmony::MonoSystem::MonoSystem(
    WeakPtr<MonoProgramComponent> mono,
    Vector<RefCntPtr<MonoDelegateInvokeProvider>> delegateInvokers)
    : System(GetTypeHash<MonoSystem>()), p_Mono(mono), p_DelegateInvokers(delegateInvokers)

{
}

void harmony::MonoSystem::Init(entt::registry& registry)
{
    OPTICK_EVENT()
    auto view = registry.view<MonoBehaviourComponent>();

    for (auto [e, mono]: view.each()) {
        for(auto behaviour : mono.m_Behaviours)
        {
            if(behaviour.p_Init != nullptr)
            {
                MonoObject * exception = nullptr;
                mono_runtime_invoke(behaviour.p_Init, behaviour.m_Object, nullptr, &exception);
                if(exception != nullptr)
                {
                    log::error("MonoSystem : AddMonoBehaviour : exception encountered during init for type {} on entity {}", behaviour.m_TypeInfo.m_TypeName, (uint32_t)e);
                }
            }
        }
    }
}

void harmony::MonoSystem::Update(entt::registry& registry)
{
    OPTICK_EVENT()
    auto view = registry.view<MonoBehaviourComponent>();

    uint32_t processedBehaviours = 0;
    for (auto [e, mono]: view.each())
    {
        for(auto behaviour : mono.m_Behaviours)
        {
            if(behaviour.p_Update != nullptr)
            {
                MonoObject * exception = nullptr;
                mono_runtime_invoke(behaviour.p_Update, behaviour.m_Object, nullptr, &exception);
                processedBehaviours++;
                if(exception != nullptr)
                {
                    log::error("MonoSystem : AddMonoBehaviour : exception encountered during update for type {} on entity {}", behaviour.m_TypeInfo.m_TypeName, (uint32_t)e);
                }
            }
        }
    }

    for(auto& d : p_DelegateInvokers)
    {
        d->ProcessDelegates();
        processedBehaviours += d->NumCallbacks();
    }

    OPTICK_TAG("Num Callbacks", processedBehaviours);
}

void harmony::MonoSystem::Render(entt::registry& registry)
{
    OPTICK_EVENT()
}

void harmony::MonoSystem::Cleanup(entt::registry& registry)
{
    OPTICK_EVENT()
    auto view = registry.view<MonoBehaviourComponent>();

    for (auto [e, mono]: view.each()) {
        registry.remove<MonoBehaviourComponent>(e);
    }

    for(auto& provider : p_DelegateInvokers)
    {
        provider->ClearDelegates();
    }
}

harmony::Json harmony::MonoSystem::SerializeSystem(entt::registry& registry)
{
    OPTICK_EVENT()
    auto j = Json();
    auto view = registry.view<MonoBehaviourComponent>();
    for (auto [e, mono]: view.each())
    {
        j[GetEntityKey(e)] = mono;
    }
    return j;
}

void harmony::MonoSystem::DeserializeSystem(entt::registry& registry, Json systemJson)
{
    OPTICK_EVENT()
    String jsonStr = systemJson.dump();
    for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        Json monoJson = entry.value();
        DeserializeEntity(registry, e, monoJson);
    }
}

harmony::Json harmony::MonoSystem::SerializeEntity(entt::registry& registry, entt::entity e)
{
    OPTICK_EVENT();
    Json j;

    if(registry.any_of<MonoBehaviourComponent>(e))
    {
        MonoBehaviourComponent& t = registry.get<MonoBehaviourComponent>(e);
        j = t;
    }

    return j;
}

void harmony::MonoSystem::DeserializeEntity(entt::registry& registry, entt::entity e, Json entityJson)
{
    MonoBehaviourComponent mc;
    entityJson.get_to<MonoBehaviourComponent>(mc);
    auto newMC = registry.emplace<MonoBehaviourComponent>(e);

    for(MonoBehaviour m : mc.m_Behaviours)
    {
        WeakPtr<MonoAssemblyAsset> assemblyAsset = p_Mono.lock()->m_AssetManager.GetAsset<MonoAssemblyAsset>(m.m_AssemblyAsset);
        if(assemblyAsset.expired())
        {
            log::error("MonoSystem : Deserialize System : Failed to get assembly {} when deserializing behaviour {} for entity {}", m.m_AssemblyAsset.Path, m.m_TypeInfo.m_TypeName, ((uint32_t )e));
            continue;
        }
        AddMonoBehaviour(registry, e, m.m_TypeInfo, assemblyAsset);
    }
    OPTICK_EVENT()
}

void harmony::MonoSystem::Refresh()
{
    OPTICK_EVENT()
}

void harmony::MonoSystem::AddMonoBehaviour(entt::registry& registry, entt::entity entity, harmony::MonoUtils::CsTypeInfo typeInfo, WeakPtr<MonoAssemblyAsset> assemblyAsset) {
    OPTICK_EVENT()
    auto a = assemblyAsset.lock();
    if(!a)
    {
        log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Assembly is expired");
        return;
    }

    bool isBehaviour = false;

    for(auto derivedType : a->m_DerivedTypeInfos)
    {
        if( derivedType == typeInfo)
        {
            if( derivedType.m_ParentTypeNamespace == p_MonoBehaviourNamespace &&
                derivedType.m_ParentTypeName == p_MonoBehaviourTypename)
            {
                isBehaviour = true;
            }
        }
    }

    if(!isBehaviour)
    {
        log::error("MonoSystem : AddMonoBehaviour : Type {} is not a Harmony.Behaviour! ignoring.", typeInfo.m_TypeName);
        return;
    }
    // We need to change this.
    // We will set Behaviour's entity property, likely protecting derived classes from changing entity.
    if(!typeInfo.m_MonoClass)
    {
        typeInfo.m_MonoClass = MonoUtils::GetClassInAssembly(a->p_MonoAssembly, typeInfo.m_TypeNamespace.c_str(), typeInfo.m_TypeName.c_str());
    }

    if(!typeInfo.m_MonoClass)
    {
        log::error("MonoSystem : AddMonoBehaviour : Could not find MonoClass for Type {}", typeInfo.m_TypeName);
        return;
    }

    // Create instance
    MonoObject* classObject   = MonoUtils::CreateMonoObject(p_Mono.lock()->p_AppDomain, typeInfo);

    // Grab interface methods to call
    MonoClass * instanceClass = mono_object_get_class(classObject);
    MonoMethod* initMethod      = nullptr;
    MonoMethod* updateMethod    = nullptr;
    MonoMethod* cleanupMethod   = nullptr;

    // Set Self (entity)
    MonoClassField* entityField = mono_class_get_field_from_name(instanceClass, "Self");
    mono_field_set_value(classObject, entityField, &entity);

    initMethod = mono_class_get_method_from_name(instanceClass, p_InitMethodName.c_str(), 0);
    updateMethod = mono_class_get_method_from_name(instanceClass, p_UpdateMethodName.c_str(), 0);
    cleanupMethod = mono_class_get_method_from_name(instanceClass, p_CleanupMethodName.c_str(), 0);

    MonoBehaviour monoBehaviour
    {
        classObject,
        initMethod,
        updateMethod,
        cleanupMethod,
        typeInfo,
        a->m_Handle
    };

    if(!registry.any_of<MonoBehaviourComponent>(entity))
    {
        registry.emplace<MonoBehaviourComponent>(entity);
    }

    auto& behaviourComponent = registry.get<MonoBehaviourComponent>(entity);

    behaviourComponent.m_Behaviours.push_back(monoBehaviour);
}
