#pragma once
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
		virtual std::vector<Ref<Asset>> LoadAssetData(const std::string& path) = 0;
		virtual void ClearLoadedData();

		AssetFactoryCapabilities m_Capabilities;
	protected:
		std::vector<Ref<Asset>> p_Assets;
	};
}
