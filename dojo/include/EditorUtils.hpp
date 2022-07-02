#include "ImGui/imgui.h"
#include "Core/Program.h"
#include "Assets/AssetManager.h"

void ProjectDetailsImGui(harmony::Program& program)
{
	if (ImGui::Begin("Project"))
	{
		if (program.m_Project != nullptr)
		{
			ImGui::Text("Project Name : ", program.m_Project->m_ProjectName.c_str());
		}
		else
		{
			ImGui::Text("No Project Loaded");
		}
	}
	ImGui::End();
}

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
