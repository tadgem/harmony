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

        struct EntryPointName {
        public:
            explicit EntryPointName(const std::string &name);

            EntryPointName();

            uint64_t m_id;
            static const uint64_t INVALID_ENTRY_POINT_NAME = 0;

            inline bool operator==(const EntryPointName &rhs) {
                return m_id = rhs.m_id;
            }

            inline bool operator!=(const EntryPointName &rhs) const {
                return m_id != rhs.m_id;
            }

            inline bool operator<(const EntryPointName &rhs) const {
                return m_id < rhs.m_id;
            }
        };

        struct Ops {
            Vector<Procedure> m_Procs;
        };

        class IVariable {
            virtual void Dispose() = 0;
        };

        class IGraphNodeIO {
        public:
            IGraphNodeIO();

            IGraphNodeIO(uint64_t id);

            const uint64_t m_ID;
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
            template<typename... Args>
            explicit HeapVariable(Args &&...args) {
                p_Value = CreateUnique<T>(args...);
            }

            virtual T *Get() override {
                return p_Value.get();
            }

            virtual void Set(const T &value) {
                *p_Value = value;
            }

            virtual void Dispose() {
                p_Value.reset();
            }

        protected:
            Unique<T> p_Value;
        };

        template<typename T>
        class IGraphNodeIOT : public IGraphNodeIO {
        public:
            IGraphNodeIOT() = default;

            T *m_Value = nullptr;
        };

        class ExecutionGraphNodeIO : public IGraphNodeIO {
        };

        class IConnection {
        public:
            IGraphNodeIO *m_LHS = nullptr;
            IGraphNodeIO *m_RHS = nullptr;
        };

        class IGraphNode {
        public:
            explicit IGraphNode(const String &name);

            virtual Ops Build() = 0;

            virtual nlohmann::json Serialize() = 0;

            virtual void Deserialize() = 0;

            virtual IGraphNode *Clone() = 0;

            const String m_Name;
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

        class EntryPointNode : public IGraphNode {
        public:
            EntryPointNode();

            Ops Build() override;

            nlohmann::json Serialize() override;

            void Deserialize() override;

            IGraphNode *Clone() override;

            EntryPointName m_Entry;
        };

        class CompiledGraph {
        public:
            void CallEntryPoint(EntryPointName &name);

        protected:
            HashMap<uint64_t, Ops> p_Entries;
            Vector<Unique<IVariable>> p_Variables;
        };

        class SerializedGraph {
        };

        class NodeRegistry {
        public:
            NodeRegistry();

            ~NodeRegistry();

            void AddNode(GraphScript::IGraphNode *node);

            void RemoveNode(GraphScript::IGraphNode *node);

            Vector<GraphScript::IGraphNode *> m_AvailableNodes;
        };

        class GraphBuilder {
        public:
            String m_Name;
            Vector<Unique<IGraphNode>> m_GraphNodes;
            Vector<Unique<IVariable>> m_Variables;
            Vector<Unique<IConnection>> m_Connections;
            Vector<Unique<EntryPointNode>> m_EntryPoints;

            Unique<CompiledGraph> Build();

            nlohmann::json Serialize();
        };
    } // namespace GraphScript

} // namespace harmony

#endif // HARMONY_DOJO_GRAPHSCRIPT_H
