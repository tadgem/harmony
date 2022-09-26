#include "Rendering/PipelineStage.h"
#include "Rendering/Renderer.h"
#include "ECS/MaterialComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/TransformComponent.h"
#include "Core/Log.hpp"
harmony::PipelineStage::PipelineStage(const std::string& name, Type stageType, WeakRef<ShaderProgram> shader, Attachment::Type attachments) : m_Name(name), m_StageType(stageType), m_Attachments(attachments), p_Shader(shader)
{
}

harmony::PipelineStage::PipelineStage()
{
}

bgfx::FrameBufferHandle harmony::PipelineStage::Init(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	if (view.expired())
	{
		harmony::log::error("trying to run pipeline init for view that does not exist.");
	}

	Ref<View> _view = view.lock();
	std::vector<bgfx::TextureHandle> fbAttachments = std::vector<bgfx::TextureHandle>();

	if (m_Attachments && Attachment::Type::RGBA16F ||
		m_Attachments && Attachment::Type::RGBA32F)
	{
		m_HasHDRAttachment = true;
	}

	if (m_Attachments && Attachment::Type::Depth16F ||
		m_Attachments && Attachment::Type::Depth24F ||
		m_Attachments && Attachment::Type::Depth32F)
	{
		m_HasDepthAttachment = true;
	}


	if (m_HasHDRAttachment)
	{
		bgfx::TextureFormat::Enum format = bgfx::TextureFormat::Unknown;
		if (m_Attachments && Attachment::Type::RGBA16F)
		{
			format = bgfx::TextureFormat::RGBA16F;
		}
		else if (m_Attachments && Attachment::Type::RGBA32F)
		{
			format = bgfx::TextureFormat::RGBA32F;
		}
		else
		{
			harmony::log::error("Invalid attachment format specified, defaulting to RGBA16F");
			format = bgfx::TextureFormat::RGBA16F;
		}

		fbAttachments.emplace_back(
			bgfx::createTexture2D(
				 _view->m_Width
				, _view->m_Height
				, false
				, 1
				, format
				, BGFX_TEXTURE_RT
			));
	}
	else
	{
		fbAttachments.emplace_back(
			bgfx::createTexture2D(
				_view->m_Width
				, _view->m_Height
				, false
				, 1
				, bgfx::TextureFormat::BGRA8
				, BGFX_TEXTURE_RT
			));
	}

	if (m_HasDepthAttachment)
	{
		bgfx::TextureFormat::Enum format = bgfx::TextureFormat::Unknown;
		if (m_Attachments && Attachment::Type::Depth16F)
		{
			format = bgfx::TextureFormat::D16F;
		}
		else if (m_Attachments && Attachment::Type::Depth24F)
		{
			format = bgfx::TextureFormat::D24F;
		}
		else if (m_Attachments && Attachment::Type::Depth32F)
		{
			format = bgfx::TextureFormat::D32F;
		}
		else
		{
			harmony::log::error("Invalid depth attachment format specified, defaulting to D16F");
			format = bgfx::TextureFormat::D16F;
		}

		fbAttachments.emplace_back(
			bgfx::createTexture2D(
				_view->m_Width
				, _view->m_Height
				, false
				, 1
				, format
				, BGFX_TEXTURE_RT | BGFX_STATE_DEPTH_TEST_LESS | BGFX_TEXTURE_BLIT_DST
			));
	}
	
	bgfx::FrameBufferHandle fbh = bgfx::createFrameBuffer(fbAttachments.size(), fbAttachments.data(), false);
	// this needs to be moved to the Viewport or PipelineStack
	bgfx::setViewFrameBuffer(viewId, fbh);
	bgfx::setViewRect(viewId, 0, 0, bgfx::BackbufferRatio::Equal);

	return fbh;
}

void harmony::PipelineStage::PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	
	bgfx::setViewClear(viewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH , 0x00000000, 1.0f);
	Ref<View> _view = view.lock();
	bgfx::setViewTransform(viewId, &_view->m_View[0], &_view->m_Projection[0]);
	bgfx::setViewRect(viewId, 0, 0, _view->m_Width, _view->m_Height);

	auto drawables = registry.view<MeshComponent, MaterialComponent, TransformComponent>();
	Ref<ShaderProgram> pipelineShader = p_Shader.lock();

	for (auto [e, mesh, material, transform] : drawables.each())
	{
		if (material.Data.m_Shader.lock() == pipelineShader)
		{
			bool vbhValid = mesh.MeshHandle.m_VBH.idx <= 4096;
			bool ibhValid = mesh.MeshHandle.m_IBH.idx <= 4096;
			if (!vbhValid || !ibhValid)
			{
				continue;
			}
			material.Data.SetContainerUniforms();
			bgfx::setTransform(&transform.Model[0]);
			bgfx::setVertexBuffer(0, mesh.MeshHandle.m_VBH);
			bgfx::setIndexBuffer(mesh.MeshHandle.m_IBH);
			bgfx::submit(viewId, pipelineShader->m_Handle);
		}
	}
}

void harmony::PipelineStage::PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	
}

void harmony::PipelineStage::Cleanup()
{
}
