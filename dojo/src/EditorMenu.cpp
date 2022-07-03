#include "EditorMenu.h"
#include "ImGui/ImGuiFileDialog.h"
harmony::EditorMainMenuBar::EditorMainMenuBar()
{
}

void harmony::EditorMainMenuBar::OnImGui()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Create Project"))
			{
				//createProjectWindow = true;
			}
			if (ImGui::MenuItem("Open Project"))
			{
				ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenProject", "Choose Project", ".harmonyproj", ".");
			}
			if (ImGui::MenuItem("Save Project"))
			{
				//app.SaveProject();
			}
			ImGui::MenuItem("Close Project");
			ImGui::Separator();
			if (ImGui::MenuItem("New Scene"))
			{
				//createSceneWindow = true;
			}
			if (ImGui::MenuItem("Save Scene"))
			{
				ImGuiFileDialog::Instance()->OpenDialog("HarmonySaveScene", "Choose Scene", ".harmonyscene,.json", ".");
			}
			ImGui::EndMenu();
		}
	}
	ImGui::EndMainMenuBar();
}
