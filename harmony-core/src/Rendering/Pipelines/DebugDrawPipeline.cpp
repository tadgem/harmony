#include "Rendering/Pipelines/DebugDrawPipeline.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Core/MathsUtils.h"
#include "Core/Input.h"
#include "Core/Log.hpp"

harmony::DebugDrawStage::DebugDrawStage(GfxDebug::Channel channel) : PipelineDrawStage("DebugDrawStage", PipelineDrawStage::Type::PrimaryDraw, WeakRef<ShaderProgram>(), WeakRef<PipelineStageRenderer>()), m_Channel(channel)
{
}

harmony::PipelineDrawStage::Data harmony::DebugDrawStage::Init(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	auto data = PipelineDrawStage::Init(registry, view, viewId);
	Ref<View> _view = view.lock();

	p_DebugRenderers.emplace(_view->m_Name, GfxDebug::Get()->AddViewChannel(m_Channel));
	
	return data;
}

void harmony::DebugDrawStage::PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	Ref<View> _view = view.lock();
	bgfx::setViewClear(viewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000, 1.0f);
	bgfx::setViewTransform(viewId, &_view->m_View[0], &_view->m_Projection[0]);
	bgfx::setViewRect(viewId, 0, 0, _view->m_Width, _view->m_Height);
	p_DebugRenderers[_view->m_Name]->begin(viewId, true);
}

void harmony::DebugDrawStage::PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	p_DebugRenderers[view.lock()->m_Name]->end();
	PipelineDrawStage::PostUpdate(registry, view, viewId);

}

void harmony::DebugDrawStage::Cleanup(WeakRef<View> view, bgfx::ViewId viewId)
{
	Ref<View> _view = view.lock();
	if (p_DebugRenderers.find(_view->m_Name) == p_DebugRenderers.end())
	{
		return;
	}

	DebugDrawEncoder* debugEncoder = p_DebugRenderers[_view->m_Name];
	GfxDebug::Get()->RemoveViewChannel(m_Channel, debugEncoder);
	p_DebugRenderers.erase(_view->m_Name);
}


harmony::DebugDrawPipeline::DebugDrawPipeline(GfxDebug::Channel channel) : Pipeline(PipelineHandle("DebugDrawPipline"), Pipeline::Type::ScreenSpace)
{
	AddPipelineStage<DebugDrawStage>(channel);
}
