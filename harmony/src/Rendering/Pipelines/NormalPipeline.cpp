#include "Rendering/Pipelines/NormalPipeline.h"
#include "Rendering/BuiltinShaders.h"
#include "ECS/MaterialComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/TransformComponent.h"
#include "Core/Program.h"

harmony::NormalStage::NormalStage() : PipelineStage(PipelineStage::Type::PrimaryDraw, WeakRef<ShaderProgram>())
{
}

void harmony::NormalStage::Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
    HARMONY_PROFILE_FUNCTION()
    PipelineStage::Init(registry, view, handle);

    p_Shader = Program::Get()->m_Renderer.GetShader("Normal");
    bgfx::setViewName(m_ViewId, "Normal");
}

void harmony::NormalStage::PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
    HARMONY_PROFILE_FUNCTION()
    PipelineStage::PreUpdate(registry, view, handle);
    bgfx::setViewClear(m_ViewId, BGFX_CLEAR_COLOR, 0x00000000);
    auto drawables = registry.view<MeshComponent, MaterialComponent, TransformComponent>();
    Ref<ShaderProgram> pipelineShader = p_Shader.lock();

    for (auto [e, mesh, material, transform] : drawables.each())
    {
        if (material.Data.m_Shader.lock() == pipelineShader)
        {
            bool vbhValid = bgfx::isValid(mesh.MeshHandle.m_VBH);
            bool ibhValid = bgfx::isValid(mesh.MeshHandle.m_IBH);
            if (!vbhValid || !ibhValid)
            {
                continue;
            }
            material.Data.SetContainerUniforms();
            bgfx::setTransform(&transform.Model[0]);
            bgfx::setVertexBuffer(0, mesh.MeshHandle.m_VBH);
            bgfx::setIndexBuffer(mesh.MeshHandle.m_IBH);
            bgfx::submit(m_ViewId, pipelineShader->m_Handle);
        }
    }
}

void harmony::NormalStage::PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle)
{
    if (!p_RunPreFrame)
    {
        return;
    }
    PipelineStage::PostUpdate(registry, view, handle);
}

void harmony::NormalStage::Cleanup()
{
}

harmony::NormalPipeline::NormalPipeline() : Pipeline(PipelineHandle::New("NormalPipeline"))
{
    AddPipelineStage<NormalStage>();
}