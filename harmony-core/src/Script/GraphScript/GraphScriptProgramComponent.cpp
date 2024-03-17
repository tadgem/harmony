//
// Created by liam_ on 5/1/2023.
//
#include "Script/GraphScript/GraphScriptProgramComponent.h"
#include "Script/GraphScript/GraphScript.h"

harmony::GraphScriptProgramComponent::GraphScriptProgramComponent() : ProgramComponent(
        GetTypeHash<GraphScriptProgramComponent>()) {
    p_NodeRegistry = CreateUnique<GraphScript::NodeRegistry>();
    p_NodeRegistry->AddNode(new GraphScript::PrintNode());
    p_NodeRegistry->AddNode(new GraphScript::EntryPointNode());
}

void harmony::GraphScriptProgramComponent::Init() {

}

void harmony::GraphScriptProgramComponent::Update() {

}

void harmony::GraphScriptProgramComponent::Render() {

}

void harmony::GraphScriptProgramComponent::Cleanup() {

}

harmony::Json harmony::GraphScriptProgramComponent::ToJson() {
    return Json();
}

void harmony::GraphScriptProgramComponent::FromJson(const Json &json) {

}

harmony::GraphScriptProgramComponent::~GraphScriptProgramComponent() {
    p_NodeRegistry.reset();
}

harmony::GraphScript::NodeRegistry *harmony::GraphScriptProgramComponent::GetNodeRegistry() {
    return p_NodeRegistry.get();
}
