#include "EditorUtils.h"

void ProjectDetailsImGui(harmony::Program &program) {
    if (ImGui::Begin("Project")) {
        if (program.m_Project != nullptr) {
            ImGui::TextWrapped("Project Name : ", program.m_Project->m_ProjectName.c_str());
        } else {
            ImGui::TextWrapped("No Project Loaded");
        }
    }
    ImGui::End();
}
