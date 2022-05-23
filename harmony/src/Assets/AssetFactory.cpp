#include "Assets/AssetFactory.h"

harmony::AssetFactory::AssetFactory(size_t typeHash)
{
	HARMONY_PROFILE_FUNCTION()
}

std::unordered_map<size_t, std::vector<harmony::Ref<harmony::Asset>>> harmony::AssetFactory::CreateAssetData(const std::string& path)
{
	HARMONY_PROFILE_FUNCTION()
	return std::unordered_map<size_t, std::vector<Ref<Asset>>>();
}
