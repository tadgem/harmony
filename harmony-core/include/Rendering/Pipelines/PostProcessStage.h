#pragma once

#include "PipelineStage.h"

namespace harmony {
    class PostProcessStage : public PipelineStage {
    public:

        PostProcessStage(
                const std::string &name,
                Type stageType,
                WeakRef<ShaderProgram> shader,
                WeakRef<PipelineStageRenderer> stageRenderer,
                AttachmentType attachments = (AttachmentType) (AttachmentType::RGBA8F));

        virtual void
        PreUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId, PipelineStage::Data data);

        virtual void
        PostUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId, PipelineStage::Data data);

    };
}