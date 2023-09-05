//
// Created by liam_ on 5/1/2023.
//
#include "Script/GraphScript/GraphScriptProgramComponent.h"
#include "Script/GraphScript/GraphScript.h"

harmony::GraphScriptProgramComponent::GraphScriptProgramComponent() : ProgramComponent(GET_TYPE_HASH(GraphScriptProgramComponent))
{
	p_NodeRegistry = CreateUnique<GraphScript::NodeRegistry>();
	p_NodeRegistry->AddNode(new GraphScript::PrintNode());
	p_NodeRegistry->AddNode(new GraphScript::EntryPointNode());
}

void harmony::GraphScriptProgramComponent::Init()
{

}

void harmony::GraphScriptProgramComponent::Update()
{

}

void harmony::GraphScriptProgramComponent::Render()
{

}

void harmony::GraphScriptProgramComponent::Cleanup()
{

}

nlohmann::json harmony::GraphScriptProgramComponent::ToJson()
{
	return nlohmann::json();
}

void harmony::GraphScriptProgramComponent::FromJson(const nlohmann::json &json)
{

}

harmony::GraphScriptProgramComponent::~GraphScriptProgramComponent()
{
	p_NodeRegistry.reset();
}

harmony::GraphScript::NodeRegistry *harmony::GraphScriptProgramComponent::GetNodeRegistry()
{
	return p_NodeRegistry.get();
}
