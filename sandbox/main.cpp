#include <iostream>
#include "Core/Program.h"
#include "ScriptSandboxComponent.h"
#include "Assets/ScriptAsset.h"
#include "Core/Log.hpp"
#include "ImGuiFileDialog.h"
#include "imgui.h"
#include <algorithm>
int main()
{
	harmony::Program app("Harmony Test");

	auto scriptComponent = app.AddProgramComponent<harmony::ScriptSandboxComponent>(app.m_AssetManager);
	app.Init();
	app.Run([&]()
	{
			if (ImGui::Begin("Project Debug"))
			{
                static char script_path[128] = "Hello, world!";
                static char str0[128] = "Hello, world!";
                ImGui::Text("Current Path: %s", std::filesystem::current_path().generic_string().c_str());
                ImGui::InputText("Filename: %s", str0, 128);
                ImGui::InputText("Script To Load: %s", script_path, 128);
                if (ImGui::Button("Load Script"))
                {
                    app.m_AssetManager.LoadAssetFromPath<harmony::ScriptAsset>(std::string(script_path));
                    scriptComponent.lock()->RefreshAvailableScripts();
                }
                ImGui::Separator();
                // open Dialog Simple
                if (ImGui::Button("Save Harmony Project"))
                    ImGuiFileDialog::Instance()->OpenDialog("HarmonySaveProject", "Choose Directory",nullptr, ".");

                if (ImGui::Button("Open Harmony Project"))
                    ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenProject", "Choose Project", ".harmonyproj", ".");

                // display
                if (ImGuiFileDialog::Instance()->Display("HarmonyOpenProject"))
                {
                    // action if OK
                    if (ImGuiFileDialog::Instance()->IsOk())
                    {
                        std::string filepath = ImGuiFileDialog::Instance()->GetFilePathName();
                        nlohmann::json json = harmony::Utils::LoadJsonFromPath(filepath);
                        harmony::Project project = json.get<harmony::Project>();
                        app.LoadProject(project);
                    }
                    // close
                    ImGuiFileDialog::Instance()->Close();
                }

                // display
                if (ImGuiFileDialog::Instance()->Display("HarmonySaveProject"))
                {
                    // action if OK
                    if (ImGuiFileDialog::Instance()->IsOk())
                    {
                        std::string directory = ImGuiFileDialog::Instance()->GetCurrentPath();
                        std::string fullPath = directory + "/" + std::string(str0) + ".harmonyproj";
                        std::replace(fullPath.begin(), fullPath.end(), '\\', '/'); // replace all 'x' to 'y'
                        std::replace(directory.begin(), directory.end(), '\\', '/'); // replace all 'x' to 'y'
                        // action
                        harmony::Project proj = harmony::Project(fullPath, directory);
                        app.SaveProject(proj);
                    }
                    // close
                    ImGuiFileDialog::Instance()->Close();
                }
                    
			}
			ImGui::End();
	});
}