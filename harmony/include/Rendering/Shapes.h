#pragma once

#include "Rendering/Mesh.h"
#include "glm.hpp"
namespace harmony
{
	class Cube : public Mesh
	{
	public:
		Cube(float size);
	};

	class Plane : public Mesh
	{
	public:
		Plane(float size);
	};
};