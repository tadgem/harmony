#include <optick.h>
#include "Rendering/Pipelines/PipelineStage.h"
#include "Rendering/Pipelines/PipelineStageRenderer.h"
#include "Rendering/View.h"
#include "Core/SerializationKeys.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/GPUResourceManager.h"

harmony::PipelineStage::PipelineStage(const std::string &name, Type pipelineStageType,
                                      Vector<AttachmentType> requiredAttachments,
                                      WeakPtr<ShaderProgram> shader, WeakPtr<PipelineStageRenderer> stageRenderer)
        : m_Name(name), m_StageType(pipelineStageType), m_Attachments(requiredAttachments), p_Shader(shader),
          p_Renderer(stageRenderer.lock()) {
    OPTICK_EVENT();
}

void harmony::PipelineStage::Cleanup(WeakPtr<View> view, bgfx::ViewId viewId) {
    OPTICK_EVENT();
}

void harmony::PipelineStage::AddShaderDataSource(WeakPtr<ShaderDataSource> source) {
    OPTICK_EVENT();
    if (source.expired()) {
        return;
    }
    for (int i = 0; i < p_DataSources.size(); i++) {
        if (p_DataSources[i].expired()) {
            continue;
        }
        if (p_DataSources[i].lock() == source.lock()) {
            harmony::log::warn("PipelineStage : Stage {} already has data source : {}", m_Name, source.lock()->m_Name);
            return;
        }
    }
    p_DataSources.emplace_back(source);
}

nlohmann::json harmony::PipelineStage::Serialize() {
    OPTICK_EVENT();
    nlohmann::json j;
    j[sk_PipelineStageName] = m_Name;
    j[sk_PipelineStageAttachments] = m_Attachments;
    j[sk_PipelineStageType] = m_StageType;
    j[sk_PipelineStageShader] = *p_Shader.lock();

    if (p_Renderer) {
        j[sk_PipelineStageRenderer] = nlohmann::json();
    } else {
        j[sk_PipelineStageRenderer] = *p_Renderer;
    }
    return j;
}

void harmony::PipelineStage::Deserialize(nlohmann::json j) {
    OPTICK_EVENT();
    m_Name = j[sk_PipelineStageName];
    // m_Attachments = j[sk_PipelineStageAttachments];
    m_StageType = j[sk_PipelineStageType];
}