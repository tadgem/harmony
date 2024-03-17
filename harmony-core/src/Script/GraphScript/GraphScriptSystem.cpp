//
// Created by liam_ on 5/1/2023.
//
#include "Script/GraphScript/GraphScriptProgramComponent.h"
#include "Script/GraphScript/GraphScriptSystem.h"

harmony::GraphScriptSystem::GraphScriptSystem(harmony::RefCntPtr<harmony::GraphScriptProgramComponent> gspc)
        : System(GetTypeHash<GraphScriptSystem>()), p_ProgramComponent(gspc) {

}

void harmony::GraphScriptSystem::Init(entt::registry &registry) {

}

void harmony::GraphScriptSystem::Update(entt::registry &registry) {

}

void harmony::GraphScriptSystem::Render(entt::registry &registry) {

}

void harmony::GraphScriptSystem::Cleanup(entt::registry &registry) {

}

harmony::Json harmony::GraphScriptSystem::SerializeSystem(entt::registry &registry) {
    return {};
}

void harmony::GraphScriptSystem::DeserializeSystem(entt::registry &registry, Json systemJson) {

}

harmony::Json harmony::GraphScriptSystem::SerializeEntity(entt::registry& registry, entt::entity e)
{
	return {};
}

void harmony::GraphScriptSystem::
DeserializeEntity(entt::registry& registry, entt::entity e, Json entityJson)
{

}

void harmony::GraphScriptSystem::Refresh() {

}
