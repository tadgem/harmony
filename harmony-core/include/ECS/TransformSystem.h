#pragma once
#include "ECS/System.h"
#include "glm.hpp"
#include "glm/gtc/quaternion.hpp"
namespace harmony
{
    struct TransformComponent;
    class TransformSystem : public System
    {
        public:
        TransformSystem();
        virtual void Init(entt::registry& registry) override;
        virtual void Update(entt::registry& registry) override;
        virtual void Render(entt::registry& registry) override;
        virtual void Cleanup(entt::registry& registry) override;
        virtual nlohmann::json SerializeSystem(entt::registry& registry) override;
        virtual void DeserializeSystem(entt::registry& registry, nlohmann::json systemJson) override;
        virtual void Refresh() override;

    protected:
        glm::vec3 CalculateVec3Radians(glm::vec3 eulerDegrees);
        glm::vec3 CalculateVec3Degrees(glm::vec3 eulerRadians);
        glm::quat CalculateRotationQuat(glm::vec3 eulerDegrees);

        void CalculateDirectionVectors(glm::vec3 eulerDegrees, TransformComponent& transform);
    };
};