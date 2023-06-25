//
// Created by liam_ on 6/24/2023.
//

#ifndef HARMONY_DOJO_SKYCOMPONENT_H
#define HARMONY_DOJO_SKYCOMPONENT_H

#include "ThirdParty/json.hpp"
#include "glm/glm.hpp"


namespace harmony
{
    struct SkyComponent
    {
        float SunSize = 0.02f;
        float SunBloom = 0.2f;
        float Exposition = 0.1f;
        float Turbidity = 1.95f;
        glm::vec3 SkyLuminance = {0.308f,    0.308f,    0.410f};

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(SkyComponent, SunSize, SunBloom, Exposition, Turbidity, SkyLuminance)
    };
}

#endif //HARMONY_DOJO_SKYCOMPONENT_H
