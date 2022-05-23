#pragma once
#include "entt.hpp"

namespace harmony
{
    class Scene
    {
        public:
        Scene();

        entt::registry m_Registry;
    };
};