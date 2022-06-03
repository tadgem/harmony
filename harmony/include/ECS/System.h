#pragma once
#include "entt.hpp"
#include "json.hpp"

namespace harmony
{
    class System
    {
        public:
        virtual ~System() {};
        virtual void Init(entt::registry& registry) {};
        virtual void Update(entt::registry& registry) {};
        virtual void Render(entt::registry& registry) {};
        virtual void Cleanup(entt::registry& registry) {};
        virtual nlohmann::json SerializeSystem(entt::registry& registry) {} ;
        virtual void DeserializeSystem(entt::registry registry) {};
    };
};