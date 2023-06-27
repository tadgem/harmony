#pragma once

#include "ECS/System.h"
#include "glm.hpp"
#include "glm/gtc/quaternion.hpp"

namespace harmony {
    struct TransformComponent;

    class TransformSystem : public System {
    public:
        TransformSystem();

        virtual void Init(entt::registry &registry) override;

        virtual void Update(entt::registry &registry) override;

        virtual void Render(entt::registry &registry) override;

        virtual void Cleanup(entt::registry &registry) override;

        virtual nlohmann::json SerializeSystem(entt::registry &registry) override;

        virtual void DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) override;

        virtual void Refresh() override;

    protected:

        const int MINIMUM_GROUP_SIZE = 64;

        static void UpdateTransformComponent(TransformComponent *transform);

        static void CalculateDirectionVectors(glm::vec3 eulerDegrees, TransformComponent &transform);
    };
};