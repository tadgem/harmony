//
// Created by liam_ on 9/24/2023.
//
#include "MonoSystem.h"
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
    return nlohmann::json();
}

void harmony::MonoSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
}

void harmony::MonoSystem::Refresh()
{
}

harmony::Optional<harmony::MonoBehaviour> harmony::MonoSystem::AddMonoBehaviour(entt::entity entity, harmony::MonoUtils::CsTypeInfo typeInfo, WeakPtr<MonoAssemblyAsset> assemblyAsset) {
    auto a = assemblyAsset.lock();
    if(!a)
    {
        log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Assembly is expired");
        return {};
    }
    // Ensure type implements one of the program component behaviours
    bool implementsInit         = false;
    bool implementsUpdate       = false;
    bool implementsCleanup      = false;
    bool implementsBehaviour    = false;

    for(MonoUtils::CsInterfaceImplInfo interfaceInfo : a->m_InterfaceImplInfos)    {
        if( interfaceInfo.m_ClassName == typeInfo.m_TypeName &&
            interfaceInfo.m_ClassNamespace == typeInfo.m_TypeNamespace)        {
            if(interfaceInfo.m_InterfaceNamespace == p_MonoBehaviourNamespace) {
                if(interfaceInfo.m_InterfaceName == p_InitInterfaceName) {
                    implementsInit = true;
                }
                if(interfaceInfo.m_InterfaceName == p_UpdateInterfaceName) {
                    implementsUpdate = true;
                }
                if(interfaceInfo.m_InterfaceName == p_CleanupInterfaceName) {
                    implementsCleanup = true;
                }
                if(interfaceInfo.m_InterfaceName == p_MonoBehaviourNamespace)
                {
                    implementsBehaviour = true;
                }
            }
        }
    }

    if(!implementsBehaviour)
    {
        log::error("MonoSystem : AddMonoBehaviour : Type {} is not a Harmony.Behaviour! ignoring.", typeInfo.m_TypeName);
        return {};
    }
    // We need to change this.
    // Implementing a behaviour aspect should be optional, but the type MUST derive Behaviour.
    // We will set Behaviour's entity property, likely protecting derived classes from changing entity.
    if(!typeInfo.m_MonoClass)
    {
        typeInfo.m_MonoClass = MonoUtils::GetClassInAssembly(a->p_MonoAssembly, typeInfo.m_TypeNamespace.c_str(), typeInfo.m_TypeName.c_str());
    }

    if(!typeInfo.m_MonoClass)
    {
        log::error("MonoSystem : AddMonoBehaviour : Could not find MonoClass for Type {}", typeInfo.m_TypeName);
        return {};
    }

    // Create instance
    MonoObject* classObject   = MonoUtils::CreateMonoObject(p_Mono.lock()->p_AppDomain, typeInfo);

    // Grab interface methods to call
    MonoClass * instanceClass = mono_object_get_class(classObject);
    MonoMethod* initMethod      = nullptr;
    MonoMethod* updateMethod    = nullptr;
    MonoMethod* cleanupMethod   = nullptr;

    if(implementsInit)    {
        initMethod = mono_class_get_method_from_name(instanceClass, p_InitMethodName.c_str(), 0);
        if(initMethod == nullptr) {
            log::error("MonoSystem : AddMonoBehaviour : Type {} implements IOnInit but does not have an Init method.", typeInfo.m_TypeName);
            return {};
        }
        MonoObject * exception = nullptr;
        mono_runtime_invoke(initMethod, classObject, nullptr, &exception);
        if(exception != nullptr)
        {
            log::error("MonoSystem : AddMonoBehaviour : exception encountered during init for type {}", typeInfo.m_TypeName);
        }
    }

    if(implementsUpdate)    {
        updateMethod = mono_class_get_method_from_name(instanceClass, p_UpdateMethodName.c_str(), 0);
        if(updateMethod == nullptr) {
            log::error("MonoSystem : AddMonoBehaviour : Type {} implements IOnUpdate but does not have an Update method.", typeInfo.m_TypeName);
            return {};
        }
    }

    if(implementsCleanup) {
        cleanupMethod = mono_class_get_method_from_name(instanceClass, p_CleanupMethodName.c_str(), 0);
        if(cleanupMethod == nullptr) {
            log::error("MonoSystem : AddMonoBehaviour : Type {} implements IOnCleanup but does not have a Cleanup method.", typeInfo.m_TypeName);
            return {};
        }
    }

    MonoBehaviour monoBehaviour
    {
        classObject,
        initMethod,
        updateMethod,
        cleanupMethod,
        typeInfo,
        a->m_Handle
    };

    return monoBehaviour;
}
