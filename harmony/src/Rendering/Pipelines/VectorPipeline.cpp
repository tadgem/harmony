#include "Rendering/Pipelines/VectorPipeline.h"
#include "Rendering/View.h"
#include "Core/Program.h"
harmony::VectorGraphicsStage::VectorGraphicsStage(VectorGraphics::Layer layer) 
	:	PipelineStage("VectorGraphicsStage", PipelineStage::Type::PrimaryDraw, WeakRef<ShaderProgram>(), harmony::Attachment::Type::RGBA16F),
		m_Layer(layer)
{
	
}

harmony::PipelineStage::Data harmony::VectorGraphicsStage::Init(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
    HARMONY_PROFILE_FUNCTION()

    p_Shader = Program::Get()->m_Renderer.GetShader("NanoVG");
    
	Ref<View> _view = view.lock();
	std::vector<bgfx::TextureHandle> fbAttachments = std::vector<bgfx::TextureHandle>();
	std::map<Attachment::Type, Attachment> attachments = std::map<Attachment::Type, Attachment>();
	fbAttachments.emplace_back(
	bgfx::createTexture2D(
			_view->m_Width
		,	_view->m_Height
		, false
		, 1
		, bgfx::TextureFormat::BGRA8
		, BGFX_TEXTURE_RT
	));

	Attachment a
	{
		fbAttachments[0],
		Attachment::Type::RGBA8F
	};
	attachments.emplace(Attachment::Type::RGBA8F, a);

	m_HasHDRAttachment = false;
	m_HasDepthAttachment = false;

	NVGcontext* nvgRenderer = VectorGraphics::Get()->AddViewLayer(m_Layer, viewId);
	p_VectorRenderers.emplace(_view->m_Name, nvgRenderer);

	bgfx::FrameBufferHandle fbh = bgfx::createFrameBuffer(fbAttachments.size(), fbAttachments.data(), false);
	bgfx::setViewRect(viewId, 0, 0, bgfx::BackbufferRatio::Equal);
	bgfx::setViewFrameBuffer(viewId, fbh);
	bgfx::setViewMode(viewId, bgfx::ViewMode::Sequential);
	bgfx::setViewName(viewId, "NanoVG");

	return PipelineStage::Data{ fbh, attachments };
}

void harmony::VectorGraphicsStage::PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	Ref<View> _view = view.lock();
	bgfx::setViewRect(viewId, 0, 0, _view->m_Width, _view->m_Height);
	nvgBeginFrame(p_VectorRenderers[_view->m_Name], float(_view->m_Width), float(_view->m_Width), 1.0f);
}

void harmony::VectorGraphicsStage::PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	Ref<View> _view = view.lock();
	nvgEndFrame(p_VectorRenderers[_view->m_Name]);
	bgfx::touch(viewId);
	PipelineStage::PostUpdate(registry, view, viewId);
}

void harmony::VectorGraphicsStage::Cleanup(WeakRef<View> view, bgfx::ViewId viewId)
{
	Ref<View> _view = view.lock();
	VectorGraphics::Get()->RemoveViewLayer(m_Layer, p_VectorRenderers[_view->m_Name]);
	p_VectorRenderers.erase(_view->m_Name);
}


harmony::VectorPipeline::VectorPipeline(VectorGraphics::Layer layer) : Pipeline(PipelineHandle("VectorGraphicsPipeline"), Pipeline::Type::ScreenSpace)
{
	AddPipelineStage<VectorGraphicsStage>(layer);
}