#pragma once
#include "ECS/System.h"
#include "ECS/SimpleCollisionComponent.h"
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

		std::vector<Hit> Raycast(Ray ray, entt::registry& registry);

	protected:
		AssetManager& p_AssetManager;

		void UpdateColliders(entt::registry& registry);

#if HARMONY_DEBUG
		void DrawAABB(AABB& aabb, uint32_t color);
		void DrawSphere(glm::vec3 position,float radius, uint32_t color);
#endif
	};
}