#pragma once
#include "Core/ProgramComponent.h"
#include "Core/Memory.h"
#include "ECS/System.h"
#include <mono/metadata/appdomain.h>
#include "MonoAssembly.h"
#include "MonoUtils.h"
namespace harmony
{
    class MonoImplementedProgramComponent
    {
    public:
        MonoImplementedProgramComponent(MonoUtils::CsTypeInfo typeInfo, MonoObject* object, MonoMethod* init, MonoMethod* update, MonoMethod* cleanup);
        ~MonoImplementedProgramComponent();
        bool m_HasInit;
        bool m_HasUpdate;
        bool m_HasCleanup;
        const MonoUtils::CsTypeInfo m_TypeInfo;
    protected:
        MonoObject* p_MonoObject;
        MonoMethod* p_Init;
        MonoMethod* p_Update;
        MonoMethod* p_Cleanup;

        friend class MonoProgramComponent;
    };

    class Program;
    class MonoProgramComponent : public ProgramComponent
    {
    public:
        MonoProgramComponent();
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Cleanup() override;
        virtual nlohmann::json ToJson() override;
        virtual void FromJson(const nlohmann::json& json) override;

        virtual void BindScriptingAPI();

        void AddMonoImplementedProgramComponent(WeakRef<MonoAssemblyAsset> assembly, MonoUtils::CsTypeInfo typeInfo);

    protected:
        MonoDomain* p_RootDomain;
        MonoDomain* p_AppDomain;
        // TODO: Make this customizable per-application
        const String p_RootDomainName = "Harmony";
        const String p_AppDomainName = "HarmonyApp";
        const String p_MonoProgramComponentNamespace = "HarmonyMono.ProgramComponent";
        const String p_InitInterfaceName = "IOnInit";
        const String p_UpdateInterfaceName = "IOnUpdate";
        const String p_CleanupInterfaceName = "IOnCleanup";
        const String p_InitMethodName = "Init";
        const String p_UpdateMethodName = "Update";
        const String p_CleanupMethodName = "Cleanup";
        const MonoAssemblyConfiguration p_AssemblyConfig;

        Vector<MonoImplementedProgramComponent> p_MonoProgramComponents;
    };

    class MonoSystem : public System
    {
    public:
        MonoSystem(WeakRef<MonoProgramComponent> mono);
        virtual void Init(entt::registry& registry) override;
        virtual void Update(entt::registry& registry) override;
        virtual void Render(entt::registry& registry) override;
        virtual void Cleanup(entt::registry& registry) override;
        virtual nlohmann::json SerializeSystem(entt::registry& registry) override;
        virtual void DeserializeSystem(entt::registry& registry, nlohmann::json systemJson) override;
        virtual void Refresh() override;

    protected:
        WeakRef<MonoProgramComponent> p_Mono;
    };

    void AddMono(harmony::Program& program);
}