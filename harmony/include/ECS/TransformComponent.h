#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"

namespace harmony
{
    struct TransformComponent
    {
        TransformComponent()
        {
            Position = glm::vec3(0.0);
            Scale = glm::vec3(1.0);
            Euler = glm::vec3(0.0);
            Rotation = glm::quat();
            Model = glm::mat4(1.0);
        }
        glm::vec3 Position;
        glm::vec3 Scale;
        glm::vec3 Euler;
        glm::quat Rotation;

        glm::mat4 Model;
    };
};