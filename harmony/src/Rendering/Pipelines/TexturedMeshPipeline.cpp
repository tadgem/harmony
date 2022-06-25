#include "Rendering/Pipelines/TexturedMeshPipeline.h"

void harmony::TextureMeshStage::Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
    PipelineStage::Init(registry, view, handle);
}

void harmony::TextureMeshStage::PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
    PipelineStage::PreUpdate(registry, view, handle);

}

void harmony::TextureMeshStage::PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
}

void harmony::TextureMeshStage::Cleanup()
{
}

bgfx::FrameBufferHandle harmony::TextureMeshStage::GetStageFinalFramebuffer()
{
    return bgfx::FrameBufferHandle();
}
