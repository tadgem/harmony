#include "Rendering/Shapes.h"
#include "Core/Profile.hpp"
harmony::Cube::Cube(float size) : Mesh("builtin://cube", 0)
{
	HARMONY_PROFILE_FUNCTION()
	float side2 = size / 2.0f;

	std::vector<glm::vec3> positions = {
		// Front
	   glm::vec3(-side2, -side2, side2), glm::vec3(side2, -side2, side2), glm::vec3(side2,  side2, side2),  glm::vec3(-side2,  side2, side2),
	   // Right
		glm::vec3(side2, -side2, side2), glm::vec3(side2, -side2, -side2), glm::vec3(side2,  side2, -side2), glm::vec3(side2,  side2, side2),
		// Back
		glm::vec3(-side2, -side2, -side2), glm::vec3(-side2,  side2, -side2), glm::vec3(side2,  side2, -side2), glm::vec3(side2, -side2, -side2),
		// Left
		glm::vec3(-side2, -side2, side2), glm::vec3(-side2,  side2, side2), glm::vec3(-side2,  side2, -side2), glm::vec3(-side2, -side2, -side2),
		// Bottom
		glm::vec3(-side2, -side2, side2),glm::vec3(-side2, -side2, -side2), glm::vec3(side2, -side2, -side2), glm::vec3(side2, -side2, side2),
		// Top
		glm::vec3(-side2,  side2, side2), glm::vec3(side2,  side2, side2), glm::vec3(side2,  side2, -side2), glm::vec3(-side2,  side2, -side2)
	};

	std::vector<glm::vec3> normals = {
		// Front
		glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),glm::vec3(0.0f, 0.0f, 1.0f),
		// Right
		glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),
		// Back
		glm::vec3(0.0f, 0.0f, -1.0f),glm::vec3(0.0f, 0.0f, -1.0f),glm::vec3(0.0f, 0.0f, -1.0f),glm::vec3(0.0f, 0.0f, -1.0f),
		// Left
		glm::vec3(-1.0f, 0.0f, 0.0f),glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f),glm::vec3(-1.0f, 0.0f, 0.0f),
		// Bottom
		glm::vec3(0.0f, -1.0f, 0.0f),glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f),
		// Top
		glm::vec3(0.0f, 1.0f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f)
	};

	std::vector<glm::vec2> uvs = {
		// Front
		glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 1.0f),
		// Right
		glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 1.0f),
		// Back
		glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 1.0f),
		// Left
		glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 1.0f),
		// Bottom
		glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 1.0f),
		// Top
		glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 1.0f)
	};

	std::vector<unsigned int> indices = {
		0,1,2,0,2,3,
		4,5,6,4,6,7,
		8,9,10,8,10,11,
		12,13,14,12,14,15,
		16,17,18,16,18,19,
		20,21,22,20,22,23
	};


	InitializeMesh(positions, indices, normals, uvs);
}

harmony::Plane::Plane(float size) : Mesh("builtin://plane", 0)
{
	HARMONY_PROFILE_FUNCTION()
	float side2 = size / 2.0f;

	std::vector<glm::vec3> positions = {
		glm::vec3(-side2, -side2, 0.0f), glm::vec3(-side2, side2, 0.0f),
		glm::vec3(side2, side2, 0.0f), glm::vec3(side2, -side2, 0.0f),
	};

	std::vector<glm::vec2> uvs = {
		glm::vec2(0.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 0.0f)
	};


	std::vector<glm::vec3> normals = {
		glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f),
	};

	/*std::vector<glm::vec3> tangents = {
		glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
	};

	std::vector<glm::vec3> bitangents = {
		glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),
		glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),
	};*/

	std::vector<unsigned int> indices = {
		0,1,2,2,3,0
	};
	InitializeMesh(positions, indices, normals, uvs);
}


bgfx::VertexLayout harmony::PosColorTexCoord0Vertex::ms_layout;
void harmony::ScreenSpaceQuad(float _textureWidth, float _textureHeight, bool _originBottomLeft, float _width, float _height)
{
	if (3 == bgfx::getAvailTransientVertexBuffer(3, PosColorTexCoord0Vertex::ms_layout))
	{
		bgfx::TransientVertexBuffer vb;
		bgfx::allocTransientVertexBuffer(&vb, 3, PosColorTexCoord0Vertex::ms_layout);
		PosColorTexCoord0Vertex* vertex = (PosColorTexCoord0Vertex*)vb.data;

		const float zz = 0.0f;

		const float minx = -_width;
		const float maxx = _width;
		const float miny = 0.0f;
		const float maxy = _height * 2.0f;

		const float texelHalfW = s_texelHalf / _textureWidth;
		const float texelHalfH = s_texelHalf / _textureHeight;
		const float minu = -1.0f + texelHalfW;
		const float maxu = 1.0f + texelHalfW;

		float minv = texelHalfH;
		float maxv = 2.0f + texelHalfH;

		if (_originBottomLeft)
		{
			float temp = minv;
			minv = maxv;
			maxv = temp;

			minv -= 1.0f;
			maxv -= 1.0f;
		}

		vertex[0].m_x = minx;
		vertex[0].m_y = miny;
		vertex[0].m_z = zz;
		vertex[0].m_rgba = 0xffffffff;
		vertex[0].m_u = minu;
		vertex[0].m_v = minv;

		vertex[1].m_x = maxx;
		vertex[1].m_y = miny;
		vertex[1].m_z = zz;
		vertex[1].m_rgba = 0xffffffff;
		vertex[1].m_u = maxu;
		vertex[1].m_v = minv;

		vertex[2].m_x = maxx;
		vertex[2].m_y = maxy;
		vertex[2].m_z = zz;
		vertex[2].m_rgba = 0xffffffff;
		vertex[2].m_u = maxu;
		vertex[2].m_v = maxv;

		bgfx::setVertexBuffer(0, &vb);
	}
}
