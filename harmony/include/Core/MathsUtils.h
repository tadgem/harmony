#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
namespace harmony
{
    class MathsUtils
    {
    public:
        static glm::vec3 CalculateForwardVector(const glm::vec3& eulerAngles);
        static glm::vec3 CalculateRightVector(const glm::vec3& eulerAngles);
        static glm::vec3 CalculateUpVector(const glm::vec3& forward, const glm::vec3& right);
    };
};