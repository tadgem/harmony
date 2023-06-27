#include <optick.h>
#include "ECS/System.h"

std::string harmony::System::GetEntityKey(entt::entity &entity)
{
	OPTICK_EVENT();
	uint32_t handle = static_cast<uint32_t>(entity);
	return std::to_string(handle);
}

entt::entity harmony::System::GetEntityFromKey(const std::string &key)
{
	OPTICK_EVENT();
	uint32_t handle = std::stoul(key);
	return entt::entity(handle);
}
