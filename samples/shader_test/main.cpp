#include "Core/Program.h"
#include "Core/Log.hpp"
#include "Rendering/Shapes.h"
#include "AssimpModelAssetFactory.h"
#include "ImGui/ImGuiFileDialog.h"
#include "ImGui/imgui.h"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtc/type_ptr.hpp"


#include <bx/timer.h>
#include <bx/math.h>

namespace harmony {
	class CubeMeshProgramComponent : public ProgramComponent
	{
	public:
		CubeMeshProgramComponent() : m_Cube(1.0f) {}
		virtual void Init() override
		{
			Program* app = Program::Get();
			m_Program = app->m_Renderer.LoadShader("sample surface", "vs_cubes", "fs_cubes");
			auto prog = m_Program.lock();

			m_Cube = Cube(1.0f);
			m_MeshHandle = app->m_Renderer.SubmitMeshToGPU(m_Cube);

			m_CameraPosition = glm::vec3(0.0f, 0.0f, -35.0f);
			m_Model = glm::mat4(1.0);
			m_View = glm::mat4(1.0);
			m_View = glm::lookAt(m_CameraPosition, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			m_Projection = glm::perspectiveFov(glm::radians(80.0f), 1280.0f, 720.0f, 0.1f, 300.0f);

			m_MVPHandle = bgfx::createUniform("u_mtx", bgfx::UniformType::Mat4);


		}
		virtual void Update() override
		{
			if (ImGui::Begin("CubeMeshComponent"))
			{
				ImGui::SliderFloat3("Camera Position", &m_CameraPosition[0], -35, 35);
			}
			ImGui::End();
		}
		virtual void Render() override
		{
			uint64_t state = BGFX_STATE_DEFAULT ;
			m_MVP = m_Projection * m_View * m_Model;
			m_View = glm::lookAt(m_CameraPosition, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			bgfx::setViewRect(0, 0, 0, uint16_t(1280), uint16_t(720));
			bgfx::touch(0);
			bgfx::setState(state, 0u);
			bgfx::setViewTransform(0, glm::value_ptr(m_View), glm::value_ptr(m_Projection));
			bgfx::setTransform(glm::value_ptr(m_Model));
			bgfx::setVertexBuffer(0, m_MeshHandle.m_VBH);
			bgfx::setIndexBuffer(m_MeshHandle.m_IBH);
			bgfx::setUniform(m_MVPHandle, glm::value_ptr(m_MVP));
			bgfx::submit(0, m_Program.lock()->m_Handle, 1, BGFX_DISCARD_NONE);
		}
		virtual void Cleanup() override
		{
		}
		virtual nlohmann::json ToJson() override
		{
			return nlohmann::json();
		}
		virtual void FromJson(const nlohmann::json& json) override
		{
		}
		glm::vec3 m_CameraPosition;
		glm::mat4 m_Model;
		glm::mat4 m_View;
		glm::mat4 m_Projection;
		glm::mat4 m_MVP;
		bgfx::UniformHandle m_MVPHandle;
		WeakRef<ShaderProgram> m_Program;
		BGFXMeshHandle m_MeshHandle;
		Cube m_Cube;
	};
};
int main()
{
	harmony::Program app("Harmony Sample Base");
	auto cubeComponent = app.AddProgramComponent<harmony::CubeMeshProgramComponent>();
	app.Init();

	app.Run([&]()
	{
		
	});
}