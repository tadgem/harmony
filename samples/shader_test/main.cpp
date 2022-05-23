#include "Core/Program.h"
#include "Core/Log.hpp"
#include "Rendering/Shapes.h"
#include "ImGui/ImGuiFileDialog.h"
#include "ImGui/imgui.h"

int main()
{
	harmony::Program app("Harmony Sample Base");
	app.Init();

	auto handle = app.m_Renderer.LoadShader("sample surface", "vs_cubes", "fs_cubes");
	harmony::Cube cube(1.0f);
	auto meshHandle = app.m_Renderer.SubmitMeshToGPU(cube);
	app.Run([&]()
	{
		if (ImGui::Begin("Sample"))
		{
		}
		ImGui::End();
		bgfx::setViewTransform(0, &glm::mat4(1.0)[0], &glm::mat4(1.0)[0]);
		bgfx::setVertexBuffer(0, meshHandle.m_VBH);
		bgfx::setIndexBuffer(meshHandle.m_IBH);
		bgfx::submit(0, handle.lock()->m_Handle);

		// bgfx::dbgTextPrintf(0, 0, 0x0f, "Hello I am Some Text");
	});
}