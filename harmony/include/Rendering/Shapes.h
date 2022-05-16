#pragma once

#include "Rendering/Mesh.h"

namespace harmony
{
	class Cube : public Mesh
	{
		static constexpr int m_CubeIndices [] =
		{
			0, 2, 1, //face front
			0, 3, 2,
			2, 3, 4, //face top
			2, 4, 5,
			1, 2, 5, //face right
			1, 5, 6,
			0, 7, 4, //face left
			0, 4, 3,
			5, 4, 7, //face back
			5, 7, 6,
			0, 6, 7, //face bottom
			0, 1, 6
		};
	};
};