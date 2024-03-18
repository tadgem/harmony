#pragma once

#include "Rendering/Pipelines/PipelineStage.h"

namespace harmony {

    class PipelineDrawStage : public PipelineStage {
    public:
        PipelineDrawStage(const String &name, Type stageType,
                          WeakPtr<ShaderProgram> shader,
                          WeakPtr<PipelineStageRenderer> stageRenderer,
                          Vector<AttachmentType> attachments = {
                                  AttachmentType::RGBA8, AttachmentType::Depth32F});

        void PreUpdate(entt::registry &registry, WeakPtr<View> view,
                       bgfx::ViewId viewId) override;

        void PostUpdate(entt::registry &registry, WeakPtr<View> view,
                        bgfx::ViewId viewId) override;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineDrawStage, m_Name, m_StageType,
                                       p_Shader, m_Attachments)

    protected:
        friend class Renderer;
    };
} // namespace harmony