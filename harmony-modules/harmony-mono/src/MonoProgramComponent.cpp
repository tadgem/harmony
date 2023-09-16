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
}

void harmony::MonoProgramComponent::Update()
{
}

void harmony::MonoProgramComponent::Render()
{
}

void harmony::MonoProgramComponent::Cleanup()
{
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

harmony::MonoImplementedProgramComponent::MonoImplementedProgramComponent(harmony::MonoUtils::CsTypeInfo typeInfo,
                                                                          MonoObject *object) : p_MonoObject(object),
                                                                                                m_TypeInfo(typeInfo){

}

harmony::MonoImplementedProgramComponent::~MonoImplementedProgramComponent() {
    mono_free(p_MonoObject);
}
