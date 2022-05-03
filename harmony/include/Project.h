#pragma once
#include "json.hpp"
#include <string>
#include <map>
#include <filesystem>
#include "Assets/AssetManager.h"

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

        void Load(AssetManager& assetManager);
        void Unload(AssetManager& assetManager);

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Project, m_ProjectPath, m_ProjectDirectory)

    };
};