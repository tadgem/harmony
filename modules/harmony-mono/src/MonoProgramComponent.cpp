#include "MonoProgramComponent.h"
#include "Core/Memory.h"

harmony::MonoProgramComponent::MonoProgramComponent()
{

}
void harmony::MonoProgramComponent::Init()
{
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
