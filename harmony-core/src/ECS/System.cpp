#include "ECS/System.h"

std::string harmony::System::GetEntityKey(entt::entity& entity)
{
    uint32_t handle = static_cast<uint32_t>(entity);
    return std::to_string(handle);
}

entt::entity harmony::System::GetEntityFromKey(const std::string& key)
{
    uint32_t handle = std::stoul(key);
    return entt::entity(handle);
}
