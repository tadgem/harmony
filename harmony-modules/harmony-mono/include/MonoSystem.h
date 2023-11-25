//
// Created by liam_ on 9/24/2023.
//

#pragma once

#include "Core/Memory.h"
#include "ECS/System.h"
#include "MonoUtils.h"
#include "Assets/Asset.h"

namespace harmony {
    class MonoProgramComponent;
    class  MonoDelegateInvokeProvider;

    struct MonoBehaviour
    {
        MonoObject* m_Object;
        MonoMethod* p_Init;
        MonoMethod* p_Update;
        MonoMethod* p_Cleanup;

        MonoUtils::CsTypeInfo m_TypeInfo;
        AssetHandle m_AssemblyAsset;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(MonoBehaviour, m_TypeInfo, m_AssemblyAsset)
    };

    struct MonoBehaviourComponent
    {
        Vector<MonoBehaviour> m_Behaviours;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(MonoBehaviourComponent, m_Behaviours)
    };
    class MonoAssemblyAsset;
    class MonoSystem : public System {
    public:
        MonoSystem(
            WeakPtr<MonoProgramComponent> mono,
            Vector<RefCntPtr<MonoDelegateInvokeProvider>> delegateInvokers
            );

        void AddMonoBehaviour(entt::registry& registry, entt::entity entity, MonoUtils::CsTypeInfo typeInfo, WeakPtr<MonoAssemblyAsset> assemblyAsset);

        virtual void Init(entt::registry &registry) override;
        virtual void Update(entt::registry &registry) override;
        virtual void Render(entt::registry &registry) override;
        virtual void Cleanup(entt::registry &registry) override;
        virtual nlohmann::json SerializeSystem(entt::registry &registry) override;
        virtual void DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) override;
        virtual void Refresh() override;

        const String p_MonoBehaviourNamespace = "Harmony";
        const String p_MonoBehaviourTypename = "Behaviour";
        const String p_InitInterfaceName = "IOnInit";
        const String p_UpdateInterfaceName = "IOnUpdate";
        const String p_CleanupInterfaceName = "IOnCleanup";
        const String p_InitMethodName = "Init";
        const String p_UpdateMethodName = "Update";
        const String p_CleanupMethodName = "Cleanup";

    protected:
        WeakPtr<MonoProgramComponent> p_Mono;
        Vector<RefCntPtr<MonoDelegateInvokeProvider>> p_DelegateInvokers;
    };
}