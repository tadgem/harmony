#pragma once
#include "entt.hpp"

namespace harmony
{
    class System
    {
        public:
        virtual ~System() {};
        virtual void Init(entt::registry& registry) = 0;
        virtual void Update(entt::registry& registry) = 0;
        virtual void Render(entt::registry& registry) = 0;
        virtual void Cleanup(entt::registry& registry) = 0;
    };
};