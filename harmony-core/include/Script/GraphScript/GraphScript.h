//
// Created by Admin on 4/15/2023.
//

#ifndef HARMONY_DOJO_GRAPHSCRIPT_H
#define HARMONY_DOJO_GRAPHSCRIPT_H

#include "Assets/Asset.h"
#include "Core/Alias.h"
#include "Core/Memory.h"

namespace harmony {
    namespace GraphScript {

        class IVariable {
            virtual void Dispose() = 0;
        };

        template<typename T>
        class IVariableT : public IVariable {
        public:
            virtual T *Get() = 0;

            virtual void Set(const T &value) = 0;
        };

        template<typename T>
        class HeapVariable : public IVariableT<T> {
        public:
            template<typename ... Args>
            explicit HeapVariable(Args &&... args) {
                p_Value = CreateUnique<T>(args ...);
            }

            virtual T *Get() override { return p_Value.get(); }

            virtual void Set(const T &value) { *p_Value = value; }

            virtual void Dispose() { p_Value.reset(); }

        protected:
            Unique<T> p_Value;
        };

        struct Ops {
            Vector<Procedure> m_Procs;
        };

        class IGraphNodeIO {
        };

        class ExecutionGraphNodeIO : public IGraphNodeIO {
        };

        template<typename T>
        class IGraphNodeIOT : public IGraphNodeIO {
        public:
            IGraphNodeIOT() = default;

            T *m_Value = nullptr;

        };

        class IConnection {
        public:
            IGraphNodeIO *m_LHS = nullptr;
            IGraphNodeIO *m_RHS = nullptr;
        };

        class IGraphNode {
        public:

            virtual Ops Build() = 0;

            virtual nlohmann::json Serialize() = 0;

            virtual void Deserialize() = 0;

            virtual IGraphNode *Clone() = 0;

            String Name;
            Vector<Unique<IGraphNodeIO>> m_Inputs;
            Vector<Unique<IGraphNodeIO>> m_Outputs;

        };

        class PrintNode : public IGraphNode {
        public:
            PrintNode();

            Ops Build() override;

            nlohmann::json Serialize() override;

            void Deserialize() override;

            IGraphNode *Clone() override;

            Unique<IGraphNodeIOT<String>> m_StringInput;

        public:
        };

        struct EntryPointName {
        public:
            explicit EntryPointName(const std::string &name);

            uint64_t m_id;

            inline bool operator==(const EntryPointName &rhs) { return m_id = rhs.m_id; }

            inline bool operator!=(const EntryPointName &rhs) const { return m_id != rhs.m_id; }

            inline bool operator<(const EntryPointName &rhs) const { return m_id < rhs.m_id; }
        };

        class EntryPointNode : public IGraphNode {
        public:
            explicit EntryPointNode(const String &entryPointName);

            Ops Build() override;

            nlohmann::json Serialize() override;

            void Deserialize() override;

            IGraphNode *Clone() override;

            EntryPointName m_Entry;
        };


        class Graph {
        public:

            bool Build();

            nlohmann::json Serialize();

            void CallEntryPoint(EntryPointName &name);

            String                          m_Name;
            Vector<Unique<IGraphNode>>      m_GraphNodes;
            Vector<Unique<IVariable>>       m_Variables;
            Vector<Unique<IConnection>>     m_Connections;
            Vector<Unique<EntryPointNode>>  m_EntryPoints;
        protected:
            Map<EntryPointName, Ops>        p_Entries;
        };

    }

    class GraphScriptVM {
    public:
        GraphScriptVM();

        ~GraphScriptVM();

        void AddNode(GraphScript::IGraphNode *node);

        void RemoveNode(GraphScript::IGraphNode *node);

        Unique<GraphScript::Graph> DeserializeGraph(nlohmann::json json);

        Vector<GraphScript::IGraphNode *> m_AvailableNodes;
    };
}

#endif //HARMONY_DOJO_GRAPHSCRIPT_H
