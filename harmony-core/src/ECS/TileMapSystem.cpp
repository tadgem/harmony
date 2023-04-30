#include <optick.h>
#include "ECS/TileMapSystem.h"
#include "ECS/TileMapComponent.h"
#include "ImGui/imgui.h"
#include "ImGui/icons_font_awesome.h"
#include "ImGui/icons_kenney.h"

harmony::TileMapSystem::TileMapSystem(AssetManager &assetManager, Renderer &renderer) : System(
        GetTypeHash<TileMapSystem>()), p_AssetManager(assetManager), p_Renderer(renderer) {
    OPTICK_EVENT();
}

void harmony::TileMapSystem::Init(entt::registry &registry) {
    OPTICK_EVENT();
}

void harmony::TileMapSystem::Update(entt::registry &registry) {
    OPTICK_EVENT();
}

void harmony::TileMapSystem::Render(entt::registry &registry) {
    OPTICK_EVENT();
}

void harmony::TileMapSystem::Cleanup(entt::registry &registry) {
    OPTICK_EVENT();
}

nlohmann::json harmony::TileMapSystem::SerializeSystem(entt::registry &registry) {
    OPTICK_EVENT();
    return nlohmann::json();
}

void harmony::TileMapSystem::DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) {
    OPTICK_EVENT();
}

void harmony::TileMapSystem::Refresh() {
    OPTICK_EVENT();
}
