#pragma once
#include "Rendering/Mesh.h"
#include "Assets/Asset.h"
#include "Core/Memory.h"
namespace harmony
{
    class Model : Asset
    {
    public:
        Model();

        std::vector<std::string> m_MeshNames;
        std::vector<WeakRef<Mesh>> m_Meshes;

    private:

    };
};