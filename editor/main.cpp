#include "EditorApplication.h"
#include "Core/Log.hpp"
#include "ImGui/ImGuiFileDialog.h"
#include "ImGui/imgui.h"
#include "Rendering/Model.h"
#include "AssimpModelAssetFactory.h"
#include "Assets/TextureAssetFactory.h"
#include "ECS/TransformSystem.h"
#include "ECS/TileMapSystem.h"
#include "ImGui/icons_font_awesome.h"
#include "EditorUtils.hpp"
int main()
{
	using namespace harmony;
	Editor app;
	app.m_AssetManager.AddAssetFactory(CreateRef<AssimpModelAssetFactory>());
	app.m_AssetManager.AddAssetFactory(CreateRef<TextureAssetFactory>());
	app.AddSystem<TransformSystem>();
	app.AddSystem<TileMapSystem>();
	app.Init();
	
	auto imageAssetsRefCollection = app.m_AssetManager.LoadAsset<Texture>("dungeon.png");

	WeakRef<Texture> tex = GetDerivedRef<Asset, Texture>(imageAssetsRefCollection[0]);
	app.m_Renderer.SubmitTextureToGPU(tex);

	bool fileOpen = false;
	bool editUndo = false;
	bool viewDefault = false;
	bool createProjectWindow = false;
	
	char projectNameInput[64]{ "" };
	char projectPathInput[256]{ "" };
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
				ImGui::MenuItem("Close Project");
				ImGui::EndMenu();
			}
		}
		ImGui::EndMainMenuBar();

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

		if (app.m_Project != nullptr)
		{
			ProjectDetailsImGui(app.m_Project);
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
					app.CreateProject(std::string(projectNameInput));
					app.SaveProject(std::string(projectPath + "/" + projectName + ".harmonyproj"));
					createProjectWindow = false;
				}
			}
			ImGui::End();
		}


	};
	app.Run(callback);
}