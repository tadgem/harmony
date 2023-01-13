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
		
		std::vector<entt::entity> m_Colliders;

		AssetHandle m_MeshHandle;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(AABBColliderComponent, m_MeshHandle)
	};

	struct SphereColliderComponent
	{
		float m_Radius;

		std::vector<entt::entity> m_Colliders;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(SphereColliderComponent, m_Radius)
	};
}