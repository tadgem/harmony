#include "Rendering/Pipelines/PostProcessStage.h"
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
	for (WeakRef<ShaderDataSource>& source : p_DataSources)
	{
		if (source.expired()) continue;
		auto src = source.lock();
		src->OnPostUpdate(registry, s);
	}
	bool hasDepth = false;
	bool hasParams = false;
	int numSamplers = 0;

	bgfx::UniformHandle colourAttachmentUniform;
	bgfx::UniformHandle depthAttachmentUniform;
	bgfx::UniformHandle postProcessParamsUniform;

	for (int i = 0; i < s->m_Uniforms.size(); i++)
	{
		if (s->m_Uniforms[i].Type == bgfx::UniformType::Vec4)
		{
			hasParams = true;
			postProcessParamsUniform = s->m_Uniforms[i].BgfxHandle;
		}
		if (s->m_Uniforms[i].Type == bgfx::UniformType::Sampler)
		{
			if (numSamplers == 0)
			{
				colourAttachmentUniform = s->m_Uniforms[i].BgfxHandle;
				numSamplers++;
				continue;
			}
			if (numSamplers == 1)
			{
				hasDepth = true;
				numSamplers++;
				depthAttachmentUniform = s->m_Uniforms[i].BgfxHandle;
			}

		}
	}

	Attachment::Type colourType = data.GetColorType();
	Attachment::Type depthType = data.GetDepthType();

	if (colourType == Attachment::Unknown)
	{
		return;
	}

	for (WeakRef<ShaderDataSource>& source : p_DataSources)
	{
		if (source.expired()) continue;
		auto src = source.lock();
		src->OnPreUpdate(registry, s);
	}

	Ref<View> v = view.lock();

	bgfx::setViewClear(viewId, BGFX_CLEAR_COLOR, 0x00000000, 1.0f);
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
	glm::vec4 params(v->m_Width, v->m_Height, 0, 0);
	if (hasParams)
	{
		bgfx::setUniform(postProcessParamsUniform, &params[0]);
	}
	ScreenSpaceQuad(v->m_Width, v->m_Height);
	bgfx::submit(viewId, s->m_Handle);
}
