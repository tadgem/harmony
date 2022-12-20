#pragma once
#include "json.hpp"
#include <string>
#include <map>
#include <filesystem>
#include "Assets/AssetManager.h"
#include "Core/ProgramComponent.h"
#include "ECS/System.h"

namespace harmony
{
    class Renderer;

    class Project
    {
        using json = nlohmann::json;
    public:
        Project() {}
        Project(std::string name);
        ~Project() {}
        std::string m_ProjectName;
        std::string m_ProjectDirectory;
        std::string m_ImGuiIniPath;

        void Save();
        void Load(AssetManager& assetManager, Renderer& renderer);
        void Unload(AssetManager& assetManager);

        std::map<size_t, nlohmann::json>    p_ProgramComponentSerializationAttributes;
        nlohmann::json m_AssetManagerSerializationAttributes;
        nlohmann::json m_RendererSerializationAttributes;
        std::vector<std::string>         m_SerializedScenes;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(
            Project, 
            m_ProjectName, 
            m_ImGuiIniPath, 
            p_ProgramComponentSerializationAttributes, 
            m_AssetManagerSerializationAttributes,
            m_RendererSerializationAttributes,
            m_SerializedScenes)
    private:
        void UpdateProjectComponentSerializationAttributes(std::vector<Ref<ProgramComponent>>& programComponents);
        void UpdateProjectAssetsSerializationAttributes(AssetManager& assetManager);
        void UpdateRendererSerializationAttributes(Renderer& renderer);
        friend class Program;

    };
};