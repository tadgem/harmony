#include "Script/GraphScript/GraphScript.h"
#include "Script/GraphScript/GraphScriptAsset.h"
#include "ThirdParty/json.hpp"
#include "Core/Log.hpp"

harmony::GraphScript::Ops harmony::GraphScript::PrintNode::Build() {
    auto ops = Ops();

    ops.m_Procs.emplace_back([]() {
        harmony::log::info("Printing from print node");
    });

    return ops;
}

nlohmann::json harmony::GraphScript::PrintNode::Serialize() {
    return nlohmann::json();
}

void harmony::GraphScript::PrintNode::Deserialize() {

}

harmony::GraphScript::PrintNode::PrintNode() : IGraphNode("Print") {
    m_StringInput = CreateUnique<IGraphNodeIOT<String>>();
}

harmony::GraphScript::IGraphNode *harmony::GraphScript::PrintNode::Clone() {
    return new PrintNode();
}

harmony::GraphScript::EntryPointNode::EntryPointNode() : IGraphNode("EntryPoint")
{

}

harmony::GraphScript::Ops harmony::GraphScript::EntryPointNode::Build() {
    return harmony::GraphScript::Ops();
}

nlohmann::json harmony::GraphScript::EntryPointNode::Serialize() {
    return nlohmann::json();
}

void harmony::GraphScript::EntryPointNode::Deserialize() {

}

harmony::GraphScript::IGraphNode *harmony::GraphScript::EntryPointNode::Clone() {
    return nullptr;
}

void harmony::GraphScript::NodeRegistry::AddNode(harmony::GraphScript::IGraphNode *node) {
    if (node == nullptr) {
        harmony::log::warn("GraphScriptVM : Provided Node is nullptr");
        return;
    }
    if (std::find(m_AvailableNodes.begin(), m_AvailableNodes.end(), node) != m_AvailableNodes.end()) {
        harmony::log::warn("GraphScriptVM : Already provided Node to VM : {}", node->m_Name);
        return;
    }
    m_AvailableNodes.push_back(node);

}

harmony::GraphScript::NodeRegistry::NodeRegistry() {
    m_AvailableNodes = Vector<GraphScript::IGraphNode *>();
}


harmony::GraphScript::NodeRegistry::~NodeRegistry() {
    for (auto node: m_AvailableNodes) {
        if(node)
        {
            delete node;
        }
    }
    m_AvailableNodes.clear();
}

void harmony::GraphScript::NodeRegistry::RemoveNode(harmony::GraphScript::IGraphNode *node) {
    auto it = std::find(m_AvailableNodes.begin(), m_AvailableNodes.end(), node);
    if (it == m_AvailableNodes.end()) {
        harmony::log::warn("GraphScriptVM : Node not found in VM available nodes");
        return;
    }
    m_AvailableNodes.erase(it);
}

void harmony::GraphScript::CompiledGraph::CallEntryPoint(EntryPointName &name) {
    if (p_Entries.find(name.m_id) == p_Entries.end()) {
        harmony::log::warn("GraphScript : CompiledGraph : No entry point : {}", name.m_id);
        return;
    }

    const Ops &ops = p_Entries[name.m_id];

    for (int i = 0; i < ops.m_Procs.size(); i++) {
        ops.m_Procs[i]();
    }

}

harmony::GraphScript::EntryPointName::EntryPointName(const std::string & name) {
    for (auto c: name) {
        m_id += c;
    }

}

harmony::GraphScript::EntryPointName::EntryPointName()
{
    m_id = INVALID_ENTRY_POINT_NAME;
}

harmony::GraphScript::IGraphNode::IGraphNode(const harmony::String &name) : m_Name(name) {

}

harmony::Unique<harmony::GraphScript::CompiledGraph> harmony::GraphScript::GraphBuilder::Build() {
    return {};
}

nlohmann::json harmony::GraphScript::GraphBuilder::Serialize() {
    return {};
}
