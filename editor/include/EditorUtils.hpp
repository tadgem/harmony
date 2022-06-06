#include "ImGui/imgui.h"
#include "Core/Program.h"

void ProjectDetailsImGui(harmony::Ref<harmony::Project> project)
{
	std::string windowTitle = "Project Properties : " + project->m_ProjectName;
	if (ImGui::Begin(windowTitle.c_str()))
	{
		std::string projectNameText = "Project Name : " + project->m_ProjectName;
		ImGui::Text(projectNameText.c_str());
		std::string projectDirectoryText = "Project Path : %s" + project->m_ProjectDirectory;
		ImGui::Text(projectDirectoryText.c_str());
	}
	ImGui::End();
}