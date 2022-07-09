#pragma once

#include "Rendering/Pipeline.h"
namespace harmony
{
    class NormalStage : public PipelineStage
    {
    public:

        NormalStage();

        virtual void Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void Cleanup() override;
    };

    class NormalPipeline : public Pipeline
    {
    public:
        NormalPipeline();
    };
};