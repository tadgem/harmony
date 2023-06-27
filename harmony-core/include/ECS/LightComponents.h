#pragma once

#include "glm.hpp"
#include "Rendering/Shaders/ShaderUniform.h"

namespace harmony
{
	struct DirectionalLight
	{
		glm::vec4 Diffuse;
		glm::vec4 Ambient;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(DirectionalLight, Diffuse, Ambient);
	};
	struct PointLight
	{
		glm::vec4 Diffuse;
		glm::vec4 Ambient;
		float Radius;
		float Intensity;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(PointLight, Diffuse, Ambient, Radius, Intensity);
	};
	struct SpotLight : PointLight
	{
		glm::vec4 Diffuse;
		glm::vec4 Ambient;
		float Radius;
		float Angle;
		float Intensity;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(SpotLight, Diffuse, Ambient, Radius, Intensity, Angle);
	};
}