#pragma once

#include "STL/Map.h"
#include "Rendering/Debug/GfxDebug.h"
#include "Rendering/Pipelines/PipelineStages/PipelineDrawStage.h"

namespace harmony {
    class Framebuffer;

    class DebugDrawStage : public PipelineDrawStage {
    public:
        DebugDrawStage(GfxDebug::Channel channel);

        virtual void PreUpdate(entt::registry &registry, WeakPtr<View> view,
                               bgfx::ViewId viewId) override;

        virtual void PostUpdate(entt::registry &registry, WeakPtr<View> view,
                                bgfx::ViewId viewId) override;

        virtual void Cleanup(WeakPtr<View> view, bgfx::ViewId viewId) override;

        GfxDebug::Channel m_Channel;
        bool Active;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(DebugDrawStage, m_Name, p_Shader, m_StageType,
                                       m_Channel)

    protected:
        Map<String, DebugDrawEncoder *> p_DebugRenderers;
    };
}; // namespace harmony
