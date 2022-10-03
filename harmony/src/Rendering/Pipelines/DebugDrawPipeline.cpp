#include "Rendering/Pipelines/DebugDrawPipeline.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Core/MathsUtils.h"
#include "Core/Input.h"
#include "Core/Log.hpp"

harmony::DebugDrawStage::DebugDrawStage(GfxDebug::Channel channel) : PipelineStage("DebugDrawStage", PipelineStage::Type::PrimaryDraw, WeakRef<ShaderProgram>()), m_Channel(channel)
{
	p_DebugRenderer = nullptr;
}

harmony::PipelineStage::Data harmony::DebugDrawStage::Init(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	if (view.expired())
	{
		harmony::log::error("trying to run pipeline init for view that does not exist.");
	}

	Ref<View> _view = view.lock();
	std::map<Attachment::Type, Attachment> attachments = std::map<Attachment::Type, Attachment>();
	bgfx::TextureHandle fbtexture[] =
	{ bgfx::createTexture2D(
		_view->m_Width
		, _view->m_Height
		, false
		, 1
		, bgfx::TextureFormat::BGRA8
		, BGFX_TEXTURE_RT
	)
	};
	Attachment a
	{
		fbtexture[0],
		Attachment::Type::RGBA8F
	};

	attachments.emplace(Attachment::Type::RGBA8F, a);

	bgfx::FrameBufferHandle fbh = bgfx::createFrameBuffer(BX_COUNTOF(fbtexture), fbtexture, false);
	bgfx::setViewFrameBuffer(viewId, fbh);
	bgfx::setViewRect(viewId, 0, 0, bgfx::BackbufferRatio::Equal);
	bgfx::setViewName(viewId, "Debug Draw");

	p_DebugRenderer = GfxDebug::Get()->AddViewChannel(m_Channel);
	PipelineStage::Data data
	{
		fbh,
		attachments
	};

	return data;
}

void harmony::DebugDrawStage::PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	bgfx::setViewClear(viewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000, 1.0f);
	Ref<View> _view = view.lock();
	bgfx::setViewTransform(viewId, &_view->m_View[0], &_view->m_Projection[0]);
	bgfx::setViewRect(viewId, 0, 0, _view->m_Width, _view->m_Height);
	p_DebugRenderer->begin(viewId, false);
}

void harmony::DebugDrawStage::PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	p_DebugRenderer->end();
	bgfx::touch(viewId);
	PipelineStage::PostUpdate(registry, view, viewId);

}

void harmony::DebugDrawStage::Cleanup()
{

}


harmony::DebugDrawPipeline::DebugDrawPipeline(GfxDebug::Channel channel) : Pipeline(PipelineHandle{ "DebugDrawPipline" })
{
	AddPipelineStage<DebugDrawStage>(channel);
}
