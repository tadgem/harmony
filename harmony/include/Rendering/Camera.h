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

        glm::mat4 View;
        glm::mat4 Projection;

        float FOV;
        float NearClipPlane, FarClipPlane;

        ProjectionType Type;
    };
};