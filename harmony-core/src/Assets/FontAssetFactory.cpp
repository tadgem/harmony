#include <optick.h>
#include "Assets/FontAssetFactory.h"
#include "Assets/FontAsset.h"
#include "Core/Memory.h"
#include "Core/Utils.h"
#include "Rendering/VectorGraphics/VectorGraphics.h"

harmony::FontAssetFactory::FontAssetFactory()
{
	OPTICK_EVENT();
	std::string fontTypeHash = GetTypeHash<FontAsset>();
	m_Capabilities.AssetTypeHashes.push_back(fontTypeHash);
}

void harmony::FontAssetFactory::LoadAssetData(const std::string &path, entt::registry &registry)
{
	OPTICK_EVENT();
	AssetHandle assetHandle(path, 0, GetTypeHash<FontAsset>());
	Ref<FontAsset> font = CreateRef<FontAsset>(assetHandle);
	std::vector<uint8_t> fontData = Utils::LoadBinaryFromPath(path);
	std::string cleanFontName = GetFontNameFromPath(path);
	font->m_CleanName = cleanFontName;
	// make available to vg renderer
	VectorGraphics::AddFont(cleanFontName, fontData);

	AssetComponent<FontAsset> fontComponent{font, assetHandle};
	entt::entity e = registry.create();
	registry.emplace<AssetComponent<FontAsset>>(e, fontComponent);
	registry.emplace<AssetHandle>(e, assetHandle);
}

void harmony::FontAssetFactory::UnloadAssetData(const std::string &path, entt::registry &registry)
{
	OPTICK_EVENT();
	auto view = registry.view<AssetComponent<FontAsset>, AssetHandle>();
	entt::entity e;
	bool found = false;
	for (auto [entity, tex, handle]: view.each())
	{
		if (handle.Path == path)
		{
			found = true;
			e = entity;
		}
	}

	if (found)
	{
		registry.destroy(e);
	}
}

std::string harmony::FontAssetFactory::GetFontNameFromPath(const std::string &path)
{
	OPTICK_EVENT();
	std::string::size_type fsPos = path.find_last_of('/');
	std::string::size_type bsPos = path.find_last_of('\\');
	std::string temp;

	if (fsPos != std::string::npos)
	{
		temp = path.substr(fsPos + 1);
	}
	else if (bsPos != std::string::npos)
	{
		temp = path.substr(bsPos + 1);
	}

	std::string::size_type dotPos = temp.find('.');

	if (dotPos != std::string::npos)
	{
		return temp.substr(0, dotPos);
	}
	else
	{
		return temp;
	}
}
