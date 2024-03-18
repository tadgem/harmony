//
// Created by liam_ on 5/1/2023.
//
#include "Script/GraphScript/GraphScriptProgramComponent.h"

harmony::GraphScriptProgramComponent::GraphScriptProgramComponent() : ProgramComponent(
    GetTypeHash<GraphScriptProgramComponent>()) {
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
}

