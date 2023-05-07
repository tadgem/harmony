#include "Script/GraphScript/GraphScript.h"
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

void harmony::GraphScriptNodeRegistry::AddNode(harmony::GraphScript::IGraphNode *node) {
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

harmony::GraphScriptNodeRegistry::GraphScriptNodeRegistry() {
    m_AvailableNodes = Vector<GraphScript::IGraphNode *>();
}


harmony::GraphScriptNodeRegistry::~GraphScriptNodeRegistry() {
    for (auto node: m_AvailableNodes) {
        if(node)
        {
            delete node;
        }
    }
    m_AvailableNodes.clear();
}

void harmony::GraphScriptNodeRegistry::RemoveNode(harmony::GraphScript::IGraphNode *node) {
    auto it = std::find(m_AvailableNodes.begin(), m_AvailableNodes.end(), node);
    if (it == m_AvailableNodes.end()) {
        harmony::log::warn("GraphScriptVM : Node not found in VM available nodes");
        return;
    }
    m_AvailableNodes.erase(it);
}

void harmony::GraphScript::Graph::CallEntryPoint(EntryPointName &name) {
    if (p_Entries.find(name) == p_Entries.end()) {
        harmony::log::warn("GraphScript : Graph : No entry point : {}", name.m_id);
        return;
    }

    const Ops &ops = p_Entries[name];

    for (int i = 0; i < ops.m_Procs.size(); i++) {
        ops.m_Procs[i]();
    }

}

bool harmony::GraphScript::Graph::Build() {
    return false;
}

nlohmann::json harmony::GraphScript::Graph::Serialize() {
    return nlohmann::json();
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
