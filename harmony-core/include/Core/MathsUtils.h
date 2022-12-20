#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/quaternion.hpp"
namespace harmony
{
    class MathsUtils
    {
    public:
        static glm::vec3 CalculateForwardVector(const glm::vec3& eulerAngles);
        static glm::vec3 CalculateRightVector(const glm::vec3& eulerAngles);
        static glm::vec3 CalculateUpVector(const glm::vec3& forward, const glm::vec3& right);

        static glm::vec3 CalculateForwardVector(const glm::quat& rot);
        static glm::vec3 CalculateRightVector(const glm::quat& rot);
        static glm::vec3 CalculateUpVector(const glm::quat& rot);
    };
};