#include "Core/Log.hpp"
#include "Core/Memory.h"
#include "Rendering/Pipelines/PipelineV2.h"
#include "Rendering/Pipelines/PipelineStage.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/View.h"
#include "Rendering/GPUResourceManager.h"

harmony::PipelineV2::PipelineV2(const String &name) : m_Name(name) {
    p_OutputFramebuffer = WeakPtr<Framebuffer>();
}

bool
harmony::PipelineV2::AddPipelineStage(harmony::WeakPtr<Framebuffer> fb, harmony::RefCntPtr<harmony::PipelineStage> stage) {
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

harmony::WeakPtr<harmony::Framebuffer>
harmony::PipelineV2::AddFramebuffer(const String &name, harmony::Vector<harmony::AttachmentType> attachments,
                                    harmony::Resolution::Type resolutionType) {
    String fbName = m_Name + "_" + name;
    auto fb = CreateFrambufferInternal(fbName, attachments, resolutionType);
    p_Stages.emplace(fb, Vector<RefCntPtr<PipelineStage>>());
    return fb;
}

harmony::WeakPtr<harmony::Framebuffer> harmony::PipelineV2::GetFramebuffer(const String& name)
{
    for(auto& [fb, stage] : p_Stages)
    {
        if(fb->m_Name == name)
        {
            return fb;
        }
    }

    return WeakPtr<Framebuffer>();
}

void harmony::PipelineV2::PreUpdate(entt::registry &registry, harmony::WeakPtr<harmony::View> view) {
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

void harmony::PipelineV2::PostUpdate(entt::registry &registry, harmony::WeakPtr<harmony::View> view) {
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

harmony::RefCntPtr<harmony::Framebuffer>
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

bool harmony::PipelineV2::IsViewValid(harmony::WeakPtr<harmony::View> view) {
    if (view.lock()) {
        return true;
    }
    return false;
}

bool harmony::PipelineV2::HasOutputFramebuffer() {
    return !GetOutputFramebuffer().expired();
}

harmony::WeakPtr<harmony::Framebuffer> harmony::PipelineV2::GetOutputFramebuffer() {
    return p_OutputFramebuffer;
}

void harmony::PipelineV2::SetOutputFramebuffer(harmony::WeakPtr<harmony::Framebuffer> framebuffer) {
    if (framebuffer.expired()) {
        harmony::log::error("Pipeline : {} : Attempting to set output framebuffer which is expired", m_Name);
        return;
    }

    RefCntPtr<Framebuffer> fb = framebuffer.lock();

    if (p_Stages.find(fb) == p_Stages.end()) {
        harmony::log::error(
                "Pipeline : {} : Attempting to set output framebuffer : {} : but it is not a part of this pipeline",
                m_Name, fb->m_Name);
        return;
    }

    p_OutputFramebuffer = framebuffer;
}

harmony::WeakPtr<harmony::Framebuffer> harmony::PipelineV2::TryGetFramebuffer(const harmony::String &name) {
    for (auto &[fb, stages]: p_Stages) {
        if (fb->m_Name == name) {
            return fb;
        }
    }
    return harmony::WeakPtr<harmony::Framebuffer>();
}

void harmony::PipelineV2::Resize(entt::registry &registry, harmony::WeakPtr<harmony::View> view) {
    auto v = view.lock();
    if (!v) {
        harmony::log::error("PipelineV2 : Cannot resize view, expired.");
        return;
    }

    for (auto &[fb, stages]: p_Stages) {
        fb->Resize(v->m_Width, v->m_Height);
    }
}
