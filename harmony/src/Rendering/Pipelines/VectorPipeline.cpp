#include "Rendering/Pipelines/VectorPipeline.h"

void harmony::VectorGraphicsStage::Init(entt::registry& registry)
{
}

void harmony::VectorGraphicsStage::Render(entt::registry& registry)
{
}

void harmony::VectorGraphicsStage::Cleanup()
{
}

bgfx::FrameBufferHandle harmony::VectorGraphicsStage::GetStageFinalFramebuffer()
{
	return bgfx::FrameBufferHandle();
}
