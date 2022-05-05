#pragma once
#include "json.hpp"
#include <string>
#include <map>
#include <filesystem>
#include "Assets/AssetManager.h"
#include "Core/ProgramComponent.h"

namespace harmony
{
    class Project
    {
        using json = nlohmann::json;
    public:
        Project() {}
        Project(std::string projectPath, std::string projectDirectory);
        ~Project() {}
        std::string m_ProjectPath;
        std::string m_ProjectDirectory;
        std::string m_ImGuiIniPath;

        void Save();
        void Load();
        void Unload(AssetManager& assetManager);

        std::map<size_t, nlohmann::json> p_ProgramComponentSerializationAttributes;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Project, m_ProjectPath, m_ProjectDirectory, m_ImGuiIniPath, p_ProgramComponentSerializationAttributes)
    private:
        void UpdateProjectComponentSerializationAttributes(std::vector<Ref<ProgramComponent>>& programComponents);
        friend class Program;

    };
};