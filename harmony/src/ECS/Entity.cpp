#include "ECS/Entity.h"

harmony::Entity::Entity(entt::entity handle, entt::registry& registry) : m_Handle(handle), p_Registry(registry)
{
	
}
