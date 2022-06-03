#pragma once
#include "entt.hpp"
#include "json.hpp"
#include "ECS/Entity.h"
namespace harmony
{
    class Scene
    {
        public:
        Scene();

        Entity& AddEntity();

        entt::registry m_Registry;
    };
};