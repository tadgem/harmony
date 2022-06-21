#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
namespace harmony
{
    class MathsUtils
    {
    public:
        static glm::vec3 CalculateForwardVector(const glm::vec3& eulerAngles);

    };
};