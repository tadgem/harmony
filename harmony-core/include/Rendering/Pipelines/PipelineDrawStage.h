#pragma once
#include "PipelineStage.h"

namespace harmony
{

    class PipelineDrawStage : public PipelineStage
    {
    public:
        
        PipelineDrawStage(
        const std::string& name,
        Type stageType,
        WeakRef<ShaderProgram> shader,
        WeakRef<PipelineStageRenderer> stageRenderer,
        Attachment::Type attachments = (Attachment::Type)(Attachment::Type::RGBA8F | Attachment::Type::Depth32F));

        virtual void PreUpdate  (entt::registry& registry, WeakRef<View> view , bgfx::ViewId viewId);
        virtual void PostUpdate (entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId);

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineDrawStage, m_Name, m_StageType, p_Shader, m_Attachments)
    protected:
        friend class Renderer;
    };
} 