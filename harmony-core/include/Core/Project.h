#pragma once

#include "ThirdParty/json.hpp"
#include <string>
#include <map>
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

        Project(std::string name);

        ~Project() {
        }

        std::string m_ProjectName;
        std::string m_ProjectDirectory;
        std::string m_ImGuiIniPath;
        // TODO the key to this really should be a hashstring...
        std::map<uint64_t, Json> p_ProgramComponentSerializationAttributes;
        Json m_AssetManagerSerializationAttributes;
        Json m_RendererSerializationAttributes;
        std::vector<std::string> m_SerializedScenes;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(
                Project,
                m_ProjectName,
                m_ImGuiIniPath,
                p_ProgramComponentSerializationAttributes,
                m_AssetManagerSerializationAttributes,
                m_RendererSerializationAttributes,
                m_SerializedScenes)

    private:
        void UpdateProjectComponentSerializationAttributes(std::vector<RefCntPtr<ProgramComponent>> &programComponents);

        void UpdateProjectAssetsSerializationAttributes(AssetManager &assetManager);

        void UpdateRendererSerializationAttributes(Renderer &renderer);

        friend class Program;

    };
};