//
// Created by liam_ on 6/24/2023.
//
#include <Rendering/Shaders/ShaderDataSources/SkyDataSource.h>
#include <Rendering/Shapes.h>
#include "Rendering/Pipelines/PipelineStages/SkyStage.h"
#include "Rendering/Pipelines/PipelineStageRenderer.h"
#include "Rendering/Pipelines/PipelineStageRenderers/SubDivScreenQuadRenderer.h"
#include "Rendering/View.h"

harmony::SkyStage::SkyStage(WeakRef<ShaderProgram> shaderProgram) : PipelineStage("SkyStage",
																				  PipelineStage::Type::PrimaryDraw,
																				  {AttachmentType::RGBA16F},
																				  shaderProgram,
																				  CreateRef<SubDivScreenQuadRenderer>(
																						  64, 64))
{
	p_Src = CreateRef<SkyDataSource>();
	AddShaderDataSource(p_Src);
}

void harmony::SkyStage::PreUpdate(entt::registry &registry, harmony::WeakRef<harmony::View> view, bgfx::ViewId viewId)
{
	auto v = view.lock();
	bgfx::setViewTransform(viewId, &v->m_View[0], &v->m_Projection[0]);
	bgfx::setViewRect(viewId, 0, 0, v->m_Width, v->m_Height);

	for (auto src: p_DataSources)
	{
		src.lock()->OnPreUpdate(registry, p_Shader.lock());
	}
	p_Renderer->Draw(registry, p_Shader.lock(), viewId);
}

void
harmony::SkyStage::PostUpdate(entt::registry &registry, harmony::WeakRef<harmony::View> view, bgfx::ViewId viewId)
{
	for (auto src: p_DataSources)
	{
		src.lock()->OnPostUpdate(registry, p_Shader.lock());
	}
}

void harmony::SkyStage::Cleanup(harmony::WeakRef<harmony::View> view, bgfx::ViewId viewId)
{
	PipelineStage::Cleanup(view, viewId);
}

void harmony::SkyStage::AddShaderDataSource(harmony::WeakRef<harmony::ShaderDataSource> source)
{
	PipelineStage::AddShaderDataSource(source);
}

nlohmann::json harmony::SkyStage::Serialize()
{
	return PipelineStage::Serialize();
}

void harmony::SkyStage::Deserialize(nlohmann::json json)
{
	PipelineStage::Deserialize(json);
}

