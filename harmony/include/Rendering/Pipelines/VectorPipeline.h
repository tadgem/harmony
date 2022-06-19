#pragma once

#include "Rendering/Pipeline.h"
#include "vg/helpers/vgpp.h"
namespace harmony
{
    class VectorGraphicsStage : public PipelineStage
    {
    public:

        VectorGraphicsStage();

        virtual void Init(entt::registry& registry) override;
        virtual void Render(entt::registry& registry) override;
        virtual void Cleanup() override;
        virtual bgfx::FrameBufferHandle GetStageFinalFramebuffer() override;
    };

    class VectorPipeline : public Pipeline
    {

    };
};