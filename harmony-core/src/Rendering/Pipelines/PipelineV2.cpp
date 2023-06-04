#include "Rendering/Pipelines/PipelineV2.h"
#include "Rendering/Pipelines/PipelineStage.h"
#include "Rendering/Framebuffer.h"
#include "Core/Log.hpp"
#include "Rendering/GPUResourceManager.h"
#include "Core/Memory.h"

harmony::PipelineV2::PipelineV2(std::string &&name) : m_Name(std::move(name)) {
    p_FinalImageFramebuffer = CreateFrambufferInternal({AttachmentType::RGBA8}, Resolution::Type::FullScale);
}

bool harmony::PipelineV2::AddPipelineStage(harmony::WeakRef<Framebuffer> fb, harmony::Ref<harmony::PipelineStage> stage) {
    auto framebuffer = fb.lock();
    if(!framebuffer)
    {
        harmony::log::error("Pipeline : Cannot add PipelineStage to Pipeline {} : passed Framebuffer is expired.", m_Name);
        return false;
    }

    if(p_Stages.find(framebuffer) == p_Stages.end())
    {
        harmony::log::error("Pipeline : Cannot add PipelineStage to Pipeline {} : passed Framebuffer is not part of this pipeline.", m_Name);
        return false;
    }

    p_Stages[framebuffer].emplace_back(stage);
    return true;
}

harmony::WeakRef<harmony::Framebuffer>
harmony::PipelineV2::AddFramebuffer(harmony::Vector<harmony::AttachmentType> attachments, harmony::Resolution::Type resolutionType) {
    auto fb = CreateFrambufferInternal(attachments, resolutionType);
    p_Stages.emplace(fb, Vector<Ref<PipelineStage>>());
    return fb;
}

void harmony::PipelineV2::PreUpdate(entt::registry &registry, harmony::WeakRef<harmony::View> view) {
    if(!IsViewValid(view))
    {
        harmony::log::error("Pipeline : {} : Cannot Pre-Update, view is expired!", m_Name);
        return;
    }

    for(auto& [fb, stages] : p_Stages)
    {
        for(auto& stage : stages)
        {
            stage->PreUpdate(registry, view, fb->m_ViewID);
        }
    }
}

void harmony::PipelineV2::PostUpdate(entt::registry &registry, harmony::WeakRef<harmony::View> view) {
    if(!IsViewValid(view))
    {
        harmony::log::error("Pipeline : {} : Cannot Post-Update, view is expired!", m_Name);
        return;
    }

    for(auto& [fb, stages] : p_Stages)
    {
        for(auto& stage : stages)
        {
            stage->PostUpdate(registry, view, fb->m_ViewID);
        }
    }
}

harmony::Ref<harmony::Framebuffer>
harmony::PipelineV2::CreateFrambufferInternal(harmony::Vector<harmony::AttachmentType> attachments,
                                              harmony::Resolution::Type resolutionType) {
    Resolution res {GPUResourceManager::GetMaxFramebufferWidth(), GPUResourceManager::GetMaxFramebufferHeight()};
    auto fb = CreateRef<Framebuffer>(res);
    for(AttachmentType& a : attachments)
    {
        fb->CreateAttachment(a);
    }
    fb->Build();
    return fb;
}

bool harmony::PipelineV2::IsViewValid(harmony::WeakRef<harmony::View> view) {
    if(view.lock())
    {
        return true;
    }
    return false;
}
