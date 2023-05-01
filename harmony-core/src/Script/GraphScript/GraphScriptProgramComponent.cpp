//
// Created by liam_ on 5/1/2023.
//
#include "Script/GraphScript/GraphScriptProgramComponent.h"
#include "Script/GraphScript/GraphScript.h"

harmony::GraphScriptProgramComponent::GraphScriptProgramComponent()
{
    p_VM = CreateUnique<GraphScriptVM>();
}

void harmony::GraphScriptProgramComponent::Init() {

}

void harmony::GraphScriptProgramComponent::Update() {

}

void harmony::GraphScriptProgramComponent::Render() {

}

void harmony::GraphScriptProgramComponent::Cleanup() {

}

nlohmann::json harmony::GraphScriptProgramComponent::ToJson() {
    return nlohmann::json();
}

void harmony::GraphScriptProgramComponent::FromJson(const nlohmann::json &json) {

}

harmony::GraphScriptProgramComponent::~GraphScriptProgramComponent()
{
    p_VM.reset();
}
