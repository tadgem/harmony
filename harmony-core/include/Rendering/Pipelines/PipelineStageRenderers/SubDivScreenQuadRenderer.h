//
// Created by liam_ on 6/24/2023.
//

#ifndef HARMONY_DOJO_SUBDIVSCREENQUADRENDERER_H
#define HARMONY_DOJO_SUBDIVSCREENQUADRENDERER_H
#include "Rendering/Pipelines/PipelineStageRenderer.h"
namespace harmony
{
    class SubDivScreenQuadRenderer : public PipelineStageRenderer
    {
    public:
        SubDivScreenQuadRenderer(uint16_t wcount, uint16_t hcount);

        void Draw(entt::registry &scene, Ref<ShaderProgram> shader, bgfx::ViewId viewId) override;

    protected:
        bgfx::VertexBufferHandle p_VBH;
        bgfx::IndexBufferHandle p_IBH;
        void CreateMesh(uint16_t w, uint16_t h);
        void DrawMesh(bgfx::ViewId viewId, Ref<ShaderProgram> shader);

    };
}

#endif //HARMONY_DOJO_SUBDIVSCREENQUADRENDERER_H
