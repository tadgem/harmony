#pragma once

#include "Rendering/Pipeline.h"
#include "Rendering/Debug/DebugDraw.h"

namespace harmony
{
    class DebugDrawStage : public PipelineStage
    {
    public:

        DebugDrawStage();

        virtual void Init(entt::registry& registry, WeakRef<View> view) override;
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view) override;
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view) override;
        virtual void Cleanup() override;


    };

    class DebugDrawPipeline : public Pipeline
    {
    public:
        DebugDrawPipeline();


    };
};
