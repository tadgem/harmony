#include "MonoProgramComponent.h"
#include "MonoAssemblyAssetFactory.h"
#include "MonoUtils.h"
#include "Core/Memory.h"
#include "Core/Program.h"
#include "Core/Log.hpp"
#include "MonoAPI.h"

harmony::MonoProgramComponent::MonoProgramComponent(AssetManager& assetManager) : ProgramComponent(GetTypeHash<MonoProgramComponent>())
, p_AssemblyConfig(MonoAssemblyConfiguration::Debug), m_AssetManager(assetManager)

{
    p_RootDomain = nullptr;
}
void harmony::MonoProgramComponent::Init()
{
    // TODO: Change to the project directory
    std::string root(std::getenv("MONO_PATH"));
    std::string assemblyDir = root + "/lib/mono/4.5";
    mono_set_assemblies_path(assemblyDir.c_str());

    if(p_RootDomain == nullptr)
    {
        p_RootDomain = mono_jit_init(p_RootDomainName.c_str());
    }

    if(p_RootDomain == nullptr)
    {
        harmony::log::error("MonoProgramComponent : Failed to create root domain.");
        return;
    }

    char* APP_DOMAIN_CONFIG = nullptr;
    p_AppDomain = mono_domain_create_appdomain((char*) p_AppDomainName.c_str(), APP_DOMAIN_CONFIG);

    if(p_AppDomain == nullptr)
    {
        harmony::log::error("MonoProgramComponent : Failed to create application domain.");
        return;
    }

    bool FORCE_SET = true;
    mono_domain_set(p_AppDomain, FORCE_SET);

    BindScriptingAPI();
}

void harmony::MonoProgramComponent::Update()
{
    for(MonoImplementedProgramComponent& c : p_MonoProgramComponents)
    {
        if(!c.m_HasUpdate) continue;
        MonoObject* exception = nullptr;
        mono_runtime_invoke(c.p_Update, c.p_MonoObject, nullptr, &exception);

        if(exception != nullptr)
        {
            log::error("MonoProgramComponent : Update : Exception during update for class. TODO improve");
        }
    }
}

void harmony::MonoProgramComponent::Render()
{
}

void harmony::MonoProgramComponent::Cleanup()
{
    for(MonoImplementedProgramComponent& c : p_MonoProgramComponents)
    {
        if(!c.m_HasCleanup) continue;
        MonoObject* exception = nullptr;
        mono_runtime_invoke(c.p_Cleanup, c.p_MonoObject, nullptr, &exception);

        if(exception != nullptr)
        {
            log::error("MonoProgramComponent : Cleanup : Exception during cleanup for class. TODO improve");
        }
    }
    p_MonoProgramComponents.clear();
    mono_domain_set(p_RootDomain, 0);
    mono_domain_unload(p_AppDomain);


}

nlohmann::json harmony::MonoProgramComponent::ToJson()
{
    auto j = nlohmann::json();

    auto& scripts = j["program-components"];

    for(auto mpc : p_MonoProgramComponents)
    {
        auto pcJson = nlohmann::json();
        pcJson["asset"] = mpc.m_AseemblyAsset;
        pcJson["typeInfo"] = mpc.m_TypeInfo;
        scripts.emplace_back(pcJson);
    }

    return j;
}

void harmony::MonoProgramComponent::FromJson(const nlohmann::json& json)
{
    if(!json.contains("program-components"))
    {
        return;
    }

    for(auto programComponentJson : json["program-components"])
    {
        AssetHandle assemblyAssetHandle = programComponentJson["asset"];
        MonoUtils::CsTypeInfo csTypeInfo = programComponentJson["typeInfo"];

        auto monoAssembly = m_AssetManager.GetAsset<MonoAssemblyAsset>(assemblyAssetHandle).lock();

        if(!monoAssembly)
        {
            log::error("MonoProgramComponent : FromJson : Failed to find mono assembly from {}", assemblyAssetHandle.Path);
            continue;
        }

        AddMonoImplementedProgramComponent(monoAssembly, csTypeInfo);
    }
}

void harmony::MonoProgramComponent::BindScriptingAPI()
{
    // Log
    mono_add_internal_call("Harmony.Log::Trace", harmony_mono_log_trace);
    mono_add_internal_call("Harmony.Log::Info", harmony_mono_log_info);
    mono_add_internal_call("Harmony.Log::Warn", harmony_mono_log_warn);
    mono_add_internal_call("Harmony.Log::Error", harmony_mono_log_error);

    // Time
    mono_add_internal_call("Harmony.Time::GetFrameTime", harmony_mono_get_frame_time);
    mono_add_internal_call("Harmony.Time::GetFrameTimeUnscaled", harmony_mono_get_frame_time_unscaled);
    mono_add_internal_call("Harmony.Time::GetTimeScale", harmony_mono_get_time_scale);
    mono_add_internal_call("Harmony.Time::SetTimeScale", harmony_mono_set_time_scale);

}

