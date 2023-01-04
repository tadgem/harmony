#pragma once
#include "Rendering/PipelineStage.h"

namespace harmony
{
    class View;
    class PipelineStageRenderer;
    class PipelineDrawStage : public PipelineStage
    {
    public:
        
        PipelineDrawStage(
        const std::string& name,
        Type stageType,
        WeakRef<ShaderProgram> shader,
        WeakRef<PipelineStageRenderer> stageRenderer,
        Attachment::Type attachments = (Attachment::Type)(Attachment::Type::RGBA8F | Attachment::Type::Depth32F));

        virtual Data Init       (entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId);
        virtual void PreUpdate  (entt::registry& registry, WeakRef<View> view , bgfx::ViewId viewId);
        virtual void PostUpdate (entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId);
        virtual void Cleanup    (WeakRef<View> view, bgfx::ViewId viewId);


        bool m_HasHDRAttachment;
        bool m_HasDepthAttachment;

        Type                m_StageType;
        Attachment::Type    m_Attachments;
        std::string         m_Name;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineDrawStage, m_Name, m_StageType, p_Shader, m_Attachments)
    protected:
        friend class Renderer;
        WeakRef<ShaderProgram>              p_Shader;
        WeakRef<PipelineStageRenderer>      p_Renderer;
    };
} 