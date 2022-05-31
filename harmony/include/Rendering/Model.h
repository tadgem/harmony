#pragma once
#include "Rendering/Mesh.h"
#include "Assets/Asset.h"
#include "Core/Memory.h"
namespace harmony
{
    struct ModelHandle
    {
        uint32_t Id;

        static ModelHandle CreateNew();
        private:
        static uint32_t p_Counter;
    };

    class Model : public Asset
    {
    public:
        Model(const std::string& name);
        std::string m_Name;
        std::vector<std::string> m_MeshNames;
        std::vector<WeakRef<Mesh>> m_Meshes;
        ModelHandle m_Handle;
    };
};