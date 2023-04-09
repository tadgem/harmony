#pragma once

#include "Pipeline.h"
#include "Rendering/VectorGraphics.h"
namespace harmony
{
    class VectorGraphicsStage : public PipelineDrawStage
    {
    public:

        VectorGraphicsStage(VectorGraphics::Layer layer);

        virtual PipelineDrawStage::Data Init(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId) override;
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId) override;
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId) override;
        virtual void Cleanup(WeakRef<View> view, bgfx::ViewId viewId) override;

        VectorGraphics::Layer m_Layer;

    protected:
        std::map<std::string, NVGcontext*> p_VectorRenderers;
    };

    class VectorPipeline : public Pipeline
    {
    public:
        VectorPipeline(VectorGraphics::Layer layer);
    };
};