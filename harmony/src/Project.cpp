#include "Project.h"
#include <filesystem>
harmony::Project::Project(std::string projectPath, std::string projectDirectory) : m_ProjectPath(projectPath), m_ProjectDirectory(projectDirectory)
{
	
}

void harmony::Project::Load(AssetManager& assetManager)
{
	std::filesystem::current_path(std::filesystem::path(m_ProjectDirectory));
}

void harmony::Project::Unload(AssetManager& assetManager)
{
	assetManager.UnloadAllAssets();
}
