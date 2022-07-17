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

bool ShaderSelector(const std::string& selectorName, harmony::Renderer& renderer, harmony::WeakRef<harmony::ShaderProgram>& prog)
{
	bool selectedAsset = false;
	std::vector<std::string> shaders = renderer.GetShaderNames();

	if (ImGui::BeginCombo(selectorName.c_str(), ""))
	{
		for (int i = 0; i < shaders.size(); i++)
		{
			if (ImGui::Selectable(shaders[i].c_str()))
			{
				prog = renderer.GetShader(shaders[i]);
				selectedAsset = true;
			}
		}
		ImGui::EndCombo();
	}

	return selectedAsset;

}

