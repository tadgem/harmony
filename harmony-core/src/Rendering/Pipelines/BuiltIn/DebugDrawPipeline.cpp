#include <optick.h>
#include "Rendering/Pipelines/BuiltIn/DebugDrawPipeline.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Core/MathsUtils.h"
#include "Core/Input.h"
#include "Rendering/Framebuffer.h"

harmony::DebugDrawStage::DebugDrawStage(GfxDebug::Channel channel) : PipelineDrawStage("DebugDrawStage",
                                                                                       PipelineDrawStage::Type::PrimaryDraw,
                                                                                       WeakPtr<ShaderProgram>(),
                                                                                       WeakPtr<PipelineStageRenderer>()),
                                                                     m_Channel(channel) {
    OPTICK_EVENT();
}

void harmony::DebugDrawStage::PreUpdate(entt::registry &registry, WeakPtr<View> view, bgfx::ViewId viewId) {
    OPTICK_EVENT();
    RefCntPtr<View> _view = view.lock();
    bgfx::setViewClear(viewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x0000000, 1.0f);
    bgfx::setViewTransform(viewId, &_view->m_View[0], &_view->m_Projection[0]);
    bgfx::setViewRect(viewId, 0, 0, _view->m_Width, _view->m_Height);
    if (p_DebugRenderers.find(_view->m_Name) == p_DebugRenderers.end()) {
        p_DebugRenderers.emplace(_view->m_Name, GfxDebug::Get()->AddViewChannel(m_Channel));
    }

    p_DebugRenderers[_view->m_Name]->begin(viewId, true);
}

void harmony::DebugDrawStage::PostUpdate(entt::registry &registry, WeakPtr<View> view, bgfx::ViewId viewId) {
    OPTICK_EVENT();
    p_DebugRenderers[view.lock()->m_Name]->end();
    PipelineDrawStage::PostUpdate(registry, view, viewId);

}

void harmony::DebugDrawStage::Cleanup(WeakPtr<View> view, bgfx::ViewId viewId) {
    OPTICK_EVENT();
    RefCntPtr<View> _view = view.lock();
    if (p_DebugRenderers.find(_view->m_Name) == p_DebugRenderers.end()) {
        return;
    }

    DebugDrawEncoder *debugEncoder = p_DebugRenderers[_view->m_Name];
    GfxDebug::Get()->RemoveViewChannel(m_Channel, debugEncoder);
    p_DebugRenderers.erase(_view->m_Name);
}
