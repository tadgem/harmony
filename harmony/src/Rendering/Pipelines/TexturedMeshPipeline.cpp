#include "Rendering/Pipelines/TexturedMeshPipeline.h"

void harmony::TextureMeshStage::Init(entt::registry& registry, WeakRef<View> view)
{
}

void harmony::TextureMeshStage::PreUpdate(entt::registry& registry, WeakRef<View> view)
{
}

void harmony::TextureMeshStage::PostUpdate(entt::registry& registry, WeakRef<View> view)
{
}

void harmony::TextureMeshStage::Cleanup()
{
}

bgfx::FrameBufferHandle harmony::TextureMeshStage::GetStageFinalFramebuffer()
{
    return bgfx::FrameBufferHandle();
}
