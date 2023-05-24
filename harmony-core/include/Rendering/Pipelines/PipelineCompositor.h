//
// Created by liam_ on 5/24/2023.
//

#ifndef HARMONY_DOJO_PIPELINECOMPOSITOR_H
#define HARMONY_DOJO_PIPELINECOMPOSITOR_H

#include <map>
#include <vector>
#include "Pipeline.h"

namespace harmony
{
    class View;

    class PostProcessStage;

    class PipelineCompositor
    {
    public:

        void PreUpdate(entt::registry &registry, WeakRef<View> view);

        void PostUpdate(entt::registry &registry, WeakRef<View> view);

        std::vector<WeakRef<PipelineStage>> m_PipelineStages;

        bgfx::ViewId m_FinalImageViewId;
        bgfx::FrameBufferHandle m_FinalFramebufferHandle;
        bgfx::TextureHandle m_FinalFramebufferAttachment;

    };
}
#endif //HARMONY_DOJO_PIPELINECOMPOSITOR_H
