#pragma once

#include "Rendering/Pipeline.h"
#include "Rendering/Debug/GfxDebug.h"
namespace harmony
{
    class DebugDrawStage : public PipelineStage
    {
    public:
        DebugDrawStage(GfxDebug::Channel channel);
        virtual void Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle) override;
        virtual void Cleanup() override;
        virtual Ref<PipelineStage> Clone() override;
        GfxDebug::Channel m_Channel;
        bool Active;
        DebugDrawEncoder* p_DebugRenderer;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(DebugDrawStage, m_Name, p_Shader, m_StageType, m_Channel)
    };
   
    class DebugDrawPipeline : public Pipeline
    {
    public:
        DebugDrawPipeline(GfxDebug::Channel channel);
    };
};
