#pragma once

#include "Rendering/Pipeline.h"

namespace harmony
{
    class TextureMeshStage : public PipelineStage
    {
        virtual void Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void Cleanup() override;
        virtual bgfx::FrameBufferHandle GetStageFinalFramebuffer() override;
    };

    class TexturedMeshPipeline : public Pipeline
    {

    };
};