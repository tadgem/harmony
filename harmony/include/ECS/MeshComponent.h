#pragma once
#include "Rendering/Mesh.h"
#include "Rendering/Renderer.h"
namespace harmony
{
    struct MeshComponent
    {
        BGFXMeshHandle Handle;
        RenderState State;
    };
};