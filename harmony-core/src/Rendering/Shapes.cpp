#include <optick.h>
#include "Rendering/Shapes.h"

harmony::Cube::Cube(float size) : Mesh("builtin://cube", 0) {
    OPTICK_EVENT();
    float side2 = size / 2.0f;
    std::vector<glm::vec3> positions = {
            // Front
            glm::vec3(-side2, -side2, side2), glm::vec3(side2, -side2, side2), glm::vec3(side2, side2, side2),
            glm::vec3(-side2, side2, side2),
            // Right
            glm::vec3(side2, -side2, side2), glm::vec3(side2, -side2, -side2), glm::vec3(side2, side2, -side2),
            glm::vec3(side2, side2, side2),
            // Back
            glm::vec3(-side2, -side2, -side2), glm::vec3(-side2, side2, -side2), glm::vec3(side2, side2, -side2),
            glm::vec3(side2, -side2, -side2),
            // Left
            glm::vec3(-side2, -side2, side2), glm::vec3(-side2, side2, side2), glm::vec3(-side2, side2, -side2),
            glm::vec3(-side2, -side2, -side2),
            // Bottom
            glm::vec3(-side2, -side2, side2), glm::vec3(-side2, -side2, -side2), glm::vec3(side2, -side2, -side2),
            glm::vec3(side2, -side2, side2),
            // Top
            glm::vec3(-side2, side2, side2), glm::vec3(side2, side2, side2), glm::vec3(side2, side2, -side2),
            glm::vec3(-side2, side2, -side2)
    };
    std::vector<glm::vec3> normals = {
            // Front
            glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),
            glm::vec3(0.0f, 0.0f, 1.0f),
            // Right
            glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),
            // Back
            glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f),
            glm::vec3(0.0f, 0.0f, -1.0f),
            // Left
            glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f),
            glm::vec3(-1.0f, 0.0f, 0.0f),
            // Bottom
            glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f),
            glm::vec3(0.0f, -1.0f, 0.0f),
            // Top
            glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f)
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
            0, 1, 2, 0, 2, 3,
            4, 5, 6, 4, 6, 7,
            8, 9, 10, 8, 10, 11,
            12, 13, 14, 12, 14, 15,
            16, 17, 18, 16, 18, 19,
            20, 21, 22, 20, 22, 23
    };

    InitializeMesh(positions, indices, normals, uvs);
}

harmony::Plane::Plane(float size) : Mesh("builtin://plane", 0) {
    OPTICK_EVENT();
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
            0, 1, 2, 2, 3, 0
    };
    InitializeMesh(positions, indices, normals, uvs);
}

bgfx::VertexLayout harmony::PosColorTexCoord0Vertex::ms_layout;

void harmony::ScreenSpaceQuad(float _textureWidth, float _textureHeight, float _width, float _height) {
    OPTICK_EVENT();
//    ImVec2 texUvs {(float)m_Width / (float)GPUResourceManager::GetMaxFramebufferWidth(),
//                   (float)m_Height / (float)GPUResourceManager::GetMaxFramebufferHeight()};
    float desiredWidth = _width / _textureWidth;
    float desiredHeight = _height / _textureHeight;

    if (6 == bgfx::getAvailTransientVertexBuffer(6, PosColorTexCoord0Vertex::ms_layout)) {
        bgfx::TransientVertexBuffer vb;
        bgfx::allocTransientVertexBuffer(&vb, 6, PosColorTexCoord0Vertex::ms_layout);
        PosColorTexCoord0Vertex *vertex = (PosColorTexCoord0Vertex *) vb.data;

        // bottom left
        vertex[0].m_x = -1.0;
        vertex[0].m_y = -1.0;
        vertex[0].m_z = 0.0;
        vertex[0].m_u = 0.0;
        vertex[0].m_v = desiredHeight;
        // bottom right
        vertex[1].m_x = 1.0;
        vertex[1].m_y = -1.0;
        vertex[1].m_z = 0.0;
        vertex[1].m_u = desiredWidth;
        vertex[1].m_v = desiredHeight;

        // top right
        vertex[2].m_x = 1.0;
        vertex[2].m_y = 1.0;
        vertex[2].m_z = 0.0;
        vertex[2].m_u = desiredWidth;
        vertex[2].m_v = 0.0;

        // top right
        vertex[3].m_x = 1.0;
        vertex[3].m_y = 1.0;
        vertex[3].m_z = 0.0;
        vertex[3].m_u = desiredWidth;
        vertex[3].m_v = 0.0;

        // top left
        vertex[4].m_x = -1.0;
        vertex[4].m_y = 1.0;
        vertex[4].m_z = 0.0;
        vertex[4].m_u = 0.0;
        vertex[4].m_v = 0.0;

        // bottom left
        vertex[5].m_x = -1.0;
        vertex[5].m_y = -1.0;
        vertex[5].m_z = 0.0;
        vertex[5].m_u = 0.0;
        vertex[5].m_v = desiredHeight;

        bgfx::setVertexBuffer(0, &vb);
    }
}
