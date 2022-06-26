#include "Rendering/Pipelines/TexturedMeshPipeline.h"
#include "Rendering/BuiltinShaders.h"
#include "ECS/MaterialComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/TransformComponent.h"
#include "Core/Program.h"

void harmony::TextureMeshStage::Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
    HARMONY_PROFILE_FUNCTION()
    PipelineStage::Init(registry, view, handle);

    p_Shader = Program::Get()->m_Renderer.GetShader("TexturedMesh");
}

void harmony::TextureMeshStage::PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
    HARMONY_PROFILE_FUNCTION()
    PipelineStage::PreUpdate(registry, view, handle);
    auto drawables = registry.view<MeshComponent, MaterialComponent, TransformComponent>();
    Ref<ShaderProgram> pipelineShader = p_Shader.lock();

    for (auto& [e, mesh, material, transform] : drawables.each())
    {
        if (material.Data.m_Shader.lock() == pipelineShader)
        {
            WeakRef<Mesh> meshAsset = Program::Get()->m_AssetManager.GetAsset<Mesh>(mesh.MeshAsset);
            
            if (meshAsset.expired())
            {
                harmony::log::error("Cannot render mesh, as it is not loaded : {}", mesh.MeshAsset.Path);
                continue;
            }

            BGFXMeshHandle handle = meshAsset.lock()->m_Handle;

            material.Data.SetContainerUniforms();
            bgfx::setTransform(&transform.Model[0]);
            bgfx::setVertexBuffer(0, handle.m_VBH);
            bgfx::setIndexBuffer(handle.m_IBH);
            bgfx::submit(m_ViewId, pipelineShader->m_Handle);
        }
    }
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
