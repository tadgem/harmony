#pragma once
#include "entt.hpp"
#include "Core/Memory.h"
#include "Core/Profile.hpp"
#include "Assets/Asset.h"
#include <map>
namespace harmony {

	struct AssetFactoryCapabilities
	{
		std::vector<size_t> AssetTypeHashes;

		bool Contains(size_t typeHash)
		{
			bool found = false;
			for (int i = 0; i < AssetTypeHashes.size(); i++)
			{
				if (typeHash == AssetTypeHashes[i])
				{
					found = true;
				}
			}
			return found;
		}
	};

	class AssetFactory
	{
	public:
		AssetFactory() {}
		virtual void LoadAssetData(const std::string& path, entt::registry& registry) = 0;
		virtual void UnloadAssetData(const std::string& path, entt::registry& registry) = 0;
		virtual void ClearLoadedData();

		AssetFactoryCapabilities m_Capabilities;
	protected:
		std::vector<Ref<Asset>> p_Assets;
	};
}
