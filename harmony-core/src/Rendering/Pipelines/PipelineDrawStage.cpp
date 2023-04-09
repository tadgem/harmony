#include "Rendering/Pipelines/PipelineDrawStage.h"
#include "Rendering/Pipelines/PipelineStageRenderer.h"
#include "Rendering/Renderer.h"
#include "Rendering/View.h"
#include "ECS/MaterialComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/TransformComponent.h"
#include "Core/Log.hpp"
harmony::PipelineDrawStage::PipelineDrawStage(const std::string& name, Type stageType, WeakRef<ShaderProgram> shader, WeakRef<PipelineStageRenderer> stageRenderer, Attachment::Type attachments) : PipelineStage(name, stageType , attachments, shader, stageRenderer)
{
}


void harmony::PipelineDrawStage::PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	Ref<View> _view = view.lock();
	bgfx::setViewTransform(viewId, &_view->m_View[0], &_view->m_Projection[0]);
	bgfx::setViewRect(viewId, 0, 0, _view->m_Width, _view->m_Height);

	Ref<ShaderProgram>			pipelineShader		= p_Shader.lock();
	Ref<PipelineStageRenderer>	pipelineRenderer	= p_Renderer.lock();

	for (WeakRef<ShaderDataSource>& source : p_DataSources)
	{
		if (source.expired()) continue;
		auto src = source.lock();
		src->OnPreUpdate(registry, pipelineShader);
	}
	// Per instance uniforms should be handled by material.
	pipelineRenderer->Draw(registry, pipelineShader, viewId);
}

void harmony::PipelineDrawStage::PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	Ref<ShaderProgram>			pipelineShader = p_Shader.lock();
	for (WeakRef<ShaderDataSource>& source : p_DataSources)
	{
		if (source.expired()) continue;
		auto src = source.lock();
		src->OnPostUpdate(registry, pipelineShader);
	}
}



