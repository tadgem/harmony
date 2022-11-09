#pragma once

#include "Rendering/Pipeline.h"
#include "Rendering/VectorGraphics.h"
namespace harmony
{
    class VectorGraphicsStage : public PipelineStage
    {
    public:

        VectorGraphicsStage();

        virtual PipelineStage::Data Init(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId) override;
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId) override;
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId) override;
        virtual void Cleanup(WeakRef<View> view, bgfx::ViewId viewId) override;

    private:
        inline static uint32_t s_InstanceCounter = 0;
    };

    class VectorPipeline : public Pipeline
    {
    public:
        VectorPipeline();
    };
};