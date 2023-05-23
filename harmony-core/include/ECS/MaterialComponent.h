#pragma once

#include "Rendering/Renderer.h"
#include "ThirdParty/json.hpp"
#include "Rendering/ShaderDataOverride.h"

namespace harmony {
    struct MaterialComponent {
        ShaderDataOverride Data;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(MaterialComponent, Data);
    };
};