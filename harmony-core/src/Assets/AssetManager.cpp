#include "Assets/AssetManager.h"
#include "Core/Profile.hpp"
#include "Core/Log.hpp"
#if HARMONY_DEBUG
#include "ImGui/imgui.h"
#include "ImGui/imgui_bgfx.h"
#include "Core/Program.h"
#include "Rendering/Texture.h"
#endif
harmony::AssetManager::AssetManager()
{
}

void harmony::AssetManager::UnloadAllAssets()
{
}
#if HARMONY_DEBUG
void harmony::AssetManager::OnImGui()
{
	
}
#endif

bool harmony::AssetManager::IsPathLoaded(const std::string path)
{
	auto it = std::find(p_LoadedPaths.begin(), p_LoadedPaths.end(), path);
	if (it != p_LoadedPaths.end())
	{
		return true;
	}

	return false;
}
std::vector<harmony::AssetHandle> harmony::AssetManager::LoadAsset(const std::string& path, std::string typeHash)
{
	std::string cleanPath = path;
	auto project = Program::Get()->m_Project;
	if (project)
	{
		std::string projectDir = project->m_ProjectDirectory;
		size_t pos = cleanPath.find(projectDir);
		if (pos != std::string::npos)
		{
			cleanPath.erase(pos, projectDir.length() + 1);
		}
	}

	auto builtin = cleanPath.find("builtin");
	if (builtin >= 0 && builtin < cleanPath.size())
	{
		return GetAssetsAtPath(cleanPath);
	}
	Ref<AssetFactory> factory = GetAssetFactory(typeHash);
	factory->LoadAssetData(cleanPath, p_AssetRegistry);
	p_LoadedPaths.emplace_back(cleanPath);

	return GetAssetsAtPath(cleanPath);
}

void harmony::AssetManager::UnloadAsset(AssetHandle& handle, std::string typeHash)
{
	auto builtin = handle.Path.find("builtin");
	if (builtin >= 0 && builtin < handle.Path.size())
	{
		return;
	}

	Ref<AssetFactory> factory = GetAssetFactory(typeHash);
	factory->UnloadAssetData(handle.Path, p_AssetRegistry);
}

std::vector<harmony::AssetHandle> harmony::AssetManager::GetAssetsAtPath(const std::string& path)
{
	auto handles = std::vector<AssetHandle>();
	auto view = p_AssetRegistry.view<AssetHandle>();

	for (auto [e, handle] : view.each())
	{
		if (handle.Path != path)
		{
			continue;
		}
		handles.emplace_back(handle);
	}
	return handles;
}

void harmony::AssetManager::Clear()
{
	p_LoadedPaths.clear();
	p_AssetRegistry.clear();
}

nlohmann::json harmony::AssetManager::Serialize()
{
	nlohmann::json json;
	auto view = p_AssetRegistry.view<AssetHandle>();


	json["assets"] = nlohmann::json::array();

	for (auto [entity, handle] : view.each())
	{
		json["assets"].emplace_back(handle);
	}

	return json;
}

void harmony::AssetManager::Deserialize(nlohmann::json& json)
{
	for (auto j : json["assets"])
	{
		AssetHandle handle = j;

		if (IsPathLoaded(handle.Path))
		{
			continue;
		}

		LoadAsset(handle.Path, handle.TypeHash);
	}
}

harmony::Ref<harmony::AssetFactory> harmony::AssetManager::GetAssetFactory(std::string typeHash)
{
	Ref<AssetFactory> factory = nullptr;
	for (int i = 0; i < p_AssetFactories.size(); i++)
	{
		if (!p_AssetFactories[i]->m_Capabilities.Contains(typeHash))
		{
			continue;
		}

		int currentCapabilities = 0;

		if (factory != nullptr)
		{
			currentCapabilities = factory->m_Capabilities.AssetTypeHashes.size();
		}

		int newCapabilities = p_AssetFactories[i]->m_Capabilities.AssetTypeHashes.size();

		if (newCapabilities > currentCapabilities)
		{
			factory = p_AssetFactories[i];
		}
	}
	return factory;
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