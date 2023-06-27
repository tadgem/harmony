#pragma once

#include "Rendering/View.h"
#include "Rendering/Camera.h"

namespace harmony
{
	struct CameraComponent
	{
		Camera Cam;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(CameraComponent, Cam);
	};
};