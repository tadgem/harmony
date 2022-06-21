#pragma once
#include "Core/Memory.h"
#include "glm/glm.hpp"

namespace harmony
{
    class Camera
    {
    public:
        enum class ProjectionType
        {
            Orthorgraphic,
            Perspective
        };

        virtual glm::mat4 GetViewMatrix() = 0;
        virtual glm::mat4 GetProjectionMatrix(uint32_t width, uint32_t height) = 0;

        ProjectionType Type;
    };
};