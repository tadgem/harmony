#pragma once

#include "Rendering/Pipelines/PipelineStage.h"

namespace harmony {

    class PostProcessStage : public PipelineStage {
    public:
        PostProcessStage(const std::string &name, Type stageType,
                         WeakRef<ShaderProgram> shader,
                         WeakRef<PipelineStageRenderer> stageRenderer,
                         Vector<AttachmentType> attachments);

        virtual void PreUpdate(entt::registry &registry, WeakRef<View> view,
                               bgfx::ViewId viewId, Ref<Framebuffer> data);

        virtual void PostUpdate(entt::registry &registry, WeakRef<View> view,
                                bgfx::ViewId viewId, Ref<Framebuffer> data);

        void PreUpdate(entt::registry &registry, WeakRef<View> view,
                       bgfx::ViewId viewId) override;

        void PostUpdate(entt::registry &registry, WeakRef<View> view,
                        bgfx::ViewId viewId) override;

        static AttachmentType s_AttachmentType;
    };
} // namespace harmony