void
harmony::MonoProgramComponent::AddMonoImplementedProgramComponent(harmony::WeakRef<harmony::MonoAssemblyAsset> assembly,
                                                                  harmony::MonoUtils::CsTypeInfo typeInfo) {

    for(auto c : p_MonoProgramComponents)
    {
        if(c.m_TypeInfo == typeInfo)
        {
            log::warn("MonoProgramComponent : AddMonoImplementedProgramComponent : Already created a program component of type {}", typeInfo.m_TypeName);
            return;
        }
    }

    auto a = assembly.lock();
    if(!a)
    {
        log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Assembly is expired");
        return;
    }
    // Ensure type implements one of the program component behaviours
    bool implementsInit = false;
    bool implementsUpdate = false;
    bool implementsCleanup = false;

    for(MonoUtils::CsInterfaceImplInfo interfaceInfo : a->m_InterfaceImplInfos)    {
        if( interfaceInfo.m_ClassName == typeInfo.m_TypeName &&
            interfaceInfo.m_ClassNamespace == typeInfo.m_TypeNamespace)        {
            if(interfaceInfo.m_InterfaceNamespace == p_MonoProgramComponentNamespace) {
                if(interfaceInfo.m_InterfaceName == p_InitInterfaceName) {
                    implementsInit = true;
                }
                if(interfaceInfo.m_InterfaceName == p_UpdateInterfaceName) {
                    implementsUpdate = true;
                }
                if(interfaceInfo.m_InterfaceName == p_CleanupInterfaceName) {
                    implementsCleanup = true;
                }
            }
        }
    }
    if(!implementsInit && !implementsUpdate && !implementsCleanup)    {
        log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Type {} does not implement any ProgramComponent aspects.", typeInfo.m_TypeName);
        return;
    }

    if(!typeInfo.m_MonoClass)
    {
        typeInfo.m_MonoClass = MonoUtils::GetClassInAssembly(a->p_MonoAssembly, typeInfo.m_TypeNamespace.c_str(), typeInfo.m_TypeName.c_str());
    }

    if(!typeInfo.m_MonoClass)
    {
        log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Could not find MonoClass for Type {}", typeInfo.m_TypeName);
        return;
    }

    // Create instance
    MonoObject* classObject   = MonoUtils::CreateMonoObject(p_AppDomain, typeInfo);

    // Grab interface methods to call
    MonoClass * instanceClass = mono_object_get_class(classObject);
    MonoMethod* initMethod      = nullptr;
    MonoMethod* updateMethod    = nullptr;
    MonoMethod* cleanupMethod   = nullptr;

    if(implementsInit)    {
        initMethod = mono_class_get_method_from_name(instanceClass, p_InitMethodName.c_str(), 0);
        if(initMethod == nullptr) {
            log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Type {} implements IOnInit but does not have an Init method.", typeInfo.m_TypeName);
            return;
        }
        MonoObject * exception = nullptr;
        mono_runtime_invoke(initMethod, classObject, nullptr, &exception);
        if(exception != nullptr)
        {
            log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : exception encountered during init for type {}", typeInfo.m_TypeName);
        }
    }

    if(implementsUpdate)    {
        updateMethod = mono_class_get_method_from_name(instanceClass, p_UpdateMethodName.c_str(), 0);
        if(updateMethod == nullptr) {
            log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Type {} implements IOnUpdate but does not have an Update method.", typeInfo.m_TypeName);
            return;
        }
    }

    if(implementsCleanup) {
        cleanupMethod = mono_class_get_method_from_name(instanceClass, p_CleanupMethodName.c_str(), 0);
        if(cleanupMethod == nullptr) {
            log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Type {} implements IOnCleanup but does not have a Cleanup method.", typeInfo.m_TypeName);
            return;
        }
    }

    // Wrap in MonoImplementedProgramComponent
    MonoImplementedProgramComponent c = MonoImplementedProgramComponent(typeInfo, a->m_Handle, classObject, initMethod, updateMethod, cleanupMethod);

    // add to collection
    p_MonoProgramComponents.emplace_back(c);
}

harmony::MonoImplementedProgramComponent::~MonoImplementedProgramComponent() {
}

harmony::MonoImplementedProgramComponent::MonoImplementedProgramComponent(MonoUtils::CsTypeInfo typeInfo, AssetHandle assemblyAssetHandle, MonoObject *object, MonoMethod *init,
                                                                          MonoMethod *update, MonoMethod *cleanup) : p_MonoObject(object), m_AseemblyAsset(assemblyAssetHandle),
                                                                                                                     m_TypeInfo(typeInfo)
{
    p_Init = init;
    m_HasInit = p_Init != nullptr;
    p_Update = update;
    m_HasUpdate = p_Update != nullptr;
    p_Cleanup = cleanup;
    m_HasCleanup = p_Cleanup != nullptr;
}
