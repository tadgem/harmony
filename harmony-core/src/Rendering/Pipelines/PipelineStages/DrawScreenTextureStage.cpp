#include "Rendering/Pipelines/PipelineStages/DrawScreenTextureStage.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/View.h"
#include "Rendering/Shapes.h"

void harmony::DrawScreenTextureStage::PreUpdate(entt::registry &registry, harmony::WeakRef<harmony::View> view,
                                                bgfx::ViewId viewId) {
    bgfx::setViewClear(viewId, BGFX_CLEAR_COLOR, 0x00000000);

    if(m_FramebufferToDraw.expired())
    {
        harmony::log::error("DrawScreenTextureStage : PreUpdate : cannot draw framebuffer, it is expired");
        return;
    }
    auto fb = m_FramebufferToDraw.lock();

    Ref<View> _view = view.lock();
    bgfx::setViewTransform(viewId, &_view->m_View[0], &_view->m_Projection[0]);
    bgfx::setViewRect(viewId, 0, 0, _view->m_Width, _view->m_Height);

    Ref<ShaderProgram> pipelineShader = p_Shader.lock();
    for (WeakRef<ShaderDataSource> &source: p_DataSources) {
        if (source.expired()) continue;
        auto src = source.lock();
        src->OnPreUpdate(registry, pipelineShader);
    }

    bgfx::setTexture(0, pipelineShader->m_Uniforms[0].BgfxHandle, fb->m_Attachments[0].m_Handle);
    ScreenSpaceQuad(static_cast<float>(_view->m_Width), static_cast<float>(_view->m_Height));
    bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A | BGFX_STATE_BLEND_NORMAL);
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

harmony::DrawScreenTextureStage::DrawScreenTextureStage(WeakRef<ShaderProgram> shader, AttachmentType type, harmony::WeakRef<harmony::Framebuffer> fb) : PipelineStage(GetName(fb), PipelineStage::Type::PrimaryDraw, {type}, shader , WeakRef<PipelineStageRenderer>())
{
    m_FramebufferToDraw = fb;
}

harmony::String harmony::DrawScreenTextureStage::GetName(WeakRef<Framebuffer> fb) {
    String name = "DrawScreenTextureStage_";
    if(fb.expired())
    {
        return name;
    }
    auto _fb = fb.lock();
    name += _fb->m_Name;

    return name;
}
