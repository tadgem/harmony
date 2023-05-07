//
// Created by liam_ on 4/21/2023.
//
#include "Core/Log.hpp"
#include "ImGui/GraphScript/GraphScriptImGui.h"
#include "ImGui/imgui.h"
#include "ImGui/imnodes.h"
#include "SDL.h"

void harmony::GraphScriptImGuiEditor::Render() {
    if (ImGui::Begin("GraphScripts")) {
        ImNodes::BeginNodeEditor();

        if (ImGui::IsWindowFocused(ImGuiFocusedFlags_RootAndChildWindows) &&
            ImNodes::IsEditorHovered() && ImGui::IsKeyReleased(ImGuiKey_MouseRight)) {
            // ImNodes::SetNodeScreenSpacePos(1, ImGui::GetMousePos());
            harmony::log::info("Right clicked in GraphScript Editor");
            p_MousePosition = ImGui::GetMousePos();
            p_ShowNodeSelector = true;
        }
        else if(ImGui::IsKeyReleased(ImGuiKey_MouseLeft))
        {
            p_ShowNodeSelector = false;
        }

        ImNodes::MiniMap();
        ImNodes::EndNodeEditor();

        int create_start_attr, create_end_attr;
        if (ImNodes::IsLinkCreated(&create_start_attr, &create_end_attr)) {

        }
        int destroyed_attr;
        if (ImNodes::IsLinkDestroyed(&destroyed_attr)) {

        }
        int drop_start_attr;
        if (ImNodes::IsLinkDropped(&drop_start_attr, true)) {

        }
    }
    ImGui::End();

    if(p_ShowNodeSelector) {
        ImGui::SetNextWindowPos(p_MousePosition);
        if (ImGui::Begin("Nodes")) {
            for (auto availableNode: m_GraphScriptBuilder->m_AvailableNodes)
            {
                if(ImGui::MenuItem(availableNode->m_Name.c_str()))
                {
                    p_ShowNodeSelector = false;
                }
            }
        }
        ImGui::End();
    }

}

harmony::GraphScriptImGuiEditor::GraphScriptImGuiEditor(harmony::GraphScript::NodeRegistry *vm) : m_GraphScriptBuilder(vm)
{
}
