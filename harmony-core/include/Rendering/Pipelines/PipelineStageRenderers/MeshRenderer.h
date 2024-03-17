#pragma once

#include "Rendering/Pipelines/PipelineStageRenderer.h"

namespace harmony {
    class MeshRenderer : public PipelineStageRenderer {
    public:
        MeshRenderer();

        virtual void Draw(entt::registry &scene, RefCntPtr<ShaderProgram> shader, RefCntPtr<View> view,
                          bgfx::ViewId viewId) override;
    };
} // namespace harmony