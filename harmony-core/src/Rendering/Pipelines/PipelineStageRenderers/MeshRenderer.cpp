#include <optick.h>
#include "Rendering/Pipelines/PipelineStageRenderers/MeshRenderer.h"
#include "ECS/MeshComponent.h"
#include "ECS/MaterialComponent.h"
#include "ECS/TransformComponent.h"

harmony::MeshRenderer::MeshRenderer() : PipelineStageRenderer("MeshRenderer")
{
}

void harmony::MeshRenderer::Draw(entt::registry &scene, Ref<ShaderProgram> shader, bgfx::ViewId viewId)
{
	OPTICK_EVENT();
	auto drawables = scene.view<MeshComponent, MaterialComponent, TransformComponent>();
	bool hasDrawn = false;
	for (auto [e, mesh, material, transform]: drawables.each())
	{
		// Fix this please.
		bool vbhValid = mesh.MeshHandle.m_VBH.idx <= 8192;
		bool ibhValid = mesh.MeshHandle.m_IBH.idx <= 8192;

		if (!vbhValid || !ibhValid)
		{
			continue;
		}

		if (shader->m_Name != material.Data.m_ShaderName)
		{
			continue;
		}

		material.Data.SetOverrides();

		auto _state = 0
					  | BGFX_STATE_WRITE_RGB
					  | BGFX_STATE_WRITE_A
					  | BGFX_STATE_WRITE_Z
					  | BGFX_STATE_DEPTH_TEST_LEQUAL;
		bgfx::setState(_state);
		bgfx::setTransform(&transform.Model[0]);
		bgfx::setVertexBuffer(0, mesh.MeshHandle.m_VBH);
		bgfx::setIndexBuffer(mesh.MeshHandle.m_IBH);
		bgfx::submit(viewId, shader->m_Handle);

		hasDrawn = true;
	}

	if (!hasDrawn)
	{
		bgfx::touch(viewId);
	}
}
