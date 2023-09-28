//
// Created by liam_ on 7/6/2023.
//

#ifndef HARMONY_DOJO_SCREENQUADRENDERER_H
#define HARMONY_DOJO_SCREENQUADRENDERER_H

#include "Rendering/Pipelines/PipelineStageRenderer.h"

namespace harmony {
    class ScreenQuadRenderer : public PipelineStageRenderer {
    public:
        ScreenQuadRenderer();

        void Draw(entt::registry &scene, RefCntPtr<ShaderProgram> shader, RefCntPtr<View> view, bgfx::ViewId viewId) override;

    };
}

#endif //HARMONY_DOJO_SCREENQUADRENDERER_H
