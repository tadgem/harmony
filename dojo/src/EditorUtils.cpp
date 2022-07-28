#include "EditorUtils.h"

void ProjectDetailsImGui(harmony::Program& program)
{
	if (ImGui::Begin("Project"))
	{
		if (program.m_Project != nullptr)
		{
			ImGui::Text("Project Name : ", program.m_Project->m_ProjectName.c_str());
		}
		else
		{
			ImGui::Text("No Project Loaded");
		}
	}
	ImGui::End();
}
