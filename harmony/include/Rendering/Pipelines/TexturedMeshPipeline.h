#pragma once

#include "Rendering/Pipeline.h"

namespace harmony
{
    class TextureMeshStage : public PipelineStage
    {
        virtual void Init(entt::registry& registry) override;
        virtual void Render(entt::registry& registry) override;
        virtual void Cleanup() override;
        virtual bgfx::FrameBufferHandle GetStageFinalFramebuffer() override;
    };

    class TexturedMeshPipeline : public Pipeline
    {

    };
};