#include <optick.h>
#include <Rendering/Pipelines/PipelineStages/PipelineDrawStage.h>
#include "Rendering/Pipelines/BuiltIn/VectorPipeline.h"
#include "Rendering/View.h"
#include "Core/Program.h"
#include "Rendering/Framebuffer.h"

harmony::VectorGraphicsStage::VectorGraphicsStage(VectorGraphics::Layer layer)
        : PipelineDrawStage("VectorGraphicsStage", PipelineStage::Type::PrimaryDraw, WeakRef<ShaderProgram>(),
                            WeakRef<PipelineStageRenderer>(), {harmony::AttachmentType::RGBA8}),
          m_Layer(layer) {
    OPTICK_EVENT();
}

void harmony::VectorGraphicsStage::PreUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) {
    OPTICK_EVENT();
    Ref<View> _view = view.lock();
    bgfx::setViewRect(viewId, 0, 0, _view->m_Width, _view->m_Height);
    bgfx::setViewTransform(viewId, &_view->m_View[0], &_view->m_Projection[0]);
    nvgBeginFrame(p_VectorRenderers[_view->m_Name], float(_view->m_Width), float(_view->m_Height), 1.0f);
}

void harmony::VectorGraphicsStage::PostUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) {
    OPTICK_EVENT();
    Ref<View> _view = view.lock();
    nvgEndFrame(p_VectorRenderers[_view->m_Name]);
    bgfx::touch(viewId);
    PipelineDrawStage::PostUpdate(registry, view, viewId);
}

void harmony::VectorGraphicsStage::Cleanup(WeakRef<View> view, bgfx::ViewId viewId) {
    OPTICK_EVENT();
    Ref<View> _view = view.lock();
    VectorGraphics::Get()->RemoveViewLayer(m_Layer, p_VectorRenderers[_view->m_Name]);
    p_VectorRenderers.erase(_view->m_Name);
}
