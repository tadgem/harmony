//
// Created by liam_ on 11/5/2023.
//
#include "MiniGuis/LoadProjectGui.h"
#include "ImGui/imgui.h"
#include "ImGui/ImGuiFileDialog.h"
#include "Core/Program.h"

harmony::LoadProjectGui::LoadProjectGui(Program& prog) : MiniGuiApp("Select Project"), p_Program(prog)
{
    p_DialogOpen = false;
}

bool harmony::LoadProjectGui::OnImGui() {
    if(!p_DialogOpen)
    {
        ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenProject", "Choose Project", ".harmonyproj", "../../../../projects/");
        p_DialogOpen = true;
    }

    float dpi = ImGui::GetWindowDpiScale();
    auto maxSize = ImGui::GetMainViewport()->Size;
    ImGui::SetNextWindowPos(ImVec2(0,0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(maxSize, ImGuiCond_Always);
    bool loaded = false;
    if (ImGuiFileDialog::Instance()->Display("HarmonyOpenProject")) {
        // action if OK
        if (ImGuiFileDialog::Instance()->IsOk()) {
            std::string filepath = ImGuiFileDialog::Instance()->GetFilePathName();
            p_Program.LoadProject(filepath);
            p_Program.PreRunInit();
            loaded = true;

            if (p_Program.m_Project) {
                if (p_Program.m_Project->m_SerializedScenes.size() > 0) {
                    p_Program.LoadScene(p_Program.m_Project->m_SerializedScenes[0]);
                }
            }
        }
        ImGuiFileDialog::Instance()->Close();
    }
    return loaded;
}
