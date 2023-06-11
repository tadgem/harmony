#pragma once

#include "glm.hpp"
#include "ThirdParty/json.hpp"
#include "Rendering/Shaders/ShaderUniform.h"

namespace harmony {

    struct AABB {
        glm::vec3 Min;
        glm::vec3 Max;
    };

    struct Sphere {
        glm::vec4 PosR;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Sphere, PosR)
    };

    struct Ray {
        glm::vec3 Origin;
        glm::vec3 Direction;
    };

    struct RayHit {
        RayHit(glm::vec4 position, float distance);

        glm::vec4 Position;
        float Distance;
    };

}