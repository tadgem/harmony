#include "Rendering/PostProcessStage.h"
#include "Rendering/View.h"
harmony::PostProcessStage::PostProcessStage(const std::string& name, Type stageType, WeakRef<ShaderProgram> shader, WeakRef<PipelineStageRenderer> stageRenderer, Attachment::Type attachments) : PipelineStage(name, stageType, attachments, shader, stageRenderer)
{
}

void harmony::PostProcessStage::PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId, PipelineStage::Data data)
{
	Ref<View> _view = view.lock();

	bgfx::setViewClear(viewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000, 1.0f);
	bgfx::setViewTransform(viewId, &_view->m_View[0], &_view->m_Projection[0]);
	bgfx::setViewRect(viewId, 0, 0, _view->m_Width, _view->m_Height);

	Ref<ShaderProgram>			pipelineShader = p_Shader.lock();
	Ref<PipelineStageRenderer>	pipelineRenderer = p_Renderer.lock();

	for (Ref<ShaderDataSource>& source : p_DataSources)
	{
		source->OnPreUpdate(registry, pipelineShader);
	}

	// TODO how do we pass data here, should this be a source?
}

void harmony::PostProcessStage::PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId, PipelineStage::Data data)
{
	Ref<ShaderProgram>			pipelineShader = p_Shader.lock();
	for (Ref<ShaderDataSource>& source : p_DataSources)
	{
		source->OnPostUpdate(registry, pipelineShader);
	}
}
