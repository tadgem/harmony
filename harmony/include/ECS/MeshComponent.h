#pragma once
#include "Rendering/Mesh.h"
#include "Rendering/Renderer.h"
namespace harmony
{
    struct MeshComponent
    {
        AssetHandle MeshAsset;

        bool CastShadow;
    };
};