#include "Assets/AssetManager.h"
#include "Core/Profile.hpp"
#include "Core/Log.hpp"
#if HARMONY_DEBUG
#include "ImGui/imgui.h"
#include "ImGui/imgui_bgfx.h"
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
	if (ImGui::Begin("Assets"))
	{
		for (auto const& [typeHash, assets] : p_Assets)
		{
			ImGui::Text(p_AssetTypeNames[typeHash].c_str());
			ImGui::Separator();
			for (int i = 0; i < assets.size(); i++)
			{
				Ref<Asset> asset = assets[i];
				ImGui::Text(asset->m_AssetPath.c_str());
				if (typeHash == GetTypeHash<Texture>())
				{
					Ref<Texture> tex = GetDerivedRef<Asset, Texture>(asset);
					if (tex)
					{
						ImVec2 size = ImVec2(tex->m_Handle.m_Info.width, tex->m_Handle.m_Info.height);
						ImGui::Image(tex->m_Handle.m_Handle, size);
					}
				}
			}
			ImGui::Separator();
		}
	}
	ImGui::End();
}
#endif

bool harmony::AssetManager::AddAssetFactory(Ref<AssetFactory> assetFactory)
{
	if (std::find(p_AssetFactories.begin(), p_AssetFactories.end(), assetFactory) == p_AssetFactories.end())
	{
		p_AssetFactories.emplace_back(assetFactory);
		return true;
	}
	return false;
}