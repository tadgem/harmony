#include "Assets/AssetFactory.h"

harmony::AssetFactory::AssetFactory(size_t typeHash)
{
}

std::map<size_t, std::vector<harmony::Ref<harmony::Asset>>> harmony::AssetFactory::CreateAssetData(const std::string& path)
{
	return std::map<size_t, std::vector<Ref<Asset>>>();
}
