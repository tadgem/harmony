#pragma once

#include "Rendering/Pipelines/PipelineStage.h"

namespace harmony {

    class PipelineDrawStage : public PipelineStage {
    public:

        PipelineDrawStage(
                const std::string &name,
                Type stageType,
                WeakRef<ShaderProgram> shader,
                WeakRef<PipelineStageRenderer> stageRenderer,
                Vector<AttachmentType> attachments = {AttachmentType::RGBA8, AttachmentType::Depth32F});

        void PreUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) override;

        void PostUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) override;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineDrawStage, m_Name, m_StageType, p_Shader, m_Attachments)

    protected:
        friend class Renderer;
    };
} 