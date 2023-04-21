//
// Created by liam_ on 4/21/2023.
//
#include "ImGui/GraphScript/GraphScriptImGui.h"
#include "ImGui/imgui.h"
#include "ImGui/imnodes.h"

void harmony::GraphScriptImGuiEditor::AddGraphDebug(harmony::GraphScript::Graph *graph) {
    m_Graphs.emplace_back(graph);
}

void harmony::GraphScriptImGuiEditor::Render()
{
    if(ImGui::Begin("GraphScripts"))
    {
        ImNodes::BeginNodeEditor();
        ImNodes::EndNodeEditor();

        int create_start_attr, create_end_attr;
        if(ImNodes::IsLinkCreated(&create_start_attr, &create_end_attr))
        {

        }
        int destroyed_attr;
        if(ImNodes::IsLinkDestroyed(&destroyed_attr))
        {

        }
        int drop_start_attr;
        if(ImNodes::IsLinkDropped(&drop_start_attr,  true))
        {

        }
    }
    ImGui::End();
}
