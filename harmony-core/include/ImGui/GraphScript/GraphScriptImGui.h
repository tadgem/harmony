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

        explicit GraphScriptImGuiEditor(GraphScriptBuilder* vm);

        Vector<GraphScript::Graph *> m_Graphs;
        Vector<ImGuiGraphState> m_GraphStates;

        void AddGraph(GraphScript::Graph *graph);

        void Render();

    protected:
        ImVec2                  p_MousePosition;
        GraphScriptBuilder*     m_GraphScriptBuilder;
        int                     p_SelectedGraphIndex;
        bool                    p_ShowNodeSelector = false;
    };
}