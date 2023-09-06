#pragma once

#include "Rendering/Shaders/ShaderUniform.h"
#include "ThirdParty/json.hpp"
#include "glm.hpp"

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

} // namespace harmony