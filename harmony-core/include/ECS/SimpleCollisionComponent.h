#pragma once

#include "Collision/CollisionShapes.h"
#include "Assets/Asset.h"
#include "ThirdParty/json.hpp"
#include "ThirdParty/entt.hpp"
namespace harmony {

	struct AABBColliderComponent
	{
		AABB m_Original;
		AABB m_Frame;
		bool m_Update;

		AssetHandle m_MeshHandle;
		std::vector<entt::entity> m_Colliders;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(AABBColliderComponent, m_MeshHandle)
	};

	struct SphereColliderComponent
	{
		float m_Radius;
		bool m_Update;
		std::vector<entt::entity> m_Colliders;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(SphereColliderComponent, m_Radius)
	};

	struct Hit
	{
		glm::vec3 Position;
		float Distance;
		bool DidHit;
		entt::entity Entity;
	};
}