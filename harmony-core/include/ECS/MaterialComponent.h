#pragma once

#include "Rendering/Renderer.h"
#include "STL/Json.hpp"
#include "Rendering/Shaders/ShaderDataOverride.h"

namespace harmony {
    struct MaterialComponent {
        ShaderDataOverride Data;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(MaterialComponent, Data);
    };
};