#include "MonoProgramComponent.h"
#include "MonoAssemblyAssetFactory.h"
#include "Core/Memory.h"
#include "Core/Program.h"
harmony::MonoProgramComponent::MonoProgramComponent()
{

}
void harmony::MonoProgramComponent::Init()
{
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

harmony::MonoSystem::MonoSystem() : System(GetTypeHash<MonoSystem>())
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
    program.AddSystem<harmony::MonoSystem>();
}
