#include "EditorMenu.h"
#include "ImGui/ImGuiFileDialog.h"

harmony::EditorMainMenuBar::EditorMainMenuBar(Program& prog) : p_Prog(prog)
{
	p_CreateProjectMenu = false;
	p_CreateSceneMenu = false;
}

void harmony::EditorMainMenuBar::OnImGui()
{
	MenuBar();
	Dialogs();
	Popups();
}

void harmony::EditorMainMenuBar::MenuBar()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Create Project"))
			{
				p_CreateProjectMenu = true;
			}
			if (ImGui::MenuItem("Open Project"))
			{
				ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenProject", "Choose Project", ".harmonyproj", ".");
			}
			if (ImGui::MenuItem("Save Project"))
			{
				p_Prog.SaveProject();
			}
			ImGui::MenuItem("Close Project");
			ImGui::Separator();
			if (ImGui::MenuItem("New Scene"))
			{
				if (p_Prog.m_Project)
				{
					p_CreateSceneMenu = true;
				}
			}
			if (ImGui::MenuItem("Save Scene"))
			{
				if (!p_Prog.GetActiveScene().expired())
				{
					ImGuiFileDialog::Instance()->OpenDialog("HarmonySaveScene", "Choose Scene", ".harmonyscene,.json", ".");
				}
			}
			ImGui::EndMenu();
		}
	}
	ImGui::EndMainMenuBar();
}

void harmony::EditorMainMenuBar::Dialogs()
{
	if (ImGuiFileDialog::Instance()->Display("HarmonyOpenProject"))
	{
		// action if OK
		if (ImGuiFileDialog::Instance()->IsOk())
		{
			std::string filepath = ImGuiFileDialog::Instance()->GetFilePathName();
			p_Prog.LoadProject(filepath);
		}
		ImGuiFileDialog::Instance()->Close();
	}

	if (ImGuiFileDialog::Instance()->Display("HarmonySaveScene"))
	{
		// action if OK
		if (ImGuiFileDialog::Instance()->IsOk())
		{
			std::string filepath = ImGuiFileDialog::Instance()->GetFilePathName();
			p_Prog.SaveScene(filepath);
		}
		ImGuiFileDialog::Instance()->Close();
	}
}

void harmony::EditorMainMenuBar::Popups()
{
	if (p_CreateProjectMenu)
	{
		if (ImGui::Begin("Create Project"))
		{
			ImGui::InputText("Project Name", &p_ProjectNameInput[0], 64);
			ImGui::InputText("Project Path", &p_ProjectPathInput[0], 256);
			ImGui::Separator();
			if (ImGui::Button("Create Project"))
			{
				std::string projectName = std::string(p_ProjectNameInput);
				std::string projectPath = std::string(p_ProjectPathInput);
				p_Prog.CreateProject(projectName, projectPath);
				p_Prog.SaveProject();
				p_CreateProjectMenu = false;
			}
		}
		ImGui::End();
	}

	if (p_CreateSceneMenu)
	{
		if (ImGui::Begin("Create Scene"))
		{
			ImGui::InputText("Scene Name", &p_SceneNameInput[0], 256);
			if (ImGui::Button("Create"))
			{
				p_Prog.CreateScene(std::string(p_SceneNameInput));
				p_CreateSceneMenu = false;
			}
		}
		ImGui::End();
	}
}
