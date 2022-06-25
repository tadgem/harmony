#include "Rendering/Pipelines/VectorPipeline.h"

void harmony::VectorGraphicsStage::Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
}

void harmony::VectorGraphicsStage::PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
}

void harmony::VectorGraphicsStage::PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
}

void harmony::VectorGraphicsStage::Cleanup()
{
}

bgfx::FrameBufferHandle harmony::VectorGraphicsStage::GetStageFinalFramebuffer()
{
	return bgfx::FrameBufferHandle();
}
