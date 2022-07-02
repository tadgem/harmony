#pragma once

#include "ImGui/imgui.h"
#include "Core/Program.h"
#include "Assets/AssetManager.h"

void ProjectDetailsImGui(harmony::Program& program);

template<typename T>
bool AssetTypeSelector(const std::string& selectorName, harmony::AssetManager& am, harmony::AssetHandle& handle)
{
	static_assert(std::is_base_of<harmony::Asset, T>());
	bool selectedAsset = false;
	std::vector<harmony::AssetHandle> assets = am.GetLoadedAssets<T>();
	if (ImGui::BeginCombo(selectorName.c_str(), ""))
	{
		for (int i = 0; i < assets.size(); i++)
		{
			if(ImGui::Selectable(assets[i].Path.c_str()))
			{
				handle = assets[i];
				selectedAsset = true;
			}
		}
		ImGui::EndCombo();
	}

	return selectedAsset;
}
