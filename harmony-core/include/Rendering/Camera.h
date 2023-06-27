#pragma once

#include "Core/Memory.h"
#include "ThirdParty/json.hpp"
#include "glm/glm.hpp"

namespace harmony
{
	class Camera
	{
	public:
		enum ProjectionType
		{
			Orthorgraphic,
			Perspective
		};
		glm::mat4 View;
		glm::mat4 Projection;
		float FOV;
		float NearClipPlane, FarClipPlane;
		float Aspect;
		uint32_t Width = 1280;
		uint32_t Height = 720;
		ProjectionType Type = ProjectionType::Perspective;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Camera, FOV, NearClipPlane, FarClipPlane,
									   Aspect, Type);
	};
}; // namespace harmony