#include "DebugDrawPipeline.h"

harmony::DebugDrawStage::DebugDrawStage() : PipelineStage(PipelineStage::Type::Draw, WeakRef<ShaderProgram>())
{
}

void harmony::DebugDrawStage::Init(entt::registry& registry, WeakRef<View> view)
{
	PipelineStage::Init(registry, view);
	ddInit();
}

void harmony::DebugDrawStage::PreUpdate(entt::registry& registry, WeakRef<View> view)
{
	Ref<View> _view = view.lock();
	bgfx::setViewTransform(m_ViewId, &_view->m_View[0], &_view->m_Projection[0]);
	bgfx::setViewRect(m_ViewId, 0, 0, _view->m_Width, _view->m_Height);
	DebugDraw.begin(m_ViewId);
}

void harmony::DebugDrawStage::PostUpdate(entt::registry& registry, WeakRef<View> view)
{
	DebugDraw.end();
}

void harmony::DebugDrawStage::Cleanup()
{
	ddShutdown();
}

harmony::DebugDrawPipeline::DebugDrawPipeline() : Pipeline(PipelineHandle::New("DebugDrawPipline"))
{
	AddPipelineStage<DebugDrawStage>();
}
