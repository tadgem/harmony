#pragma once
#include "glm.hpp"
#include "ThirdParty/json.hpp"
#include "Rendering/ShaderUniform.h"
namespace harmony
{

	struct AABB
	{
		glm::vec3 Min;
		glm::vec3 Max;
	};

	struct Sphere
	{
		glm::vec4 PosR;
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Sphere, PosR)
	};


}