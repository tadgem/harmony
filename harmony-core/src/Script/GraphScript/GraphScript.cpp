#include "Script/GraphScript/GraphScript.h"
#include "Core/Log.hpp"
harmony::GraphScript::Ops harmony::GraphScript::PrintNode::Build() {
    auto ops = Ops();

    ops.m_Procs.emplace_back([]()
    {
        harmony::log::info("Printing from print node");
    });

    return ops;
}

nlohmann::json harmony::GraphScript::PrintNode::Serialize() {
    return nlohmann::json();
}

void harmony::GraphScript::PrintNode::Deserialize() {

}

harmony::GraphScript::PrintNode::PrintNode()
{
    m_StringInput = CreateUnique<IGraphNodeIOT<String>>();
}

harmony::GraphScript::IGraphNode *harmony::GraphScript::PrintNode::Clone() {
    return new PrintNode();
}

harmony::GraphScript::EntryPointNode::EntryPointNode(const String &entryPointName) {

}

harmony::GraphScript::EntryPointNode::EntryPointNode() {

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

void harmony::GraphScriptVM::AddNode(harmony::GraphScript::IGraphNode *node)
{
    if(node == nullptr)
    {
        harmony::log::warn("GraphScriptVM : Provided Node is nullptr");
        return;
    }
    if(std::find(m_AvailableNodes.begin(), m_AvailableNodes.end(), node) != m_AvailableNodes.end())
    {
        harmony::log::warn("GraphScriptVM : Already provided Node to VM : {}", node->Name);
        return;
    }
    m_AvailableNodes.push_back(node);

}

void harmony::GraphScript::Graph::CallEntryPoint(String name)
{
    if(p_Entries.find(name) == p_Entries.end())
    {
        harmony::log::warn("GraphScript : Graph : No entry point : {}", name);
        return;
    }

    const Ops& ops = p_Entries[name];

    for(int i = 0; i < ops.m_Procs.size(); i++)
    {
        ops.m_Procs[i]();
    }

}

bool harmony::GraphScript::Graph::Build() {
    return false;
}
