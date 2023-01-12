#include "ECS/SimpleCollisionSystem.h"
#include "Core/Memory.h"
#include "Core/Log.hpp"
#include "Collision/Collision.h"
#include "ECS/TransformComponent.h"
#include "ECS/SimpleCollisionComponent.h"
#include "Rendering/Mesh.h"
#if HARMONY_DEBUG
#include "Rendering/Debug/GfxDebug.h"
#endif
harmony::SimpleCollisionSystem::SimpleCollisionSystem(AssetManager& am) : System(GetTypeHash<SimpleCollisionSystem>()), p_AssetManager(am)
{
}

void harmony::SimpleCollisionSystem::Init(entt::registry& registry)
{
	auto view = registry.view<TransformComponent, AABBComponent>();
	for (auto& [e, t, aabb] : view.each())
	{
		auto mesh = p_AssetManager.GetAsset<Mesh>(aabb.m_MeshHandle);
		if (mesh.expired())
		{
			harmony::log::error("SimpleCollisionSystem : Unable to get aabb for mesh at path : {}", aabb.m_MeshHandle.Path);
			continue;
		}
		auto m = mesh.lock();
		aabb.aabb = m->m_AABB;
	}
}

void harmony::SimpleCollisionSystem::Update(entt::registry& registry)
{
	auto view = registry.view<TransformComponent, AABBComponent>();
	for (auto& [e, t, aabb] : view.each())
	{
		AABB trans = aabb.aabb;
		Collision::UpdateAABB(trans, glm::mat3(glm::transpose(t.Model)), t.Position);
#if HARMONY_DEBUG
		bx::Aabb bgfxAABB;
		bgfxAABB.max = bx::Vec3(trans.Max.x, trans.Max.y, trans.Max.z);
		bgfxAABB.min = bx::Vec3(trans.Min.x, trans.Min.y, trans.Min.z);
		GfxDebug::Get()->draw(GfxDebug::Editor, bgfxAABB);
#endif

	}
}

void harmony::SimpleCollisionSystem::Render(entt::registry& registry)
{
}

void harmony::SimpleCollisionSystem::Cleanup(entt::registry& registry)
{
}

nlohmann::json harmony::SimpleCollisionSystem::SerializeSystem(entt::registry& registry)
{
	nlohmann::json j;

	auto view = registry.view<AABBComponent>();

	for (auto [e, aabb] : view.each())
	{
		j["aabb"][GetEntityKey(e)] = aabb;
	}

	return j;
}

void harmony::SimpleCollisionSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
	auto aabbJson = systemJson["aabb"];

	for (auto entry = aabbJson.begin(); entry != aabbJson.end(); entry++)
	{
		entt::entity e = GetEntityFromKey(entry.key());
		nlohmann::json aabb = entry.value();
		AABBComponent c;
		aabb.get_to<AABBComponent>(c);

		registry.emplace<AABBComponent>(e, c);
	}
}

void harmony::SimpleCollisionSystem::Refresh()
{
}
