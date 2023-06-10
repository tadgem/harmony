#pragma once

#include "Rendering/Pipelines/PipelineStage.h"
#include "Rendering/VectorGraphics/VectorGraphics.h"

namespace harmony {
    class VectorGraphicsStage : public PipelineDrawStage {
    public:

        VectorGraphicsStage(VectorGraphics::Layer layer);

        virtual void PreUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) override;

        virtual void PostUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) override;

        virtual void Cleanup(WeakRef<View> view, bgfx::ViewId viewId) override;

        VectorGraphics::Layer m_Layer;

    protected:
        NVGcontext * p_Context;
    };
};