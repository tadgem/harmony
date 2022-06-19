#include "Rendering/Pipelines/TexturedMeshPipeline.h"

void harmony::TextureMeshStage::Init(entt::registry& registry)
{
}

void harmony::TextureMeshStage::Render(entt::registry& registry)
{
}

void harmony::TextureMeshStage::Cleanup()
{
}

bgfx::FrameBufferHandle harmony::TextureMeshStage::GetStageFinalFramebuffer()
{
    return bgfx::FrameBufferHandle();
}
