#pragma once
#include "glm.hpp"

namespace harmony {
	struct DirectionalLight
	{
		glm::vec4 Diffuse;
		glm::vec4 Ambient;
	};

	struct PointLight
	{
		glm::vec4 Diffuse;
		glm::vec4 Ambient;

		float Radius;
	};

	struct SpotLight : PointLight
	{
		glm::vec4 Diffuse;
		glm::vec4 Ambient;

		float Radius;
		float Angle;
	};
}