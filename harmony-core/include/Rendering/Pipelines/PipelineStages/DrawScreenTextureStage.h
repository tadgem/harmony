//
// Created by Admin on 6/4/2023.
//

#ifndef HARMONY_DOJO_DRAWSCREENTEXTURESTAGE_H
#define HARMONY_DOJO_DRAWSCREENTEXTURESTAGE_H
#include "Rendering/Pipelines/PipelineStage.h"

namespace harmony
{
    class DrawScreenTextureStage : public PipelineStage
    {
    public:
        DrawScreenTextureStage(WeakRef<ShaderProgram> shader, AttachmentType type, WeakRef<Framebuffer> fb);

        void PreUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) override;

        void PostUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) override;

        WeakRef<Framebuffer> m_FramebufferToDraw;
    private:
        static String GetName(WeakRef<Framebuffer> fb);

    };
}
#endif //HARMONY_DOJO_DRAWSCREENTEXTURESTAGE_H