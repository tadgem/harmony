//
// Created by liam_ on 9/24/2023.
//
#include "MonoSystem.h"
#include "Assets/AssetManager.h"
#include "MonoProgramComponent.h"
#include "MonoAssembly.h"
#include "Core/Log.hpp"
harmony::MonoSystem::MonoSystem(WeakPtr<MonoProgramComponent> mono) : System(GetTypeHash<MonoSystem>()), p_Mono(mono)
{
}

void harmony::MonoSystem::Init(entt::registry& registry)
{
}

void harmony::MonoSystem::Update(entt::registry& registry)
{
}

void harmony::MonoSystem::Render(entt::registry& registry)
{
}

void harmony::MonoSystem::Cleanup(entt::registry& registry)
{
}

nlohmann::json harmony::MonoSystem::SerializeSystem(entt::registry& registry)
{
    auto j = nlohmann::json();
    auto view = registry.view<MonoBehaviourComponent>();
    for (auto [e, mono]: view.each()) {
        j[GetEntityKey(e)] = mono;
    }
    return j;
}

void harmony::MonoSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
    for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        nlohmann::json monoJson = entry.value();
        MonoBehaviourComponent mc;
        monoJson.get_to<MonoBehaviourComponent>(mc);
        // TODO: Add behaviours again.

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
    }
}

void harmony::MonoSystem::Refresh()
{
}

void harmony::MonoSystem::AddMonoBehaviour(entt::registry& registry, entt::entity entity, harmony::MonoUtils::CsTypeInfo typeInfo, WeakPtr<MonoAssemblyAsset> assemblyAsset) {
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

    // optional methods
    initMethod = mono_class_get_method_from_name(instanceClass, p_InitMethodName.c_str(), 0);
    if(initMethod != nullptr)
    {
        MonoObject * exception = nullptr;
        mono_runtime_invoke(initMethod, classObject, nullptr, &exception);
        if(exception != nullptr)
        {
            log::error("MonoSystem : AddMonoBehaviour : exception encountered during init for type {}", typeInfo.m_TypeName);
        }
    }

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
