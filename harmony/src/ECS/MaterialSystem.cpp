#include "ECS/MaterialSystem.h"
#include "ECS/MaterialComponent.h"

harmony::MaterialSystem::MaterialSystem(Renderer& renderer) : System(GetTypeHash<MaterialComponent>()), p_Renderer(renderer)
{
}

void harmony::MaterialSystem::Init(entt::registry& registry)
{
}

void harmony::MaterialSystem::Update(entt::registry& registry)
{
}

void harmony::MaterialSystem::Render(entt::registry& registry)
{
}

void harmony::MaterialSystem::Cleanup(entt::registry& registry)
{
}

nlohmann::json harmony::MaterialSystem::SerializeSystem(entt::registry& registry)
{
	nlohmann::json j;

	auto view = registry.view<MaterialComponent>();

	for (auto [e, mat] : view.each())
	{
		j[GetEntityKey(e)] = mat;
	}

	return j;
}

void harmony::MaterialSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
	for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++)
	{
		entt::entity e = GetEntityFromKey(entry.key());
		MaterialComponent mc = entry.value();
		WeakRef<ShaderProgram> shader = p_Renderer.GetShader(mc.Data.m_ShaderName);
		mc.Data.UpdateShader(shader);
		registry.emplace<MaterialComponent>(e, mc);
	}
}

void harmony::MaterialSystem::Refresh()
{
}
