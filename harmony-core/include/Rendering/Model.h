#pragma once

#include "Assets/Asset.h"
#include "STL/Thread.h"
#include "Rendering/Mesh.h"

namespace harmony {
    struct ModelHandle {
        uint32_t Id;

        static ModelHandle CreateNew();

    private:
        static uint32_t p_Counter;
    };

    struct ModelEntry {
        AssetHandle Mesh;
        glm::vec3 Position;
        glm::vec3 Euler;
        glm::vec3 Scale;
        Vector<AssetHandle> Textures;
    };

    class Model : public Asset {
    public:
        Model(const String &name);

        String m_Name;
        AssetHandle m_ModelHandle;
        Vector<ModelEntry> m_Entries;
    };
}; // namespace harmony