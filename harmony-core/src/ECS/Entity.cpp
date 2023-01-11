#include "ECS/Entity.h"

harmony::Entity::Entity()
{
}

harmony::Entity::Entity(entt::entity handle) : m_Handle(handle)
{
}
