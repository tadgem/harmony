#pragma once

#include "Rendering/Pipelines/PipelineStage.h"

namespace harmony {

    class PostProcessStage : public PipelineStage {
    public:
        PostProcessStage(const std::string &name, Type stageType,
                         WeakPtr<ShaderProgram> shader,
                         WeakPtr<PipelineStageRenderer> stageRenderer,
                         Vector<AttachmentType> attachments);

        virtual void PreUpdate(entt::registry &registry, WeakPtr<View> view,
                               bgfx::ViewId viewId, RefCntPtr<Framebuffer> data);

        virtual void PostUpdate(entt::registry &registry, WeakPtr<View> view,
                                bgfx::ViewId viewId, RefCntPtr<Framebuffer> data);

        void PreUpdate(entt::registry &registry, WeakPtr<View> view,
                       bgfx::ViewId viewId) override;

        void PostUpdate(entt::registry &registry, WeakPtr<View> view,
                        bgfx::ViewId viewId) override;

        static AttachmentType s_AttachmentType;
    };
} // namespace harmony