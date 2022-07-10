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


    // TODO: handle this in a more efficient way;
    struct PosColorTexCoord0Vertex
    {
        float m_x;
        float m_y;
        float m_z;
        uint32_t m_rgba;
        float m_u;
        float m_v;

        static void init()
        {
            ms_layout
                .begin()
                .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
                .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
                .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
                .end();
        }

        static bgfx::VertexLayout ms_layout;
    };

    inline static float s_texelHalf = 0.0f;
    void ScreenSpaceQuad(float _textureWidth, float _textureHeight, bool _originBottomLeft = false, float _width = 1.0f, float _height = 1.0f);

};