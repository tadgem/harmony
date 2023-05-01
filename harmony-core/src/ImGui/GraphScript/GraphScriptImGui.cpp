//
// Created by liam_ on 4/21/2023.
//
#include "Core/Log.hpp"
#include "ImGui/GraphScript/GraphScriptImGui.h"
#include "ImGui/imgui.h"
#include "ImGui/imnodes.h"
#include "SDL.h"

void harmony::GraphScriptImGuiEditor::AddGraph(harmony::GraphScript::Graph *graph) {
    m_Graphs.emplace_back(graph);
    m_GraphStates.emplace_back(ImGuiGraphState());
}

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
            for (auto availableNode: m_GraphScriptVM->m_AvailableNodes)
            {
                if(ImGui::MenuItem(availableNode->Name.c_str()))
                {
                    harmony::log::info("GraphScriptImGuiEditor : Adding node {} to graph {}", availableNode->Name, m_Graphs[p_SelectedGraphIndex]->m_Name);
                    p_ShowNodeSelector = false;
                }
            }
        }
        ImGui::End();
    }

}

harmony::GraphScriptImGuiEditor::GraphScriptImGuiEditor(harmony::GraphScriptVM *vm) : m_GraphScriptVM(vm)
{
}
