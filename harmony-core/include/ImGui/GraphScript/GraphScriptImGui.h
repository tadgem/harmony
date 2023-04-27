#pragma once

#include "Script/GraphScript/GraphScript.h"
#include "ImGui/imgui.h"

namespace harmony {
    class ImGuiGraphState {
    public:
        HashMap<int, ImVec2> NodePositions;
    };

    class GraphScriptImGuiEditor {
    public:

        Vector<GraphScript::Graph *> m_Graphs;
        Vector<ImGuiGraphState> m_GraphStates;

        void AddGraph(GraphScript::Graph *graph);

        void Render();

    protected:
        int m_SelectedGraphIndex;
    };
}