//
// Created by liam_ on 6/24/2023.
//
#include "Rendering/Pipelines/PipelineStageRenderers/SubDivScreenQuadRenderer.h"
#include "Core/Alias.h"

void harmony::SubDivScreenQuadRenderer::Draw(entt::registry &scene, harmony::Ref<harmony::ShaderProgram> shader,
                                             bgfx::ViewId viewId) {
    DrawMesh(viewId,shader);
}

harmony::SubDivScreenQuadRenderer::SubDivScreenQuadRenderer(uint16_t wcount, uint16_t hcount) : PipelineStageRenderer("SubDivScreenQuad")
{
    CreateMesh(wcount, hcount);
}

void harmony::SubDivScreenQuadRenderer::CreateMesh(uint16_t w, uint16_t h)
{
    bgfx::VertexLayout layout;
    layout
    .begin()
    .add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
    .end();

    glm::vec2* vertices = new glm::vec2[w * h];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            glm::vec2& v = vertices[i * h + j];
            v.x = float(j) / (w - 1) * 2.0f - 1.0f;
            v.y = float(i) / (h - 1) * 2.0f - 1.0f;
        }
    }

    uint16_t* indices =new uint16_t[(h - 1) * (w - 1) * 6];

    int k = 0;
    for (int i = 0; i < h - 1; i++)
    {
        for (int j = 0; j < w - 1; j++)
        {
            indices[k++] = (uint16_t)(j + 0 + w * (i + 0));
            indices[k++] = (uint16_t)(j + 1 + w * (i + 0));
            indices[k++] = (uint16_t)(j + 0 + w * (i + 1));

            indices[k++] = (uint16_t)(j + 1 + w * (i + 0));
            indices[k++] = (uint16_t)(j + 1 + w * (i + 1));
            indices[k++] = (uint16_t)(j + 0 + w * (i + 1));
        }
    }

    p_VBH = bgfx::createVertexBuffer(bgfx::copy(vertices, sizeof(glm::vec2) * h * w), layout);
    p_IBH = bgfx::createIndexBuffer(bgfx::copy(indices, sizeof(uint16_t) * k));

}

void harmony::SubDivScreenQuadRenderer::DrawMesh(bgfx::ViewId viewId, Ref<ShaderProgram> shader)
{
    bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
    bgfx::setIndexBuffer(p_IBH);
    bgfx::setVertexBuffer(0, p_VBH);
    bgfx::submit(viewId, shader->m_Handle);
}
