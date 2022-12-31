#pragma once
#include "Assets/AssetFactory.h"
namespace harmony
{
	class FontAssetFactory : public AssetFactory
	{
	public:
		FontAssetFactory();

		virtual void LoadAssetData(const std::string& path, entt::registry& registry) override;
		virtual void UnloadAssetData(const std::string& path, entt::registry& registry) override;

	protected:
		std::string GetFontNameFromPath(const std::string& path);
	};
}