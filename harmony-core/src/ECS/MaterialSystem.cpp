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

harmony::Json harmony::MaterialSystem::SerializeSystem(entt::registry &registry) {
    OPTICK_EVENT();
    Json j;
    auto view = registry.view<MaterialComponent>();

    for (auto [e, mat]: view.each()) {
        j[GetEntityKey(e)] = mat;
    }

    return j;
}

void harmony::MaterialSystem::DeserializeSystem(entt::registry &registry, Json systemJson) {
    OPTICK_EVENT();
    for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        MaterialComponent mc = entry.value();
        WeakPtr<ShaderProgram> shader = p_Renderer.GetShader(mc.Data.m_ShaderName);
        mc.Data.UpdateOverrides(shader, p_AssetManager);
        registry.emplace<MaterialComponent>(e, mc);
    }
}

harmony::Json harmony::MaterialSystem::SerializeEntity(entt::registry& registry, entt::entity e)
{
    OPTICK_EVENT();
    Json j;

    if(registry.any_of<MaterialComponent>(e))
    {
        MaterialComponent& mc = registry.get<MaterialComponent>(e);
        j = mc;
    }

    return j;
}

void harmony::MaterialSystem::DeserializeEntity(entt::registry& registry, entt::entity e, Json entityJson)
{
    MaterialComponent mc;
    entityJson.get_to<MaterialComponent>(mc);
    WeakPtr<ShaderProgram> shader = p_Renderer.GetShader(mc.Data.m_ShaderName);
    mc.Data.UpdateOverrides(shader, p_AssetManager);
    registry.emplace<MaterialComponent>(e, mc);
}


void harmony::MaterialSystem::Refresh() {
    OPTICK_EVENT();
}
