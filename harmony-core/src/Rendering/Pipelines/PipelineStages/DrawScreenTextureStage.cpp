#include "Rendering/Pipelines/PipelineStages/DrawScreenTextureStage.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/View.h"
#include "Rendering/Shapes.h"

void harmony::DrawScreenTextureStage::PreUpdate(entt::registry &registry, harmony::WeakRef<harmony::View> view,
                                                bgfx::ViewId viewId) {
    auto v = view.lock();
    bgfx::setViewTransform(viewId, NULL, NULL);
    bgfx::setViewRect(viewId, 0, 0, v->m_Width, v->m_Height);

    Ref<ShaderProgram> pipelineShader = p_Shader.lock();
    for (WeakRef<ShaderDataSource> &source: p_DataSources) {
        if (source.expired()) continue;
        auto src = source.lock();
        src->OnPreUpdate(registry, pipelineShader);
    }
    if (m_FramebuffersToDraw.empty()) {
        harmony::log::error("DrawScreenTextureStage : PreUpdate : cannot draw framebuffer, no framebuffers passed.");
        return;
    }
    float fbWidth = 0;
    float fbHeight = 0;
    for (int i = 0; i < m_FramebuffersToDraw.size(); i++) {
        if (pipelineShader->m_Uniforms.size() == i) {
            harmony::log::error(
                    "DrawScreenTextureStage : PreUpdate : Shader does not have uniform for framebuffer at sampler index {}.",
                    i);
            return;
        }
        if (i == 0 && m_FramebuffersToDraw[i].expired()) {
            harmony::log::error(
                    "DrawScreenTextureStage : PreUpdate : cannot draw framebuffer, colour buffer is expired.");
            return;
        }
        auto fb = m_FramebuffersToDraw[i].lock();
        bgfx::setTexture(i, pipelineShader->m_Uniforms[i].BgfxHandle, fb->m_Attachments[0].m_Handle);
        fbWidth = fb->m_FramebufferResolution.Width;
        fbHeight = fb->m_FramebufferResolution.Height;
    }

    ScreenSpaceQuad(fbWidth, fbHeight, v->m_Width, v->m_Height);
    bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
    bgfx::submit(viewId, pipelineShader->m_Handle);
}

void harmony::DrawScreenTextureStage::PostUpdate(entt::registry &registry, harmony::WeakRef<harmony::View> view,
                                                 bgfx::ViewId viewId) {
    Ref<ShaderProgram> pipelineShader = p_Shader.lock();
    for (WeakRef<ShaderDataSource> &source: p_DataSources) {
        if (source.expired()) continue;
        auto src = source.lock();
        src->OnPostUpdate(registry, pipelineShader);
    }

}

harmony::DrawScreenTextureStage::DrawScreenTextureStage(WeakRef<ShaderProgram> shader, AttachmentType type,
                                                        Vector<WeakRef<Framebuffer>> fbs) : PipelineStage(
        GetName(fbs[0]), PipelineStage::Type::PrimaryDraw, {type}, shader, WeakRef<PipelineStageRenderer>()) {
    m_FramebuffersToDraw = fbs;
}

harmony::String harmony::DrawScreenTextureStage::GetName(WeakRef<Framebuffer> fb) {
    String name = "DrawScreenTextureStage_";
    if (fb.expired()) {
        return name;
    }
    auto _fb = fb.lock();
    name += _fb->m_Name;

    return name;
}
