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

        explicit GraphScriptImGuiEditor(GraphScriptNodeRegistry* vm);
        Vector<ImGuiGraphState> m_GraphStates;

        void Render();

    protected:
        ImVec2                      p_MousePosition;
        GraphScriptNodeRegistry*    m_GraphScriptBuilder;
        int                         p_SelectedGraphIndex;
        bool                        p_ShowNodeSelector = false;
    };
}