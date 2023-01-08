#include "Rendering/PostProcessStage.h"
#include "Rendering/View.h"
#include "Rendering/Shapes.h"
harmony::PostProcessStage::PostProcessStage(const std::string& name, Type stageType, WeakRef<ShaderProgram> shader, WeakRef<PipelineStageRenderer> stageRenderer, Attachment::Type attachments) : PipelineStage(name, stageType, attachments, shader, stageRenderer)
{
}

void harmony::PostProcessStage::PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId, PipelineStage::Data data)
{
	
}

void harmony::PostProcessStage::PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId, PipelineStage::Data data)
{
	Ref<ShaderProgram>			s = p_Shader.lock();
	for (Ref<ShaderDataSource>& source : p_DataSources)
	{
		source->OnPostUpdate(registry, s);
	}

	// set colour and depth attachment
	bgfx::UniformHandle colourAttachmentUniform	= s->m_Uniforms[0].BgfxHandle;
	bgfx::UniformHandle depthAttachmentUniform; 
	bool hasDepth = false;
	if (s->m_Uniforms.size() > 1)
	{
		depthAttachmentUniform = s->m_Uniforms[1].BgfxHandle;
		hasDepth = true;
	}

	Attachment::Type colourType = data.GetColorType();
	Attachment::Type depthType = data.GetDepthType();

	if (colourType == Attachment::Unknown)
	{
		return;
	}

	for (Ref<ShaderDataSource>& source : p_DataSources)
	{
		source->OnPreUpdate(registry, s);
	}

	Ref<View> v = view.lock();

	bgfx::setViewClear(viewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000, 1.0f);
	bgfx::setViewRect(viewId, 0, 0, v->m_Width, v->m_Height);

	bgfx::TextureHandle colourAttachment	= data.m_Attachments[colourType].m_Handle;
	bgfx::setTexture(0, colourAttachmentUniform, colourAttachment);

	if (hasDepth && depthType != Attachment::Unknown)
	{
		bgfx::TextureHandle depthAttachment		= data.m_Attachments[depthType].m_Handle;
		if (depthAttachment.idx <= 4096)
		{
			bgfx::setTexture(1, depthAttachmentUniform, depthAttachment);
		}
	}

	ScreenSpaceQuad(v->m_Width, v->m_Height);
	bgfx::submit(viewId, s->m_Handle);
}
