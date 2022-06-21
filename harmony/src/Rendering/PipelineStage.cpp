#include "Rendering/PipelineStage.h"
#include "Rendering/Renderer.h"
#include "Core/Log.hpp"
harmony::PipelineStage::PipelineStage(Type stageType, WeakRef<ShaderProgram> shader) : m_ViewId(Renderer::GetViewID()), m_StageType(stageType), p_Shader(shader)
{
	p_FrameBufferHandle = BGFX_INVALID_HANDLE;
}

void harmony::PipelineStage::Init(entt::registry& registry, WeakRef<View> view)
{
	if (view.expired())
	{
		harmony::log::error("trying to run pipeline init for view that does not exist.");
	}

	Ref<View> _view = view.lock();
	p_FrameBufferHandle = bgfx::createFrameBuffer(_view->m_Width, _view->m_Height, bgfx::TextureFormat::BGRA8);
	bgfx::setViewFrameBuffer(m_ViewId, p_FrameBufferHandle);
}

void harmony::PipelineStage::PreUpdate(entt::registry& registry, WeakRef<View> view)
{
}

void harmony::PipelineStage::PostUpdate(entt::registry& registry, WeakRef<View> view)
{
}

bgfx::FrameBufferHandle harmony::PipelineStage::GetStageFinalFramebuffer()
{
	return p_FrameBufferHandle;
}
