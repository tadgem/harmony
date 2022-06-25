#include "ECS/TileMapSystem.h"
#include "ECS/TileMapComponent.h"
#include "ImGui/imgui.h"
#include "ImGui/icons_font_awesome.h"
#include "ImGui/icons_kenney.h"

harmony::TileMapSystem::TileMapSystem(AssetManager& assetManager, Renderer& renderer) : System(GetTypeHash<TileMapSystem>()), p_AssetManager(assetManager), p_Renderer(renderer)
{
}

void harmony::TileMapSystem::Init(entt::registry& registry)
{
}

void harmony::TileMapSystem::Update(entt::registry& registry)
{
	
}

void harmony::TileMapSystem::Render(entt::registry& registry)
{
}

void harmony::TileMapSystem::Cleanup(entt::registry& registry)
{
}

nlohmann::json harmony::TileMapSystem::SerializeSystem(entt::registry& registry)
{
	return nlohmann::json();
}

void harmony::TileMapSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
}

void harmony::TileMapSystem::Refresh()
{
}
