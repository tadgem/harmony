#pragma once
#include "Rendering/Renderer.h"
namespace harmony
{
    struct MaterialComponent
    {
        ShaderDataContainer Data;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(MaterialComponent, Data);
    };
};