//
// Created by liam_ on 7/6/2023.
//
#include "Rendering/Pipelines/PipelineStageRenderers/ScreenQuadRenderer.h"
#include "Rendering/Shapes.h"
#include "Rendering/View.h"
#include "Rendering/GPUResourceManager.h"

void
harmony::ScreenQuadRenderer::Draw(entt::registry &scene, harmony::RefCntPtr<harmony::ShaderProgram> shader, RefCntPtr<View> view,
                                  bgfx::ViewId viewId) {
    if (!shader) {
        return;
    }
    ScreenSpaceQuad(GPUResourceManager::GetMaxFramebufferWidth(), GPUResourceManager::GetMaxFramebufferHeight(),
                    view->m_Width, view->m_Height);
    bgfx::setViewTransform(viewId, NULL, NULL);
    bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
    bgfx::submit(viewId, shader->m_Handle);
}

harmony::ScreenQuadRenderer::ScreenQuadRenderer() : PipelineStageRenderer("ScreenQuadRenderer") {

}
