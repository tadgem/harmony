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
		CubeMeshProgramComponent(){}
		virtual void Init() override
		{
			Program* app = Program::Get();
			m_Program = app->m_Renderer.LoadShader("sample surface", "vs_cubes", "fs_cubes");
			auto prog = m_Program.lock();

			m_Cube = CreateRef<Cube>(1.0f);
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
		Ref<Cube> m_Cube;
	};

	class ModelProgramComponent : public ProgramComponent
	{
	public:
		ModelProgramComponent(const std::string& modelPath);

		virtual void Init() override
		{
			Program* app = Program::Get();
			m_Program = app->m_Renderer.LoadShader("sample surface", "vs_cubes", "fs_cubes");
			auto prog = m_Program.lock();

			auto modelAsset = app->m_AssetManager.LoadAssetFromPath<Model>(p_ModelPath);
			auto modelWr = modelAsset[0];
			auto model = modelWr.lock();

			
			for (int i = 0; i < model->m_Meshes.size(); i++)
			{
				m_MeshHandles.emplace_back(app->m_Renderer.SubmitMeshToGPU(model->m_Meshes[i]));
			}
			// m_MeshHandle = app->m_Renderer.SubmitMeshToGPU(m_Cube);

			m_CameraPosition = glm::vec3(0.0f, 0.0f, -35.0f);
			m_Model = glm::mat4(1.0);
			m_View = glm::mat4(1.0);
			m_View = glm::lookAt(m_CameraPosition, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			m_Projection = glm::perspectiveFov(glm::radians(80.0f), 1280.0f, 720.0f, 0.1f, 300.0f);

			m_MVPHandle = bgfx::createUniform("u_mtx", bgfx::UniformType::Mat4);


		}

		virtual void Update() override
		{
			if (ImGui::Begin("ModelComponent"))
			{
				ImGui::SliderFloat3("Camera Position", &m_CameraPosition[0], -100, 100);
			}
			ImGui::End();
		}

		virtual void Render() override
		{
			uint64_t state = BGFX_STATE_DEFAULT;
			m_MVP = m_Projection * m_View * m_Model;
			m_View = glm::lookAt(m_CameraPosition, m_CameraPosition + glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0f, 1.0f, 0.0f));
			bgfx::setViewRect(0, 0, 0, uint16_t(1280), uint16_t(720));
			bgfx::touch(0);
			bgfx::setState(state, 0u);
			bgfx::setViewTransform(0, glm::value_ptr(m_View), glm::value_ptr(m_Projection));
			bgfx::setTransform(glm::value_ptr(m_Model));
			bgfx::setUniform(m_MVPHandle, glm::value_ptr(m_MVP));
			for (int i = 0; i < m_MeshHandles.size(); i++)
			{
				bgfx::setVertexBuffer(0, m_MeshHandles[i].m_VBH);
				bgfx::setIndexBuffer(m_MeshHandles[i].m_IBH);
				bgfx::submit(0, m_Program.lock()->m_Handle, 1, BGFX_DISCARD_NONE);
			}
		}

		glm::vec3 m_CameraPosition;
		glm::mat4 m_Model;
		glm::mat4 m_View;
		glm::mat4 m_Projection;
		glm::mat4 m_MVP;
		bgfx::UniformHandle m_MVPHandle;
		WeakRef<ShaderProgram> m_Program;

		std::vector<BGFXMeshHandle> m_MeshHandles;

	private:
		const std::string p_ModelPath;


		// Inherited via ProgramComponent
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

	};
	ModelProgramComponent::ModelProgramComponent(const std::string& modelPath) : p_ModelPath(modelPath)
	{
		harmony::log::info("Loaded model at path : ", p_ModelPath);
	}
};
int main()
{
	using namespace harmony;
	Program app("Harmony Sample Base");
	app.m_AssetManager.AddAssetFactory(GetTypeHash<Model>(), CreateRef<AssimpModelAssetFactory>());
	auto modelComponent = app.AddProgramComponent<ModelProgramComponent>("sponza/sponza.obj");
	app.Init();

	app.Run([&]()
	{
		
	});
}