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
	auto view = registry.view<TransformComponent, AABBColliderComponent>();
	for (auto& [e, t, aabb] : view.each())
	{
		auto mesh = p_AssetManager.GetAsset<Mesh>(aabb.m_MeshHandle);
		if (mesh.expired())
		{
			harmony::log::error("SimpleCollisionSystem : Unable to get aabb for mesh at path : {}", aabb.m_MeshHandle.Path);
			continue;
		}
		auto m = mesh.lock();
		aabb.m_Original = m->m_AABB;
	}
}

void harmony::SimpleCollisionSystem::Update(entt::registry& registry)
{
	auto aabbView = registry.view<TransformComponent, AABBColliderComponent>();
	for (auto& [e, t, aabb] : aabbView.each())
	{
		aabb.m_Frame = aabb.m_Original;
		Collision::UpdateAABB(aabb.m_Frame, glm::mat3(glm::transpose(t.Model)), t.Position);
#if HARMONY_DEBUG
		bx::Aabb bgfxAABB;
		bgfxAABB.max = bx::Vec3(aabb.m_Frame.Max.x, aabb.m_Frame.Max.y, aabb.m_Frame.Max.z);
		bgfxAABB.min = bx::Vec3(aabb.m_Frame.Min.x, aabb.m_Frame.Min.y, aabb.m_Frame.Min.z);
		GfxDebug::Get()->draw(GfxDebug::Editor, bgfxAABB);
#endif
	}

	auto sphereView = registry.view<TransformComponent, SphereColliderComponent>();
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

	auto view = registry.view<AABBColliderComponent>();

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
		AABBColliderComponent c;
		aabb.get_to<AABBColliderComponent>(c);

		registry.emplace<AABBColliderComponent>(e, c);
	}
}

void harmony::SimpleCollisionSystem::Refresh()
{
}