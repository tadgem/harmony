#include "Rendering/Pipelines/DebugDrawPipeline.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Core/MathsUtils.h"
#include "Core/Input.h"
harmony::DebugDrawStage::DebugDrawStage() : PipelineStage(PipelineStage::Type::PrimaryDraw, WeakRef<ShaderProgram>())
{
	p_RunPreFrame = false;
}

void harmony::DebugDrawStage::Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	PipelineStage::Init(registry, view, handle);
	ddInit(&p_Allocator);
	DebugDraw = new DebugDrawEncoder();
	bgfx::setViewName(m_ViewId, "Debug Draw");
}

void harmony::DebugDrawStage::PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	PipelineStage::PreUpdate(registry, view, handle);
	DebugDraw->begin(m_ViewId, false);
	DebugDraw->setColor(0xfffffff);
	DebugDraw->drawGrid(Axis::Enum::Y, bx::Vec3(0.0f, -2.0f, 0.0f), 1000);
	DebugDraw->drawAxis(0.0f, 1.0f, 0.0f, 5.0f);
	p_RunPreFrame = true;
}

void harmony::DebugDrawStage::PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
	if (!p_RunPreFrame)
	{
		return;
	}
	DebugDraw->end();
	bgfx::touch(m_ViewId);
	PipelineStage::PostUpdate(registry, view, handle);

}

void harmony::DebugDrawStage::Cleanup()
{
	ddShutdown();
}

harmony::DebugDrawPipeline::DebugDrawPipeline() : Pipeline(PipelineHandle::New("DebugDrawPipline"))
{
	AddPipelineStage<DebugDrawStage>();
}

