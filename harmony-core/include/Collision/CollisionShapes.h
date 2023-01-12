#pragma once
#include "glm.hpp"

namespace harmony
{

	struct AABB
	{
		glm::vec3 Center;
		glm::vec3 Min;
		glm::vec3 Max;
	};


}