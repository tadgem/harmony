#include <optick.h>
#include "Rendering/Pipelines/PipelineStages/PipelineDrawStage.h"
#include "Rendering/Pipelines/PipelineStageRenderer.h"
#include "Rendering/Renderer.h"
#include "Rendering/View.h"
#include "Core/Log.hpp"

harmony::PipelineDrawStage::PipelineDrawStage(const std::string &name, Type stageType, WeakPtr<ShaderProgram> shader,
                                              WeakPtr<PipelineStageRenderer> stageRenderer,
                                              Vector<AttachmentType> attachments) : PipelineStage(name, stageType,
                                                                                                  attachments, shader,
                                                                                                  stageRenderer) {
    OPTICK_EVENT();
}

void harmony::PipelineDrawStage::PreUpdate(entt::registry &registry, WeakPtr<View> view, bgfx::ViewId viewId) {
    OPTICK_EVENT();
    RefCntPtr<View> _view = view.lock();
    bgfx::setViewTransform(viewId, &_view->m_View[0], &_view->m_Projection[0]);
    bgfx::setViewRect(viewId, 0, 0, _view->m_Width, _view->m_Height);

    RefCntPtr<ShaderProgram> pipelineShader = p_Shader.lock();

    for (WeakPtr<ShaderDataSource> &source: p_DataSources) {
        if (source.expired()) {
            continue;
        }
        auto src = source.lock();
        src->OnPreUpdate(registry, pipelineShader);
    }
    // Per instance uniforms should be handled by material.
    p_Renderer->Draw(registry, pipelineShader, _view, viewId);
}

void harmony::PipelineDrawStage::PostUpdate(entt::registry &registry, WeakPtr<View> view, bgfx::ViewId viewId) {
    OPTICK_EVENT();
    RefCntPtr<ShaderProgram> pipelineShader = p_Shader.lock();
    for (WeakPtr<ShaderDataSource> &source: p_DataSources) {
        if (source.expired()) {
            continue;
        }
        auto src = source.lock();
        src->OnPostUpdate(registry, pipelineShader);
    }
}



