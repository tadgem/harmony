#include "Core/Program.h"
#include "Core/Log.hpp"
#include "Rendering/Shapes.h"
#include "ImGui/ImGuiFileDialog.h"
#include "ImGui/imgui.h"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtc/type_ptr.hpp"


#include <bx/timer.h>
#include <bx/math.h>
int main()
{
	harmony::Program app("Harmony Sample Base");
	app.Init();

	auto handle = app.m_Renderer.LoadShader("sample surface", "vs_cubes", "fs_cubes");
	harmony::Cube cube(1.0f);
	auto meshHandle = app.m_Renderer.SubmitMeshToGPU(cube);

	uint64_t state = 0
		| (true ? BGFX_STATE_WRITE_R : 0)
		| (true ? BGFX_STATE_WRITE_G : 0)
		| (true ? BGFX_STATE_WRITE_B : 0)
		| (true ? BGFX_STATE_WRITE_A : 0)
		| BGFX_STATE_WRITE_Z
		| BGFX_STATE_DEPTH_TEST_LESS
		;

	app.Run([&]()
	{
		if (ImGui::Begin("Sample"))
		{
			//ImGui::SliderFloat3("Cam position", glm::value_ptr(cameraPosition), -100.0f, 100.0f);
		}
		ImGui::End();
		float time = (float)((bx::getHPCounter()) / double(bx::getHPFrequency()));

		const bx::Vec3 at = { 0.0f, 0.0f,   0.0f };
		const bx::Vec3 eye = { 0.0f, 0.0f, -35.0f };

		// Set view and projection matrix for view 0.
		{
			float view[16];
			bx::mtxLookAt(view, eye, at);

			float proj[16];
			bx::mtxProj(proj, 60.0f, float(1280) / float(720), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
			bgfx::setViewTransform(0, view, proj);

			// Set view 0 default viewport.
			bgfx::setViewRect(0, 0, 0, uint16_t(1280), uint16_t(720));
		}

		for (uint32_t yy = 0; yy < 11; ++yy)
		{
			for (uint32_t xx = 0; xx < 11; ++xx)
			{
				float mtx[16];
				bx::mtxRotateXY(mtx, time + xx * 0.21f, time + yy * 0.37f);
				mtx[12] = -15.0f + float(xx) * 3.0f;
				mtx[13] = -15.0f + float(yy) * 3.0f;
				mtx[14] = 0.0f;

				// Set model matrix for rendering.
				bgfx::setTransform(mtx);

				// Set vertex and index buffer.
				bgfx::setVertexBuffer(0, meshHandle.m_VBH);
				bgfx::setIndexBuffer(meshHandle.m_IBH);

				// Set render states.
				bgfx::setState(state);

				// Submit primitive for rendering to view 0.
				bgfx::submit(0, handle.lock()->m_Handle);
			}
		}
		// bgfx::dbgTextPrintf(0, 0, 0x0f, "Hello I am Some Text");
	});
}