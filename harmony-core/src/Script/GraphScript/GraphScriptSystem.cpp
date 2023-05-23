//
// Created by liam_ on 5/1/2023.
//
#include "Script/GraphScript/GraphScriptProgramComponent.h"
#include "Script/GraphScript/GraphScriptSystem.h"

harmony::GraphScriptSystem::GraphScriptSystem(harmony::Ref<harmony::GraphScriptProgramComponent> gspc)
: System(GetTypeHash<GraphScriptSystem>()), p_ProgramComponent(gspc)
{

}

void harmony::GraphScriptSystem::Init(entt::registry &registry) {

}

void harmony::GraphScriptSystem::Update(entt::registry &registry) {

}

void harmony::GraphScriptSystem::Render(entt::registry &registry) {

}

void harmony::GraphScriptSystem::Cleanup(entt::registry &registry) {

}

nlohmann::json harmony::GraphScriptSystem::SerializeSystem(entt::registry &registry) {
    return nlohmann::json();
}

void harmony::GraphScriptSystem::DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) {

}

void harmony::GraphScriptSystem::Refresh() {

}
