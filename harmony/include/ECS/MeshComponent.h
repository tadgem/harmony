#pragma once
#include "Rendering/Mesh.h"
#include "Rendering/Renderer.h"
namespace harmony
{
    struct MeshComponent
    {
        AssetHandle MeshAsset;
        BGFXMeshHandle MeshHandle;
        bool CastShadow;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(MeshComponent, MeshAsset, CastShadow)
    };
};