#include "Project.h"
#include <filesystem>
#include "ImGui/imgui.h"
#include "Core/Profile.hpp"

harmony::Project::Project(std::string name, std::string projectPath, std::string projectDirectory) : m_ProjectName(name), m_ProjectPath(projectPath), m_ProjectDirectory(projectDirectory)
{
	
}
void harmony::Project::Save()
{
	HARMONY_PROFILE_FUNCTION()
	m_ImGuiIniPath = m_ProjectPath + ".ini";
	ImGui::SaveIniSettingsToDisk(m_ImGuiIniPath.c_str());
}
void harmony::Project::Load()
{
	HARMONY_PROFILE_FUNCTION()
	m_ImGuiIniPath = m_ProjectPath + ".ini";
	if (std::filesystem::exists(m_ImGuiIniPath))
	{
		ImGui::LoadIniSettingsFromDisk(m_ImGuiIniPath.c_str());
	}
	std::filesystem::current_path(std::filesystem::path(m_ProjectDirectory));
}

void harmony::Project::Unload(AssetManager& assetManager)
{
	HARMONY_PROFILE_FUNCTION()
	assetManager.UnloadAllAssets();
}

void harmony::Project::UpdateProjectComponentSerializationAttributes(std::vector<Ref<ProgramComponent>>& programComponents)
{
	HARMONY_PROFILE_FUNCTION()
	p_ProgramComponentSerializationAttributes.clear();

	for (int i = 0; i < programComponents.size(); i++)
	{
		auto pcRef = programComponents[i];
		p_ProgramComponentSerializationAttributes.emplace(pcRef->m_TypeHash, pcRef->ToJson());
	}
}
