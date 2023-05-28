#include <algorithm>
#include <optick.h>
#include "Rendering/Pipelines/Pipeline.h"
#include "Rendering/Pipelines/PipelineDrawStage.h"
#include "Rendering/View.h"
#include "Core/Log.hpp"


harmony::Pipeline::Pipeline(const PipelineHandle &handle, Pipeline::Type pipelineType) : m_Handle(handle),
                                                                                         m_Name(handle.Name),
                                                                                         m_Type(pipelineType),
                                                                                         m_PostProcess(true) {
    OPTICK_EVENT();
}

std::vector<harmony::PipelineDrawStage::Data>
harmony::Pipeline::Init(entt::registry &registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds) {
    OPTICK_EVENT();

    std::vector<PipelineDrawStage::Data> datas = std::vector<PipelineDrawStage::Data>();
    if (p_Stages.size() == 0) {
        return datas;
    }
    for (int i = 0; i < p_Stages.size(); i++) {
        bgfx::setViewMode(viewIds[i], bgfx::ViewMode::Sequential);
        datas.emplace_back(p_Stages[i]->Init(registry, view, viewIds[i]));
    }
    return datas;
}

void harmony::Pipeline::AddPipelineStage(Ref<PipelineDrawStage> stage) {
    OPTICK_EVENT();

    if (std::find(p_Stages.begin(), p_Stages.end(), stage) != p_Stages.end()) {
        harmony::log::warn("Pipeline : {} : already contains stage : {}", m_Name, stage->m_Name);
        return;
    }

    p_Stages.emplace_back(stage);
}

void harmony::Pipeline::PreUpdate(entt::registry &registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds,
                                  std::vector<PipelineDrawStage::Data> data) {
    OPTICK_EVENT();

    Ref<View> _v = view.lock();
    if (p_Stages.size() == 0) {
        return;
    }
    for (int i = 0; i < p_Stages.size(); i++) {
        bgfx::setViewClear(viewIds[i], BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000, 1.0f);
    }

    for (int i = 0; i < p_Stages.size(); i++) {
        p_Stages[i]->PreUpdate(registry, view, viewIds[i]);

        int nextIndex = i + 1;
        if (nextIndex >= p_Stages.size()) {
            continue;
        }

        if (!p_Stages[nextIndex]->m_HasDepthAttachment) {
            continue;
        }

        auto srcData = data[i];
        auto dstData = data[nextIndex];
        AttachmentType srcDepthType = srcData.GetDepthType();
        if (!(srcDepthType == dstData.GetDepthType())) {
            continue;
        }
        // Get first view id of next pipeline
        bgfx::ViewId nextViewId = viewIds[nextIndex];
        // Get tex handles for this stage final depth & next stage initial depth texture
        bgfx::TextureHandle srcTexture = srcData.m_Attachments[srcDepthType].m_Handle;
        bgfx::TextureHandle destTexture = dstData.m_Attachments[srcDepthType].m_Handle;
        // this is blasphemy. Burn
        if (srcTexture.idx >= 4096 || destTexture.idx >= 4096) {
            continue;
        }
        bgfx::blit(
                nextViewId,
                destTexture,
                0,
                0,
                srcTexture
        );
    }
}

void harmony::Pipeline::PostUpdate(entt::registry &registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds,
                                   std::vector<PipelineDrawStage::Data> data) {
    OPTICK_EVENT();

    if (p_Stages.size() == 0) {
        return;
    }
    for (int i = 0; i < p_Stages.size(); i++) {
        p_Stages[i]->PostUpdate(registry, view, viewIds[i]);
    }
}

void harmony::Pipeline::Cleanup(entt::registry &registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds) {
    OPTICK_EVENT();

    if (p_Stages.size() == 0) {
        return;
    }
    for (int i = 0; i < p_Stages.size(); i++) {
        p_Stages[i]->Cleanup(view, viewIds[i]);
    }
}


uint32_t harmony::Pipeline::NumPipelineStages() {
    OPTICK_EVENT();
    return p_Stages.size();
}

bool harmony::Pipeline::HasDepth() {
    OPTICK_EVENT();
    for (Ref<PipelineDrawStage> pipeline: p_Stages) {
        if (pipeline->m_HasDepthAttachment) {
            return true;
        }
    }
    return false;
}

nlohmann::json harmony::Pipeline::Serialize() {
    OPTICK_EVENT();
    auto json = nlohmann::json();

    json["pipeline"] = nlohmann::json();
    json["pipeline"]["name"] = m_Name;
    json["pipeline"]["stages"] = nlohmann::json::array();
    json["pipeline"]["type"] = m_Type;
    for (int i = 0; i < p_Stages.size(); i++) {
        json["pipeline"]["stages"][i] = *p_Stages[i];
    }
    json["pipeline"]["handle"] = m_Handle;

    return json;
}

void harmony::Pipeline::Deserialize(nlohmann::json &json) {
    OPTICK_EVENT();
    m_Name = json["pipeline"]["name"];
    m_Handle = json["pipeline"]["handle"];
    m_Type = json["pipeline"]["type"];
    auto pipelinesJson = json["pipeline"]["stages"];
}
