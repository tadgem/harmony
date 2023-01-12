#pragma once
#include "Collision/CollisionShapes.h"

namespace harmony
{
	class Collision
	{
	public:

		static void UpdateAABB(AABB& aabb, glm::mat3 matrix, glm::vec3 position);
	};
}