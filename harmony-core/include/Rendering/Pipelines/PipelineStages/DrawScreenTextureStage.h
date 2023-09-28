//
// Created by Admin on 6/4/2023.
//

#ifndef HARMONY_DOJO_DRAWSCREENTEXTURESTAGE_H
#define HARMONY_DOJO_DRAWSCREENTEXTURESTAGE_H

#include "Rendering/Pipelines/PipelineStage.h"

namespace harmony {
    class DrawScreenTextureStage : public PipelineStage {
    public:
        DrawScreenTextureStage(WeakPtr<ShaderProgram> shader, AttachmentType type,
                               Vector<WeakPtr<Framebuffer>> fbs);

        void PreUpdate(entt::registry &registry, WeakPtr<View> view,
                       bgfx::ViewId viewId) override;

        void PostUpdate(entt::registry &registry, WeakPtr<View> view,
                        bgfx::ViewId viewId) override;

        Vector<WeakPtr<Framebuffer>> m_FramebuffersToDraw;

    private:
        static String GetName(WeakPtr<Framebuffer> fb);
    };
} // namespace harmony
#endif // HARMONY_DOJO_DRAWSCREENTEXTURESTAGE_H
