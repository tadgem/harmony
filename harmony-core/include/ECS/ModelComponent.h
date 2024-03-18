#pragma once

#include "Rendering/Mesh.h"
#include "Rendering/Renderer.h"

namespace harmony {
    struct ModelComponent {
        Vector<BGFXMeshHandle> MeshHandles;
    };
};