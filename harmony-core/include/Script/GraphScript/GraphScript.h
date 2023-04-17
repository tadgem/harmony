//
// Created by Admin on 4/15/2023.
//

#ifndef HARMONY_DOJO_GRAPHSCRIPT_H
#define HARMONY_DOJO_GRAPHSCRIPT_H

#include "Assets/Asset.h"
#include "Core/Alias.h"
#include "Core/Memory.h"

namespace harmony
{
    namespace GraphScript
    {

        class IVariable
        {
            virtual void Dispose() = 0;
        };

        template<typename T>
        class IVariableT : public IVariable
        {
        public:
            virtual T*      Get() = 0;
            virtual void    Set(const T& value) = 0;
        };

        template<typename T>
        class HeapVariable : public IVariableT<T>
        {
        public:
            template<typename ... Args>
            explicit HeapVariable(Args&& ... args)
            {
                p_Value = CreateUnique<T>(args ...);
            }

            virtual T*      Get() override      { return p_Value.get();}
            virtual void    Set(const T& value) { *p_Value = value;}
            virtual void    Dispose()           { p_Value.reset(); }

        protected:
            Unique<T> p_Value;
        };

        struct Ops
        {
            Vector<Procedure> m_Procs;
        };

        class IGraphNodeIO
        {
            virtual void Process() = 0;
        };

        template<typename T>
        class IGraphNodeIOT : public IGraphNodeIO
        {
        public:

        };

        class IGraphNode
        {
        public:

            virtual Ops             Build() = 0;
            virtual nlohmann::json  Serialize() = 0;
            virtual void            Deserialize() = 0;

            Vector<Unique<IGraphNodeIO>>    m_Inputs;
            Vector<Unique<IGraphNodeIO>>    m_Outputs;

        };

        class PrintNode : public IGraphNode
        {
        public:
        };

        struct IControlFlow
        {
            IGraphNodeIO* m_LHS;
            IGraphNodeIO* m_RHS;
        };

        class Graph
        {
        public:
            Vector<Unique<IGraphNode>>      m_GraphNodes;
            Vector<Unique<IVariable>>       m_Variables;
            Vector<Unique<IControlFlow>>    m_GraphFlow;

        };

    };

    class GraphScriptVM
    {

    };
}

#endif //HARMONY_DOJO_GRAPHSCRIPT_H
