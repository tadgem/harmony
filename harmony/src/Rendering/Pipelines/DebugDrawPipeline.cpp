#include "Rendering/Pipelines/DebugDrawPipeline.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Core/MathsUtils.h"
#include "Core/Input.h"
harmony::DebugDrawStage::DebugDrawStage() : PipelineStage(PipelineStage::Type::PrimaryDraw, WeakRef<ShaderProgram>())
{
	Active = false;
	Active = false;
}

void harmony::DebugDrawStage::Init(entt::registry& registry, WeakRef<View> view)
{
	PipelineStage::Init(registry, view);
	ddInit(&p_Allocator);
	DebugDraw = new DebugDrawEncoder();
	bgfx::setViewName(m_ViewId, "Debug Draw");
}

void harmony::DebugDrawStage::PreUpdate(entt::registry& registry, WeakRef<View> view)
{
	bgfx::setViewClear(m_ViewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0);
	Ref<View> _view = view.lock();
	bgfx::setViewTransform(m_ViewId, &_view->m_View[0], &_view->m_Projection[0]);
	bgfx::setViewRect(m_ViewId, 0, 0, _view->m_Width, _view->m_Height);
	DebugDraw->begin(m_ViewId);
	Active = true;

	DebugDraw->drawGrid(Axis::Enum::Y, bx::Vec3(0.0f, -2.0f, 0.0f), 1000);
	DebugDraw->drawAxis(0.0f, 1.0f, 0.0f, 10.0f);
}

void harmony::DebugDrawStage::PostUpdate(entt::registry& registry, WeakRef<View> view)
{
	if (!Active)
	{
		return;
	}
	DebugDraw->end();
	bgfx::touch(m_ViewId);
	Active = false;

}

void harmony::DebugDrawStage::Cleanup()
{
	ddShutdown();
}

harmony::DebugDrawPipeline::DebugDrawPipeline() : Pipeline(PipelineHandle::New("DebugDrawPipline"))
{
	AddPipelineStage<DebugDrawStage>();
}

