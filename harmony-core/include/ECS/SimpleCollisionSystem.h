#pragma once
#include "ECS/System.h"

namespace harmony
{
	class AssetManager;
	class SimpleCollisionSystem : public System
	{
	public:

		SimpleCollisionSystem(AssetManager& am);

		virtual void Init(entt::registry& registry) override;
		virtual void Update(entt::registry& registry) override;
		virtual void Render(entt::registry& registry) override;
		virtual void Cleanup(entt::registry& registry) override;
		virtual nlohmann::json SerializeSystem(entt::registry& registry) override;
		virtual void DeserializeSystem(entt::registry& registry, nlohmann::json systemJson) override;
		virtual void Refresh() override;

	protected:
		AssetManager& p_AssetManager;
	};
}