#include "Rendering/Pipelines/PipelineV2.h"
#include "Rendering/Pipelines/PipelineStage.h"
#include "Rendering/Framebuffer.h"
#include "Core/Log.hpp"
#include "Rendering/GPUResourceManager.h"
#include "Core/Memory.h"

harmony::PipelineV2::PipelineV2(const String &name) : m_Name(name) {
    p_OutputFramebuffer = WeakRef<Framebuffer>();
}

bool
harmony::PipelineV2::AddPipelineStage(harmony::WeakRef<Framebuffer> fb, harmony::Ref<harmony::PipelineStage> stage) {
    auto framebuffer = fb.lock();
    if (!framebuffer) {
        harmony::log::error("Pipeline : {} : Cannot add PipelineStage to Pipeline : passed Framebuffer is expired.",
                            m_Name);
        return false;
    }

    if (p_Stages.find(framebuffer) == p_Stages.end()) {
        harmony::log::error(
                "Pipeline : {} : Cannot add PipelineStage to Pipeline {} : passed Framebuffer is not part of this pipeline.",
                m_Name);
        return false;
    }

    p_Stages[framebuffer].emplace_back(stage);
    return true;
}

harmony::WeakRef<harmony::Framebuffer>
harmony::PipelineV2::AddFramebuffer(const String &name, harmony::Vector<harmony::AttachmentType> attachments,
                                    harmony::Resolution::Type resolutionType) {
    String fbName = m_Name + "_" + name;
    auto fb = CreateFrambufferInternal(fbName, attachments, resolutionType);
    p_Stages.emplace(fb, Vector<Ref<PipelineStage>>());
    return fb;
}

void harmony::PipelineV2::PreUpdate(entt::registry &registry, harmony::WeakRef<harmony::View> view) {
    if (!IsViewValid(view)) {
        harmony::log::error("Pipeline : {} : Cannot Pre-Update, view is expired!", m_Name);
        return;
    }

    for (auto &[fb, stages]: p_Stages) {
        bgfx::setViewFrameBuffer(fb->m_ViewID, fb->m_FBH);
        bgfx::setViewClear(fb->m_ViewID, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000, 1.0f, 0x00000000);
        for (auto &stage: stages) {
            if (!stage) {
                continue;
            }

            stage->PreUpdate(registry, view, fb->m_ViewID);
        }
    }
}

void harmony::PipelineV2::PostUpdate(entt::registry &registry, harmony::WeakRef<harmony::View> view) {
    if (!IsViewValid(view)) {
        harmony::log::error("Pipeline : {} : Cannot Post-Update, view is expired!", m_Name);
        return;
    }

    for (auto &[fb, stages]: p_Stages) {
        for (auto &stage: stages) {
            if (!stage) {
                continue;
            }
            stage->PostUpdate(registry, view, fb->m_ViewID);
        }
    }
}

harmony::Ref<harmony::Framebuffer>
harmony::PipelineV2::CreateFrambufferInternal(const String &name, harmony::Vector<harmony::AttachmentType> attachments,
                                              harmony::Resolution::Type resolutionType) {
    Resolution res{GPUResourceManager::GetMaxFramebufferWidth(), GPUResourceManager::GetMaxFramebufferHeight()};
    auto fb = CreateRef<Framebuffer>(name, res);
    for (AttachmentType &a: attachments) {
        fb->CreateAttachment(a);
    }
    fb->Build();
    return fb;
}

bool harmony::PipelineV2::IsViewValid(harmony::WeakRef<harmony::View> view) {
    if (view.lock()) {
        return true;
    }
    return false;
}

bool harmony::PipelineV2::HasOutputFramebuffer() {
    return !GetOutputFramebuffer().expired();
}

harmony::WeakRef<harmony::Framebuffer> harmony::PipelineV2::GetOutputFramebuffer() {
    return p_OutputFramebuffer;
}

void harmony::PipelineV2::SetOutputFramebuffer(harmony::WeakRef<harmony::Framebuffer> framebuffer) {
    if (framebuffer.expired()) {
        harmony::log::error("Pipeline : {} : Attempting to set output framebuffer which is expired", m_Name);
        return;
    }

    Ref<Framebuffer> fb = framebuffer.lock();

    if (p_Stages.find(fb) == p_Stages.end()) {
        harmony::log::error(
                "Pipeline : {} : Attempting to set output framebuffer : {} : but it is not a part of this pipeline",
                m_Name, fb->m_Name);
        return;
    }

    p_OutputFramebuffer = framebuffer;
}
