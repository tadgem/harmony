#include "ECS/MaterialSystem.h"

nlohmann::json harmony::MaterialSystem::SerializeSystem(entt::registry& registry)
{
    return nlohmann::json();
}

void harmony::MaterialSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
}
