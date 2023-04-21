#pragma once
#include "Script/GraphScript/GraphScript.h"
namespace harmony
{
    class GraphScriptImGuiEditor
    {
    public:

        Vector<GraphScript::Graph*> m_Graphs;
        void AddGraphDebug(GraphScript::Graph* graph);

        void Render();
    protected:
        int m_SelectedGraphIndex;
    };
}