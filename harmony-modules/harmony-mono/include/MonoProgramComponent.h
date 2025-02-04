#pragma once
#include "Assets/Asset.h"
#include "Core/ProgramComponent.h"
#include "Core/Memory.h"
#include <mono/metadata/appdomain.h>
#include "MonoAssembly.h"
#include "MonoUtils.h"
#include "STL/Vector.h"
namespace harmony
{
    class AssetManager;
    class MonoImplementedProgramComponent
    {
    public:
        MonoImplementedProgramComponent(MonoUtils::CsTypeInfo typeInfo, AssetHandle assemblyAssetHandle, MonoObject* object, MonoMethod* init, MonoMethod* update, MonoMethod* cleanup);
        ~MonoImplementedProgramComponent();
        bool m_HasInit;
        bool m_HasUpdate;
        bool m_HasCleanup;
        MonoUtils::CsTypeInfo m_TypeInfo;
        AssetHandle m_AseemblyAsset;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(MonoImplementedProgramComponent, m_TypeInfo, m_AseemblyAsset);
    protected:
        MonoObject* p_MonoObject;
        MonoMethod* p_Init;
        MonoMethod* p_Update;
        MonoMethod* p_Cleanup;

        friend class MonoProgramComponent;
    };

    class MonoInternalMethodProvider
    {
    public:
        virtual void BindInternalMethods() = 0;
    };

    class MonoDelegateInvokeProvider
    {
    public:
        virtual void ProcessDelegates() = 0;
        virtual void ClearDelegates() = 0;
        virtual uint32_t NumCallbacks() = 0;
    };

    class Program;
    class MonoProgramComponent : public ProgramComponent
    {
    public:
        MonoProgramComponent(
            AssetManager& assetManager,
            Vector<RefCntPtr<MonoInternalMethodProvider>> methodProviders,
            Vector<RefCntPtr<MonoDelegateInvokeProvider>> delegateInvokers
            );
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Cleanup() override;
        virtual Json ToJson() override;
        virtual void FromJson(const Json& json) override;

        void BindScriptingAPI();

        MonoType*   GetType(String& name);
        MonoDomain* GetAppDomain();
        AssetManager& m_AssetManager;

        void AddMonoImplementedProgramComponent(WeakPtr<MonoAssemblyAsset> assembly, MonoUtils::CsTypeInfo typeInfo);

    protected:
        MonoDomain* p_RootDomain;
        MonoDomain* p_AppDomain;
        // TODO: Make this customizable per-application
        const String p_RootDomainName = "Harmony";
        const String p_AppDomainName = "GameTest";
        const String p_MonoProgramComponentNamespace = "Harmony.ProgramComponent";
        const String p_MonoModuleNamespace = "Harmony.Module";
        const String p_InitInterfaceName = "IOnInit";
        const String p_UpdateInterfaceName = "IOnUpdate";
        const String p_CleanupInterfaceName = "IOnCleanup";
        const String p_InitMethodName = "Init";
        const String p_UpdateMethodName = "Update";
        const String p_CleanupMethodName = "Cleanup";
        const MonoAssemblyConfiguration p_AssemblyConfig;

        Vector<MonoImplementedProgramComponent> p_MonoProgramComponents;
        Vector<RefCntPtr<MonoInternalMethodProvider>> p_MethodProviders;
        Vector<RefCntPtr<MonoDelegateInvokeProvider>> p_DelegateInvokers;

        friend class MonoPanel;
        friend class MonoSystem;
    };
}