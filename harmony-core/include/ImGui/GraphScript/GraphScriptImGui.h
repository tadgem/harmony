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

        explicit GraphScriptImGuiEditor(GraphScript::NodeRegistry* vm);
        Vector<ImGuiGraphState> m_GraphStates;

        void Render();

    protected:
        ImVec2                      p_MousePosition;
        GraphScript::NodeRegistry*    m_GraphScriptBuilder;
        int                         p_SelectedGraphIndex;
        bool                        p_ShowNodeSelector = false;
    };
}