#pragma once
#include "Rendering/Pipeline.h"
#include "Rendering/PipelineStage.h"
#include "Rendering/Debug/GfxDebug.h"
namespace harmony
{
    class DebugDrawStage : public PipelineStage
    {
    public:
        DebugDrawStage(GfxDebug::Channel channel);
        virtual PipelineStage::Data Init(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId) override;
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId) override;
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId) override;
        virtual void Cleanup() override;

        GfxDebug::Channel m_Channel;
        bool Active;
        std::map<std::string,DebugDrawEncoder*> p_DebugRenderers;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(DebugDrawStage, m_Name, p_Shader, m_StageType, m_Channel)
    };
   
    class DebugDrawPipeline : public Pipeline
    {
    public:
        DebugDrawPipeline(GfxDebug::Channel channel);
    };
};
