#pragma once

#include "Collision/CollisionShapes.h"
#include "Assets/Asset.h"
#include "ThirdParty/json.hpp"
namespace harmony {
	struct AABBComponent
	{
		AABB aabb;
		AssetHandle m_MeshHandle;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(AABBComponent, m_MeshHandle)
	};
}