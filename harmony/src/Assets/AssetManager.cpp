#include "Assets/AssetManager.h"
#include "Core/Profile.hpp"
#include "Core/Log.hpp"
#include "ImGui/imgui.h"

harmony::AssetManager::AssetManager()
{
}

void harmony::AssetManager::UnloadAllAssets()
{
}

bool harmony::AssetManager::AddAssetFactory(Ref<AssetFactory> assetFactory)
{
	if (std::find(p_AssetFactories.begin(), p_AssetFactories.end(), assetFactory) == p_AssetFactories.end())
	{
		p_AssetFactories.emplace_back(assetFactory);
		return true;
	}
	return false;
}