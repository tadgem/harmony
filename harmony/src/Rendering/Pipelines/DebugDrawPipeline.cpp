#include "Rendering/Pipelines/DebugDrawPipeline.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Core/MathsUtils.h"
#include "Core/Input.h"
#include "Core/Log.hpp"

harmony::DebugDrawStage::DebugDrawStage(GfxDebug::Channel channel) : PipelineStage(PipelineStage::Type::PrimaryDraw, WeakRef<ShaderProgram>()), m_Channel(channel)
{
	p_RunPreFrame = false;
	p_DebugRenderer = nullptr;
}

void harmony::DebugDrawStage::Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	if (view.expired())
	{
		harmony::log::error("trying to run pipeline init for view that does not exist.");
	}

	Ref<View> _view = view.lock();

	bgfx::TextureHandle fbtextures[] =
	{
		bgfx::createTexture2D(
				_view->m_Width
			, _view->m_Height
			, false
			, 1
			, bgfx::TextureFormat::BGRA8
			, BGFX_TEXTURE_RT
			)
	};

	p_FrameBufferHandle = bgfx::createFrameBuffer(BX_COUNTOF(fbtextures), fbtextures, false);
	bgfx::setViewFrameBuffer(m_ViewId, p_FrameBufferHandle);
	bgfx::setViewRect(m_ViewId, 0, 0, bgfx::BackbufferRatio::Equal);
	bgfx::setViewName(m_ViewId, "Debug Draw");

	p_DebugRenderer = GfxDebug::Get()->AddViewChannel(m_Channel);
	p_DebugRenderer->begin(m_ViewId, false);
	p_RunPreFrame = true;
}

void harmony::DebugDrawStage::PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	PipelineStage::PreUpdate(registry, view, handle);
	p_DebugRenderer->begin(m_ViewId, false);
	p_RunPreFrame = true;
}

void harmony::DebugDrawStage::PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	if (!p_RunPreFrame)
	{
		return;
	}
	p_DebugRenderer->end();
	bgfx::touch(m_ViewId);
	PipelineStage::PostUpdate(registry, view, handle);

}

void harmony::DebugDrawStage::Cleanup()
{

}

harmony::Ref<harmony::PipelineStage> harmony::DebugDrawStage::Clone()
{
	Ref <DebugDrawStage> newStage = CreateRef<DebugDrawStage>(m_Channel);
	return newStage;
}

harmony::DebugDrawPipeline::DebugDrawPipeline(GfxDebug::Channel channel) : Pipeline(PipelineHandle::New("DebugDrawPipline"))
{
	AddPipelineStage<DebugDrawStage>(channel);
}
