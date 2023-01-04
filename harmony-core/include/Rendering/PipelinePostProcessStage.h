#pragma once
#include "Rendering/PipelineStage.h"

namespace harmony
{
    class PipelinePostProcessStage : public PipelineStage
    {
    public:

        PipelinePostProcessStage(
            const std::string& name,
            Type stageType,
            WeakRef<ShaderProgram> shader,
            WeakRef<PipelineStageRenderer> stageRenderer,
            Attachment::Type attachments = (Attachment::Type)(Attachment::Type::RGBA8F));

        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId, PipelineStage::Data data);
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId, PipelineStage::Data data);

    };
}