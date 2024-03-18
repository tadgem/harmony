#pragma once

#include "Core/Alias.h"
#include <filesystem>
#include "Assets/AssetManager.h"
#include "Core/ProgramComponent.h"
#include "ECS/System.h"

namespace harmony {
    class Renderer;

    class Project {
        using json = Json;
    public:
        Project() {
        }

        Project(String name);

        ~Project() {
        }

        String m_ProjectName;
        String m_ProjectDirectory;
        String m_ImGuiIniPath;
        // TODO the key to this really should be a hashstring...
        Map<uint64_t, Json> p_ProgramComponentSerializationAttributes;
        Json m_AssetManagerSerializationAttributes;
        Json m_RendererSerializationAttributes;
        Vector<String> m_SerializedScenes;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(
                Project,
                m_ProjectName,
                m_ImGuiIniPath,
                p_ProgramComponentSerializationAttributes,
                m_AssetManagerSerializationAttributes,
                m_RendererSerializationAttributes,
                m_SerializedScenes)

    private:
        void UpdateProjectComponentSerializationAttributes(Vector<RefCntPtr<ProgramComponent>> &programComponents);

        void UpdateProjectAssetsSerializationAttributes(AssetManager &assetManager);

        void UpdateRendererSerializationAttributes(Renderer &renderer);

        friend class Program;

    };
};