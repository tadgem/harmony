#pragma once
#include "ECS/System.h"

namespace harmony
{
    class TransformSystem : public System
    {
        public:
        TransformSystem();
        virtual void Init(entt::registry& registry) override;
        virtual void Update(entt::registry& registry) override;
        virtual void Render(entt::registry& registry) override;
        virtual void Cleanup(entt::registry& registry) override;
        virtual nlohmann::json SerializeSystem(entt::registry& registry) override;
        virtual void DeserializeSystem(entt::registry registry) override;
    };
};