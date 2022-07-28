#include "Assets/ShaderSourceAssetFactory.h"

harmony::ShaderSourceAssetFactory::ShaderSourceAssetFactory() : AssetFactory()
{
	m_Capabilities.AssetTypeHashes.push_back(GetTypeHash<ShaderSourceAsset>());
}

void harmony::ShaderSourceAssetFactory::LoadAssetData(const std::string& path, entt::registry& registry)
{
	std::string shaderName = path.substr(path.find_last_of("\\") + 1);

	ShaderStage::Type type = ShaderStage::Type::Unknown;

	auto foundVs = shaderName.find("vs");
	auto foundFs = shaderName.find("fs");
	auto foundCs = shaderName.find("cs");
	if (foundVs >= 0 && foundVs < shaderName.size())
	{
		type = ShaderStage::Type::Vertex;
	}
	if (foundFs >= 0 && foundFs < shaderName.size())
	{
		type = ShaderStage::Type::Fragment;
	}
	if (foundCs >= 0 && foundCs < shaderName.size())
	{
		type = ShaderStage::Type::Compute;
	}

	Ref<ShaderSourceAsset> sourceAsset = CreateRef<ShaderSourceAsset>(path, type);

	AssetHandle handle{ path, 0, GetTypeHash<ShaderSourceAsset>() };
	AssetComponent<ShaderSourceAsset> sourceComponent{ sourceAsset, handle };

	entt::entity e = registry.create();
	registry.emplace<AssetComponent<ShaderSourceAsset>>(e, sourceComponent);
	registry.emplace<AssetHandle>(e, handle);
}

void harmony::ShaderSourceAssetFactory::UnloadAssetData(const std::string& path, entt::registry& registry)
{
}

void harmony::ShaderSourceAssetFactory::ClearLoadedData()
{
}
