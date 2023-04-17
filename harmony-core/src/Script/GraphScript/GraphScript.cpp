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
