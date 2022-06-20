#include "EditorApplication.h"
#include "Core/Log.hpp"
#include "ImGui/ImGuiFileDialog.h"
#include "ImGui/imgui.h"
#include "Rendering/Model.h"
#include "AssimpModelAssetFactory.h"
#include "Assets/TextureAssetFactory.h"
#include "ECS/TransformSystem.h"
#include "ECS/TileMapSystemImGui.h"
#include "ImGui/icons_font_awesome.h"
#include "EditorUtils.hpp"
#include "Rendering/Pipelines/DebugDrawPipeline.h"
int main()
{
	using namespace harmony;
	Editor app;
	harmony::Renderer& renderer = app.m_Renderer;
	harmony::AssetManager& assetManager = app.m_AssetManager;

	renderer.CreatePipeline<harmony::DebugDrawPipeline>();
	assetManager.AddAssetFactory(CreateRef<AssimpModelAssetFactory>());
	assetManager.AddAssetFactory(CreateRef<TextureAssetFactory>());
	app.AddSystem<TransformSystem>();
	WeakRef<TileMapSystem> tileMapSystem = app.AddSystem<TileMapSystem>(app.m_AssetManager, app.m_Renderer);
	app.AddSystem<TileMapSystemImGui>(tileMapSystem.lock());
	app.Init();
	

	bool fileOpen = false;
	bool editUndo = false;
	bool viewDefault = false;
	bool createProjectWindow = false;
	bool createSceneWindow = false;
	
	std::string currentScenePath = "";
	unsigned int selectedScene = 0;
	char projectNameInput[64]{ "" };
	char projectPathInput[256]{ "" };
	char sceneNameInput[256]{ "" };
	auto callback = [&]()
	{
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Create Project"))
				{
					createProjectWindow = true;
				}
				if (ImGui::MenuItem("Open Project"))
				{
					ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenProject", "Choose Project", ".harmonyproj", ".");
				}
				if (ImGui::MenuItem("Save Project"))
				{
					app.SaveProject();
				}
				ImGui::MenuItem("Close Project");
				ImGui::Separator();
				if (ImGui::MenuItem("New Scene"))
				{
					createSceneWindow = true;
				}
				if (ImGui::MenuItem("Save Scene"))
				{
					ImGuiFileDialog::Instance()->OpenDialog("HarmonySaveScene", "Choose Scene", ".harmonyscene,.json", ".");
				}
				ImGui::EndMenu();
			}
		}
		ImGui::EndMainMenuBar();


		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_PassthruCentralNode;

		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(viewport->Size);
		ImGui::SetNextWindowViewport(viewport->ID);
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;


		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
		// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive, 
		// all active windows docked into it will lose their parent and become undocked.
		// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise 
		// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
		ImGui::Begin("DockSpace", nullptr, window_flags);
		ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
		ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		ImGui::End();

		if (ImGuiFileDialog::Instance()->Display("HarmonyOpenProject"))
		{
			// action if OK
			if (ImGuiFileDialog::Instance()->IsOk())
			{
				std::string filepath = ImGuiFileDialog::Instance()->GetFilePathName();
				app.LoadProject(filepath);
			}
			ImGuiFileDialog::Instance()->Close();
		}

		if (ImGuiFileDialog::Instance()->Display("HarmonySaveScene"))
		{
			// action if OK
			if (ImGuiFileDialog::Instance()->IsOk())
			{
				std::string filepath = ImGuiFileDialog::Instance()->GetFilePathName();
				app.SaveScene(filepath);
			}
			ImGuiFileDialog::Instance()->Close();
		}


		if (app.m_Project != nullptr)
		{
			std::string windowTitle = "Project Properties : " + app.m_Project->m_ProjectName;
			if (ImGui::Begin(windowTitle.c_str()))
			{
				std::string projectNameText = "Project Name : " + app.m_Project->m_ProjectName;
				ImGui::Text(projectNameText.c_str());
				std::string projectDirectoryText = "Project Path : " + app.m_Project->m_ProjectDirectory;
				ImGui::Text(projectDirectoryText.c_str());
				ImGui::Separator();
				auto sceneWr = app.GetActiveScene();
				if (!sceneWr.expired())
				{
					auto scene = sceneWr.lock();
					std::string sceneNameText = "Active Scene Name : " + scene->m_Name;
					std::string loadedScenePath = "Loaded Scene Path : " + currentScenePath;
					ImGui::Text(sceneNameText.c_str());
					ImGui::Text(loadedScenePath.c_str());
					ImGui::Separator();
				}
				if (app.m_Project->m_SerializedScenes.size() > 0)
				{
					if (ImGui::BeginCombo("Project Scenes", app.m_Project->m_SerializedScenes[selectedScene].c_str()))
					{
						for (int i = 0; i < app.m_Project->m_SerializedScenes.size(); i++)
						{
							if (ImGui::Selectable(app.m_Project->m_SerializedScenes[i].c_str()))
							{
								selectedScene = i;
							}
						}
						ImGui::EndCombo();
					}
					if (ImGui::Button("Load Scene"))
					{
						app.LoadScene(app.m_Project->m_SerializedScenes[selectedScene]);
						currentScenePath = app.m_Project->m_SerializedScenes[selectedScene];
					}

				}
			}
			ImGui::End();
		}

		if (createProjectWindow)
		{
			if (ImGui::Begin("Create Project"))
			{
				ImGui::InputText("Project Name", &projectNameInput[0], 64);
				ImGui::InputText("Project Path", &projectPathInput[0], 256);
				ImGui::Separator();
				if (ImGui::Button("Create Project"))
				{
					std::string projectName = std::string(projectNameInput);
					std::string projectPath = std::string(projectPathInput);
					app.CreateProject(projectName, projectPath);
					app.SaveProject();
					createProjectWindow = false;
				}
			}
			ImGui::End();
		}

		if (createSceneWindow)
		{
			if (ImGui::Begin("Create Scene"))
			{
				ImGui::InputText("Scene Name", &sceneNameInput[0], 256);
				if (ImGui::Button("Create"))
				{
					app.CreateScene(std::string(sceneNameInput));
					createSceneWindow = false;
				}
			}
			ImGui::End();
		}


	};
	app.Run(callback);
}