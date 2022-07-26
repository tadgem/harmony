#include "Rendering/Pipelines/VectorPipeline.h"
#include "Core/Program.h"
harmony::VectorGraphicsStage::VectorGraphicsStage() : PipelineStage("VectorGraphicsStage", PipelineStage::Type::PrimaryDraw, WeakRef<ShaderProgram>())
{
}

void harmony::VectorGraphicsStage::Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
    HARMONY_PROFILE_FUNCTION()

    p_Shader = Program::Get()->m_Renderer.GetShader("NanoVG");
    
	Ref<View> _view = view.lock();

	p_Attachments.emplace_back(
		bgfx::createTexture2D(
				_view->m_Width
			,	_view->m_Height
			, false
			, 1
			, bgfx::TextureFormat::BGRA8
			, BGFX_TEXTURE_RT
		));

	m_HasHDRAttachment = false;
	m_HasDepthAttachment = false;

	VectorGraphics::Get();
	VectorGraphics::SetInstanceContext(nvgCreate(1, m_ViewId));
	p_FrameBufferHandle = bgfx::createFrameBuffer(p_Attachments.size(), p_Attachments.data(), false);
	bgfx::setViewRect(m_ViewId, 0, 0, bgfx::BackbufferRatio::Equal);
	bgfx::setViewFrameBuffer(m_ViewId, p_FrameBufferHandle);
	bgfx::setViewMode(m_ViewId, bgfx::ViewMode::Sequential);
    bgfx::setViewName(m_ViewId, "NanoVG");
}

void harmony::VectorGraphicsStage::PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	Ref<View> _view = view.lock();
	bgfx::setViewRect(m_ViewId, 0, 0, _view->m_Width, _view->m_Height);
	nvgBeginFrame(VectorGraphics::GetNVGContext() , float(_view->m_Width), float(_view->m_Width), 1.0f);
}

void harmony::VectorGraphicsStage::PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	nvgEndFrame(VectorGraphics::GetNVGContext());
	bgfx::touch(m_ViewId);
	PipelineStage::PostUpdate(registry, view, handle);
}

void harmony::VectorGraphicsStage::Cleanup()
{
}

bgfx::FrameBufferHandle harmony::VectorGraphicsStage::GetStageFinalFramebuffer()
{
	return bgfx::FrameBufferHandle();
}

harmony::VectorPipeline::VectorPipeline() : Pipeline(PipelineHandle::New("VectorGraphicsPipeline"))
{
	AddPipelineStage<VectorGraphicsStage>();
}

bgfx::TextureHandle harmony::VectorPipeline::GetFinalImage()
{
	return nvgGetFramebufferTexture(VectorGraphics::GetNVGContext());
}
