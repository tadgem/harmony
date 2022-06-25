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
	/*if (ImGui::Begin("Assets"))
	{
		for (auto const& [typeHash, assets] : p_Assets)
		{
			ImGui::Text(p_AssetTypeNames[typeHash].c_str());
			ImGui::Separator();
			for (int i = 0; i < assets.size(); i++)
			{
				Ref<Asset> asset = assets[i];
				ImGui::Text(asset->m_Handle.Path.c_str());
				if (typeHash == GetTypeHash<Texture>())
				{
					Ref<Texture> tex = GetDerivedRef<Asset, Texture>(asset);
					if (tex)
					{
						ImVec2 size = ImVec2(tex->m_TextureHandle.Info.width, tex->m_TextureHandle.Info.height);
						ImGui::Image(tex->m_TextureHandle.Handle, size);
					}
				}
			}
			ImGui::Separator();
		}
	}
	ImGui::End();*/
}
#endif

harmony::Ref<harmony::AssetFactory> harmony::AssetManager::GetAssetFactory(size_t typeHash)
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