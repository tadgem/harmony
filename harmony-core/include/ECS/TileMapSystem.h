#pragma once

#include "ECS/System.h"
#include "Rendering/Renderer.h"
#include "Assets/AssetManager.h"

namespace harmony
{
	class TileMapSystem : public System
	{
	public:
		TileMapSystem(AssetManager &assetManager, Renderer &renderer);
		virtual void Init(entt::registry &registry) override;
		virtual void Update(entt::registry &registry) override;
		virtual void Render(entt::registry &registry) override;
		virtual void Cleanup(entt::registry &registry) override;
		virtual nlohmann::json SerializeSystem(entt::registry &registry) override;
		virtual void DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) override;
		virtual void Refresh() override;

	private:
		AssetManager &p_AssetManager;
		Renderer &p_Renderer;
		friend class TileMapSystemImGui;
	};
};