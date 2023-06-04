#include "Rendering/Pipelines/PipelineStages/DrawScreenTextureStage.h"
//
// Created by Admin on 6/4/2023.
//
void harmony::DrawScreenTextureStage::PreUpdate(entt::registry &registry, harmony::WeakRef<harmony::View> view,
                                                bgfx::ViewId viewId) {

}

void harmony::DrawScreenTextureStage::PostUpdate(entt::registry &registry, harmony::WeakRef<harmony::View> view,
                                                 bgfx::ViewId viewId) {

}

harmony::DrawScreenTextureStage::DrawScreenTextureStage(harmony::WeakRef<harmony::Framebuffer> fb) : PipelineStage("DrawScreenTexture"), m_FramebufferToDraw(fb)
{

}
