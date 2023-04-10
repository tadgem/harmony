#pragma once
#include "Core/Alias.h"
#include "Core/Memory.h"
#include "ThirdParty/entt.hpp"

namespace harmony
{
    class View;
    class PipelineGraph
    {
        public:

        class IVariable
        {
        public:
        };

        class INodeInput
        {
        public:
        };

        class INodeOutput
        {
        public:
        };

        class INode
        {
        public:
            Vector<INodeInput*>    m_Inputs;
            Vector<INodeOutput*>   m_Outputs;

            virtual void Process() = 0;
        };

        class IConnection
        {
        public:
            virtual void Process() = 0;
        };

        class INodeOutputConnection : public IConnection
        {
        public:
            INodeOutput*    m_LHS;
            INodeInput*     m_RHS;

        };

        PipelineGraph();
        ~PipelineGraph();

        Vector<INode*>               m_GraphNodes;
        Vector<IConnection*>         m_GraphConnections;
        HashMap<String, IVariable*>  m_GraphVariables;

        void ProcessGraph(entt::registry& registry, WeakRef<View> view);

    };
}