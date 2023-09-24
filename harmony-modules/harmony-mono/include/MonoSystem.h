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

    class MonoSystem : public System {
    public:
        MonoSystem(WeakRef<MonoProgramComponent> mono);

        void AddMonoBehaviour(MonoUtils::CsTypeInfo typeInfo, AssetHandle assemblyAsset);

        virtual void Init(entt::registry &registry) override;
        virtual void Update(entt::registry &registry) override;
        virtual void Render(entt::registry &registry) override;
        virtual void Cleanup(entt::registry &registry) override;
        virtual nlohmann::json SerializeSystem(entt::registry &registry) override;
        virtual void DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) override;
        virtual void Refresh() override;

        const String p_MonoProgramComponentNamespace = "Harmony.Behaviour";
        const String p_InitInterfaceName = "IOnInit";
        const String p_UpdateInterfaceName = "IOnUpdate";
        const String p_CleanupInterfaceName = "IOnCleanup";
        const String p_InitMethodName = "Init";
        const String p_UpdateMethodName = "Update";
        const String p_CleanupMethodName = "Cleanup";

    protected:
        WeakRef<MonoProgramComponent> p_Mono;
    };
}