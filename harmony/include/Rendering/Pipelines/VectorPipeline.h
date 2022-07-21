#pragma once

#include "Rendering/Pipeline.h"
#include "Rendering/VectorGraphics.h"
namespace harmony
{
    class VectorGraphicsStage : public PipelineStage
    {
    public:

        VectorGraphicsStage();

        virtual void Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void Cleanup() override;
        virtual bgfx::FrameBufferHandle GetStageFinalFramebuffer() override;
    };

    class VectorPipeline : public Pipeline
    {
    public:
        VectorPipeline();

        virtual bgfx::TextureHandle GetFinalImage() override;
    };
};