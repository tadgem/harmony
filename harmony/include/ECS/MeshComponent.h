#pragma once
#include "Rendering/Mesh.h"
#include "Rendering/Renderer.h"
namespace harmony
{
    struct MeshComponent
    {
        std::string MeshAssetPath;
        uint32_t Index;

        bool CastShadow;
    };
};