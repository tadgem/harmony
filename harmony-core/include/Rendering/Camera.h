#pragma once
#include "Core/Memory.h"
#include "glm/glm.hpp"
#include "json.hpp"
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

        glm::mat4 View;
        glm::mat4 Projection;

        float FOV;
        float NearClipPlane, FarClipPlane;
        float Aspect;
        ProjectionType Type;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Camera, FOV, NearClipPlane, FarClipPlane, Aspect, Type);
    };
};