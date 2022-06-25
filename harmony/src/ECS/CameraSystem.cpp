#include "ECS/CameraSystem.h"

nlohmann::json harmony::CameraSystem::SerializeSystem(entt::registry& registry)
{
    return nlohmann::json();
}

void harmony::CameraSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
}
