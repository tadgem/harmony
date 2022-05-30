#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"

namespace harmony
{
    struct TransformComponent
    {
        glm::vec3 Position;
        glm::vec3 Scale;
        glm::vec3 Euler;
        glm::quat Rotation;

        glm::mat4 Model;
    };
};