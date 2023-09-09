#include <optick.h>
#include "ECS/MaterialSystem.h"
#include "ECS/MaterialComponent.h"

harmony::MaterialSystem::MaterialSystem(Renderer &renderer, AssetManager &assetManager) : System(
        GetTypeHash<MaterialSystem>()), p_Renderer(renderer), p_AssetManager(assetManager) {
    OPTICK_EVENT();
}

void harmony::MaterialSystem::Init(entt::registry &registry) {
    OPTICK_EVENT();
}

void harmony::MaterialSystem::Update(entt::registry &registry) {
    OPTICK_EVENT();
}

void harmony::MaterialSystem::Render(entt::registry &registry) {
    OPTICK_EVENT();
}

void harmony::MaterialSystem::Cleanup(entt::registry &registry) {
    OPTICK_EVENT();
}

nlohmann::json harmony::MaterialSystem::SerializeSystem(entt::registry &registry) {
    OPTICK_EVENT();
    nlohmann::json j;
    auto view = registry.view<MaterialComponent>();

    for (auto [e, mat]: view.each()) {
        j[GetEntityKey(e)] = mat;
    }

    return j;
}

void harmony::MaterialSystem::DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) {
    OPTICK_EVENT();
    for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        MaterialComponent mc = entry.value();
        WeakRef<ShaderProgram> shader = p_Renderer.GetShader(mc.Data.m_ShaderName);
        mc.Data.UpdateOverrides(shader, p_AssetManager);
        registry.emplace<MaterialComponent>(e, mc);
    }
}

void harmony::MaterialSystem::Refresh() {
    OPTICK_EVENT();
}