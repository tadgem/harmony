#include "Rendering/PipelineStage.h"
#include "Rendering/Renderer.h"
#include "Core/Log.hpp"
harmony::PipelineStage::PipelineStage(Type stageType, WeakRef<ShaderProgram> shader) : m_ViewId(Renderer::GetViewID()), m_StageType(stageType), p_Shader(shader)
{
	p_FrameBufferHandle = BGFX_INVALID_HANDLE;
}

void harmony::PipelineStage::Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	if (view.expired())
	{
		harmony::log::error("trying to run pipeline init for view that does not exist.");
	}

	Ref<View> _view = view.lock();
	p_FrameBufferHandle = bgfx::createFrameBuffer(_view->m_Width, _view->m_Height, bgfx::TextureFormat::BGRA8);
	bgfx::setViewFrameBuffer(m_ViewId, p_FrameBufferHandle);
	bgfx::setViewRect(m_ViewId, 0, 0, bgfx::BackbufferRatio::Equal);
}

void harmony::PipelineStage::PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	if (p_RunPreFrame)
	{
		harmony::log::error("Already ran pre frame callback for this frame!");
		return;
	}
	bgfx::setViewClear(m_ViewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH , 0x00000000);
	Ref<View> _view = view.lock();
	bgfx::setViewTransform(m_ViewId, &_view->m_View[0], &_view->m_Projection[0]);
	bgfx::setViewRect(m_ViewId, 0, 0, _view->m_Width, _view->m_Height);
}

void harmony::PipelineStage::PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	p_RunPreFrame = false;
}

bgfx::FrameBufferHandle harmony::PipelineStage::GetStageFinalFramebuffer()
{
	return p_FrameBufferHandle;
}
