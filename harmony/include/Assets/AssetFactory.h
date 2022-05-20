#pragma once
#include "Core/Memory.h"
#include "Core/Profile.hpp"
#include "Assets/Asset.h"
#include <map>
namespace harmony {
	class AssetFactory
	{
	public:
		AssetFactory(size_t typeHash);

		template<typename T>
		std::unordered_map<size_t, std::vector<Ref<Asset>>> CreateFromFile(const std::string& path)
		{
			HARMONY_PROFILE_FUNCTION()
			static_assert(std::is_base_of<Asset, T>());
			std::map<size_t, std::vector<Asset*>> assets = CreateAssetData(path);
			return assets;
		}

		std::unordered_map<size_t, std::vector<Ref<Asset>>> CreateFromFileUnsafe(const std::string& path)
		{
			HARMONY_PROFILE_FUNCTION()
			return CreateAssetData(path);
		}

	protected:
		virtual std::unordered_map<size_t, std::vector<Ref<Asset>>> CreateAssetData(const std::string& path);
		size_t p_TypeHash;
	};
}
