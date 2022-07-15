#pragma once

#include "Rendering/Pipeline.h"
#include "Rendering/Debug/GfxDebug.h"
namespace harmony
{
    class DebugDrawStage : public PipelineStage
    {
    public:
        DebugDrawStage();
        virtual void Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void Cleanup() override;

        bool Active;
        DebugDrawEncoder* p_DebugRenderer;
    };
    /// <summary>
    /// CURRENT KNOWN LIMITATION:
    /// Cannot have more than one DebugDrawPipeline active at once
    /// ddebug draw needs to be statically available for easy access 
    /// but the bgfx ref impl cannot be reused in more than one using the static instance.
    /// would require each draw call was called again after the initial view was rendered.
    /// </summary>
    class DebugDrawPipeline : public Pipeline
    {
    public:
        DebugDrawPipeline();
    };
};
