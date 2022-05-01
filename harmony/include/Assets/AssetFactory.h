#pragma once
#include "Core/Memory.h"
#include "Assets/Asset.h"
#include <map>
namespace harmony {
	class AssetFactory
	{
	public:
		AssetFactory(size_t typeHash);

		template<typename T>
		std::map<size_t, std::vector<Ref<Asset>>> CreateFromFile(const std::string& path)
		{
			static_assert(std::is_base_of<Asset, T>());
			std::map<size_t, std::vector<Asset*>> assets = CreateAssetData(path);
			return assets;
		}

	protected:
		virtual std::map<size_t, std::vector<Ref<Asset>>> CreateAssetData(const std::string& path);
		size_t p_TypeHash;
	};
}
