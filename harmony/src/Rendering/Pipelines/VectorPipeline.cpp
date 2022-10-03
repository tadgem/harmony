#include "Rendering/Pipelines/VectorPipeline.h"
#include "Rendering/View.h"
#include "Core/Program.h"
harmony::VectorGraphicsStage::VectorGraphicsStage() : PipelineStage("VectorGraphicsStage", PipelineStage::Type::PrimaryDraw, WeakRef<ShaderProgram>())
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

	VectorGraphics::Get();
	VectorGraphics::SetInstanceContext(nvgCreate(1, viewId));
	bgfx::FrameBufferHandle fbh = bgfx::createFrameBuffer(fbAttachments.size(), fbAttachments.data(), false);
	bgfx::setViewRect(viewId, 0, 0, bgfx::BackbufferRatio::Equal);
	bgfx::setViewFrameBuffer(viewId, fbh);
	bgfx::setViewMode(viewId, bgfx::ViewMode::Sequential);

	std::string viewName = "NanoVG#" + std::to_string(s_InstanceCounter);
	s_InstanceCounter++;

	bgfx::setViewName(viewId, viewName.c_str());

	return PipelineStage::Data{ fbh, attachments };
}

void harmony::VectorGraphicsStage::PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	Ref<View> _view = view.lock();
	bgfx::setViewRect(viewId, 0, 0, _view->m_Width, _view->m_Height);
	nvgBeginFrame(VectorGraphics::GetNVGContext() , float(_view->m_Width), float(_view->m_Width), 1.0f);
}

void harmony::VectorGraphicsStage::PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	nvgEndFrame(VectorGraphics::GetNVGContext());
	bgfx::touch(viewId);
	PipelineStage::PostUpdate(registry, view, viewId);
}

void harmony::VectorGraphicsStage::Cleanup()
{
}


harmony::VectorPipeline::VectorPipeline() : Pipeline(PipelineHandle{ "VectorGraphicsPipeline" })
{
	AddPipelineStage<VectorGraphicsStage>();
}