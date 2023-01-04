#pragma once
#include "Rendering/Pipeline.h"
#include "Rendering/PipelineDrawStage.h"
#include "Rendering/Debug/GfxDebug.h"
namespace harmony
{
    class DebugDrawStage : public PipelineDrawStage
    {
    public:
        DebugDrawStage(GfxDebug::Channel channel);
        virtual PipelineDrawStage::Data Init(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId) override;
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId) override;
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId) override;
        virtual void Cleanup(WeakRef<View> view, bgfx::ViewId viewId) override;

        GfxDebug::Channel m_Channel;
        bool Active;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(DebugDrawStage, m_Name, p_Shader, m_StageType, m_Channel)
    protected:
        std::map<std::string,DebugDrawEncoder*> p_DebugRenderers;

    };
   
    class DebugDrawPipeline : public Pipeline
    {
    public:
        DebugDrawPipeline(GfxDebug::Channel channel);
    };
};
