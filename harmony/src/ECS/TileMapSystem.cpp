#include "ECS/TileMapSystem.h"
#include "ImGui/imgui.h"

harmony::TileMapSystem::TileMapSystem()
{
}

void harmony::TileMapSystem::Init(entt::registry& registry)
{
}

void harmony::TileMapSystem::Update(entt::registry& registry)
{
	if (ImGui::Begin("Tile Map Manager"))
	{
		ImGui::Text("Blep");
	}
	ImGui::End();
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

void harmony::TileMapSystem::DeserializeSystem(entt::registry registry)
{
}

void harmony::TileMapSystem::Refresh()
{
}
