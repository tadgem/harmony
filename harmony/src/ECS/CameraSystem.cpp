#include "ECS/CameraSystem.h"
#include "ECS/CameraComponent.h"
#include "Core/Memory.h"
harmony::CameraSystem::CameraSystem() : System(GetTypeHash<CameraComponent>())
{
}

void harmony::CameraSystem::Init(entt::registry& registry)
{
}

void harmony::CameraSystem::Update(entt::registry& registry)
{
}

void harmony::CameraSystem::Render(entt::registry& registry)
{
}

void harmony::CameraSystem::Cleanup(entt::registry& registry)
{
}

nlohmann::json harmony::CameraSystem::SerializeSystem(entt::registry& registry)
{
    return nlohmann::json();
}

void harmony::CameraSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
}
