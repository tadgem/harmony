#include "Project.h"

harmony::Project::Project(std::string projectPath, std::string projectDirectory)
{
}

void harmony::Project::Load(AssetManager& assetManager)
{

}

void harmony::Project::Unload(AssetManager& assetManager)
{
	assetManager.UnloadAllAssets();
}
