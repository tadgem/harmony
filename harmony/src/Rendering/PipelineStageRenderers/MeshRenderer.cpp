#include "Rendering/PipelineStageRenderers/MeshRenderer.h"
#include "ECS/MeshComponent.h"
#include "ECS/MaterialComponent.h"
#include "ECS/TransformComponent.h"

harmony::MeshRenderer::MeshRenderer()
{
}

void harmony::MeshRenderer::Draw(entt::registry& scene, Ref<ShaderProgram> shader, bgfx::ViewId viewId)
{
	auto drawables = scene.view<MeshComponent, MaterialComponent, TransformComponent>();

	for (auto [e, mesh, material, transform] : drawables.each())
	{		
		// Fix this please.
		bool vbhValid = mesh.MeshHandle.m_VBH.idx <= 4096;
		bool ibhValid = mesh.MeshHandle.m_IBH.idx <= 4096;
		if (!vbhValid || !ibhValid)
		{
			continue;
		}
		material.Data.SetContainerUniforms();
		bgfx::setTransform(&transform.Model[0]);
		bgfx::setVertexBuffer(0, mesh.MeshHandle.m_VBH);
		bgfx::setIndexBuffer(mesh.MeshHandle.m_IBH);
		bgfx::submit(viewId, shader->m_Handle);
		
	}
}
