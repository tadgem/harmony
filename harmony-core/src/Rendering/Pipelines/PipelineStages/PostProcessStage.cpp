#include <optick.h>
#include <Rendering/Shapes.h>
#include "Rendering/Pipelines/PipelineStages/PostProcessStage.h"
#include "Rendering/View.h"
#include "Rendering/Framebuffer.h"

harmony::AttachmentType harmony::PostProcessStage::s_AttachmentType = harmony::AttachmentType::RGBA8;

harmony::PostProcessStage::PostProcessStage(const String &name, Type stageType, WeakPtr<ShaderProgram> shader,
                                            WeakPtr<PipelineStageRenderer> stageRenderer,
                                            Vector<AttachmentType> attachments)
        : PipelineStage(name, stageType, attachments, shader, stageRenderer) {
    OPTICK_EVENT();
}

void harmony::PostProcessStage::PreUpdate(entt::registry &registry, WeakPtr<View> view, bgfx::ViewId viewId,
                                          RefCntPtr<Framebuffer>) {
    OPTICK_EVENT();
}

void harmony::PostProcessStage::PostUpdate(entt::registry &registry, WeakPtr<View> view, bgfx::ViewId viewId,
                                           RefCntPtr<Framebuffer> data) {
    OPTICK_EVENT();
    RefCntPtr<ShaderProgram> s = p_Shader.lock();
    for (WeakPtr<ShaderDataSource> &source: p_DataSources) {
        if (source.expired()) {
            continue;
        }
        auto src = source.lock();
        src->OnPostUpdate(registry, s);
    }
    bool hasDepth = false;
    bool hasParams = false;
    int numSamplers = 0;
    bgfx::UniformHandle colourAttachmentUniform{ bgfx::kInvalidHandle };
    bgfx::UniformHandle depthAttachmentUniform{ bgfx::kInvalidHandle };
    bgfx::UniformHandle postProcessParamsUniform{ bgfx::kInvalidHandle };

    for (int i = 0; i < s->m_Uniforms.size(); i++) {
        if (s->m_Uniforms[i].Type == bgfx::UniformType::Vec4) {
            hasParams = true;
            postProcessParamsUniform = s->m_Uniforms[i].BgfxHandle;
        }
        if (s->m_Uniforms[i].Type == bgfx::UniformType::Sampler) {
            if (numSamplers == 0) {
                colourAttachmentUniform = s->m_Uniforms[i].BgfxHandle;
                numSamplers++;
                continue;
            }
            if (numSamplers == 1) {
                hasDepth = true;
                numSamplers++;
                depthAttachmentUniform = s->m_Uniforms[i].BgfxHandle;
            }

        }
    }

    for (WeakPtr<ShaderDataSource> &source: p_DataSources) {
        if (source.expired()) {
            continue;
        }
        auto src = source.lock();
        src->OnPreUpdate(registry, s);
    }

    RefCntPtr<View> v = view.lock();

    bgfx::setViewClear(viewId, BGFX_CLEAR_COLOR, 0x00000000, 1.0f);
    bgfx::setViewRect(viewId, 0, 0, v->m_Width, v->m_Height);

    bgfx::TextureHandle colourAttachment = data->m_Attachments[0].m_Handle;
    bgfx::setTexture(0, colourAttachmentUniform, colourAttachment);

    glm::vec4 params(v->m_Width, v->m_Height, 0, 0);
    if (hasParams) {
        bgfx::setUniform(postProcessParamsUniform, &params[0]);
    }
    ScreenSpaceQuad(static_cast<float>(v->m_Width), static_cast<float>(v->m_Height), static_cast<float>(v->m_Width),
                    static_cast<float>(v->m_Height));
    bgfx::submit(viewId, s->m_Handle);
}

void harmony::PostProcessStage::PreUpdate(entt::registry &registry, harmony::WeakPtr<harmony::View> view,
                                          bgfx::ViewId viewId) {

}

void harmony::PostProcessStage::PostUpdate(entt::registry &registry, harmony::WeakPtr<harmony::View> view,
                                           bgfx::ViewId viewId) {

}
