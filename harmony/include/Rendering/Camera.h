#pragma once
#include "Core/Memory.h"
#include "glm/glm.hpp"

namespace harmony
{
    class Camera
    {
    public:
        enum ProjectionType
        {
            Orthorgraphic,
            Perspective
        };

        virtual glm::mat4 GetViewMatrix() = 0;
        virtual glm::mat4 GetProjectionMatrix() = 0;

    };
};