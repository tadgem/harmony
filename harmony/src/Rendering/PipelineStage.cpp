#include "Rendering/PipelineStage.h"
#include "Rendering/Renderer.h"
#include "ECS/MaterialComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/TransformComponent.h"
#include "Core/Log.hpp"
harmony::PipelineStage::PipelineStage(Type stageType, WeakRef<ShaderProgram> shader) : m_ViewId(Renderer::GetViewID()), m_StageType(stageType), p_Shader(shader)
{
	p_FrameBufferHandle = BGFX_INVALID_HANDLE;
	p_RunPreFrame = false;
}

void harmony::PipelineStage::Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	if (view.expired())
	{
		harmony::log::error("trying to run pipeline init for view that does not exist.");
	}

	Ref<View> _view = view.lock();

	p_Attachments.emplace_back(
		bgfx::createTexture2D(
			_view->m_Width
			, _view->m_Height
			, false
			, 1
			, bgfx::TextureFormat::BGRA8
			, BGFX_TEXTURE_RT
		));
	p_Attachments.emplace_back(
		bgfx::createTexture2D(
			_view->m_Width
			, _view->m_Height
			, false
			, 1
			, bgfx::TextureFormat::D32F
			, BGFX_TEXTURE_RT| BGFX_STATE_DEPTH_TEST_LESS | BGFX_TEXTURE_BLIT_DST 
		));
	m_HasHDRAttachment = false;
	m_HasDepthAttachment = true;
	p_FrameBufferHandle = bgfx::createFrameBuffer(p_Attachments.size(), p_Attachments.data(), false);
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
	bgfx::setViewClear(m_ViewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH , 0x00000000, 1.0f);
	Ref<View> _view = view.lock();
	bgfx::setViewTransform(m_ViewId, &_view->m_View[0], &_view->m_Projection[0]);
	bgfx::setViewRect(m_ViewId, 0, 0, _view->m_Width, _view->m_Height);

	auto drawables = registry.view<MeshComponent, MaterialComponent, TransformComponent>();
	Ref<ShaderProgram> pipelineShader = p_Shader.lock();

	for (auto [e, mesh, material, transform] : drawables.each())
	{
		if (material.Data.m_Shader.lock() == pipelineShader)
		{
			bool vbhValid = bgfx::isValid(mesh.MeshHandle.m_VBH);
			bool ibhValid = bgfx::isValid(mesh.MeshHandle.m_IBH);
			if (!vbhValid || !ibhValid)
			{
				continue;
			}
			material.Data.SetContainerUniforms();
			bgfx::setTransform(&transform.Model[0]);
			bgfx::setVertexBuffer(0, mesh.MeshHandle.m_VBH);
			bgfx::setIndexBuffer(mesh.MeshHandle.m_IBH);
			bgfx::submit(m_ViewId, pipelineShader->m_Handle);
		}
	}
}

void harmony::PipelineStage::PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	if (!p_RunPreFrame)
	{
		return;
	}
	p_RunPreFrame = false;
}

void harmony::PipelineStage::Cleanup()
{
}

bgfx::FrameBufferHandle harmony::PipelineStage::GetStageFinalFramebuffer()
{
	return p_FrameBufferHandle;
}

bgfx::TextureHandle harmony::PipelineStage::GetStageDepthTexture()
{
	if (!m_HasDepthAttachment)
	{
		return bgfx::TextureHandle();
	}
	return bgfx::getTexture(p_FrameBufferHandle, 1);
}
