#include <optick.h>
#include "ECS/Entity.h"

harmony::Entity::Entity() {
    OPTICK_EVENT();
}

harmony::Entity::Entity(entt::entity handle) : m_Handle(handle) {
    OPTICK_EVENT();
}

harmony::EntityData::EntityData()
{

}
