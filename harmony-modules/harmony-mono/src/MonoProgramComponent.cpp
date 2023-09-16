#include "MonoProgramComponent.h"
#include "MonoAssemblyAssetFactory.h"
#include "MonoUtils.h"
#include "Core/Memory.h"
#include "Core/Program.h"
#include "Core/Log.hpp"

harmony::MonoProgramComponent::MonoProgramComponent() : ProgramComponent(GetTypeHash<MonoProgramComponent>())
, p_AssemblyConfig(MonoAssemblyConfiguration::Debug)

{

}
void harmony::MonoProgramComponent::Init()
{
    // TODO: Change to the project directory
    std::string root(std::getenv("MONO_PATH"));
    std::string assemblyDir = root + "/lib/mono/4.5";
    mono_set_assemblies_path(assemblyDir.c_str());

    p_RootDomain = mono_jit_init(p_RootDomainName.c_str());

    if(p_RootDomain == nullptr)
    {
        harmony::log::error("MonoProgramComponent : Failed to create root domain.");
        return;
    }

    static char* APP_DOMAIN_CONFIG = nullptr;
    p_AppDomain = mono_domain_create_appdomain((char*) p_AppDomainName.c_str(), APP_DOMAIN_CONFIG);

    if(p_AppDomain == nullptr)
    {
        harmony::log::error("MonoProgramComponent : Failed to create application domain.");
        return;
    }

    static bool FORCE_SET = true;
    mono_domain_set(p_AppDomain, FORCE_SET);

    BindScriptingAPI();

    for(MonoImplementedProgramComponent& c : p_MonoProgramComponents)
    {
        if(!c.m_HasInit) continue;
        MonoObject* exception = nullptr;
        mono_runtime_invoke(c.p_Init, c.p_MonoObject, nullptr, &exception);

        if(exception != nullptr)
        {
            log::error("MonoProgramComponent : Init : Exception during init for class. TODO improve");
        }
    }
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
}

nlohmann::json harmony::MonoProgramComponent::ToJson()
{
    return nlohmann::json();
}

void harmony::MonoProgramComponent::FromJson(const nlohmann::json& json)
{
}

void harmony::MonoProgramComponent::BindScriptingAPI()
{
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
        log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Type {} does not implement any ProgramComponent aspects.");
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
    MonoImplementedProgramComponent c = MonoImplementedProgramComponent(typeInfo, classObject, initMethod, updateMethod, cleanupMethod);

    // add to collection
    p_MonoProgramComponents.emplace_back(c);
}

harmony::MonoSystem::MonoSystem(WeakRef<MonoProgramComponent> mono) : System(GetTypeHash<MonoSystem>()), p_Mono(mono)
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

void harmony::AddMono(harmony::Program& program)
{
    // root component required for all mono functionality
    harmony::WeakRef<harmony::MonoProgramComponent> mono = program.AddProgramComponent<harmony::MonoProgramComponent>();
    // factory responsible for loading assembly binary + creating a mono object for the assembly.
    program.m_AssetManager.AddAssetFactory(harmony::CreateRef<harmony::MonoAssemblyAssetFactory>(mono));
    // Per scene Mono components
    program.AddSystem<harmony::MonoSystem>(mono);
}


harmony::MonoImplementedProgramComponent::~MonoImplementedProgramComponent() {
    mono_free(p_MonoObject);
}

harmony::MonoImplementedProgramComponent::MonoImplementedProgramComponent(MonoUtils::CsTypeInfo typeInfo, MonoObject *object, MonoMethod *init,
                                                                          MonoMethod *update, MonoMethod *cleanup) : p_MonoObject(object),
                                                                                                                     m_TypeInfo(typeInfo)
{
    p_Init = init;
    m_HasInit = p_Init != nullptr;
    p_Update = update;
    m_HasUpdate = p_Update != nullptr;
    p_Cleanup = cleanup;
    m_HasCleanup = p_Cleanup != nullptr;
}
