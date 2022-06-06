#include "ImGui/imgui.h"
#include "Core/Program.h"

void ProjectDetailsImGui(harmony::Ref<harmony::Project> project)
{
	std::string windowTitle = "Project Properties : " + project->m_ProjectName;
	if (ImGui::Begin(windowTitle.c_str()))
	{
		ImGui::Text("Project Name : ", project->m_ProjectName);
		ImGui::Text("Project Path : ", project->m_ProjectDirectory);
	}
	ImGui::End();
}