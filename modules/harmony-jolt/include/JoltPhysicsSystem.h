#pragma once
#include "ECS/System.h"
#include "Jolt/Jolt.h"

namespace harmony
{
    class JoltPhysicsSystem : public System
    {
    public:
        JoltPhysicsSystem();
        ~JoltPhysicsSystem() override;

        void Init(entt::registry &registry) override;
        void Update(entt::registry &registry) override;
        void Render(entt::registry &registry) override;
        void Cleanup(entt::registry &registry) override;
        nlohmann::json SerializeSystem(entt::registry &registry) override;
        void DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) override;

    protected:
        void Refresh() override;

    };
}