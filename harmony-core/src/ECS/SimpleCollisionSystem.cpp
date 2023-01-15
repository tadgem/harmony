#include <algorithm>
#include <mutex>
#include <execution>
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
	PreUpdate(registry);
	UpdateColliders(registry);
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

	auto sphereView = registry.view<SphereColliderComponent>();
	for (auto [e, s] : sphereView.each())
	{
		j["sphere"][GetEntityKey(e)] = s;
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

	auto sphereJson = systemJson["sphere"];
	for (auto entry = sphereJson.begin(); entry != sphereJson.end(); entry++)
	{
		entt::entity e = GetEntityFromKey(entry.key());
		nlohmann::json sphereJson = entry.value();
		SphereColliderComponent c;
		sphereJson.get_to<SphereColliderComponent>(c);

		registry.emplace<SphereColliderComponent>(e, c);
	}
}

void harmony::SimpleCollisionSystem::Refresh()
{
}

static std::mutex s_AABBHitsMutex;
static std::mutex s_SphereHitsMutex;

std::vector<harmony::Hit> harmony::SimpleCollisionSystem::Raycast(Ray ray, entt::registry& registry)
{
	auto hits = std::vector<Hit>();
	auto aabbView = registry.view<TransformComponent, AABBColliderComponent>();
	std::for_each(
		std::execution::par,
		aabbView.begin(),
		aabbView.end(),
		[&ray, &hits, &aabbView](const auto &e)
		{
			AABBColliderComponent& aabb = aabbView.get<AABBColliderComponent>(e);
			auto hitPos = Collision::Intersects(ray, aabb.m_Frame);
			if (hitPos.Position.w > 0.0f)
			{
				Hit h;
				h.Position = glm::vec3(hitPos.Position.x, hitPos.Position.y, hitPos.Position.z);
				h.DidHit = true;
				h.Entity = e;
				std::lock_guard<std::mutex> hitLock(s_AABBHitsMutex);
				hits.push_back(h);
			}
		}
	);


	auto sphereView = registry.view<TransformComponent, SphereColliderComponent>();
	std::for_each(
		std::execution::par,
		sphereView.begin(),
		sphereView.end(),
		[&ray, &hits, &sphereView](const auto& e)
		{
			SphereColliderComponent& s = sphereView.get<SphereColliderComponent>(e);
			TransformComponent& t = sphereView.get<TransformComponent>(e);
			auto hitPos = Collision::Intersects(ray, harmony::Sphere{ glm::vec4(t.Position, s.m_Radius) });
			if (hitPos.Position.w > 0.0f)
			{
				Hit h;
				h.Position = glm::vec3(hitPos.Position.x, hitPos.Position.y, hitPos.Position.z);
				h.DidHit = true;
				h.Entity = e;
				std::lock_guard<std::mutex> hitLock(s_SphereHitsMutex);
				hits.push_back(h);
			}
		}
	);

	return hits;
}

static std::mutex s_AABBTransformMutex;

void harmony::SimpleCollisionSystem::UpdateColliders(entt::registry& registry)
{
	auto aabbView = registry.view<TransformComponent, AABBColliderComponent>();
	auto aabbs = std::vector<AABBColliderComponent*>();
	auto aabbEntities = std::vector<entt::entity>();
#if 0 // Experimental MT 
	std::for_each(
		std::execution::seq,
		aabbView.begin(),
		aabbView.end(),
		[&aabbs, &aabbEntities, &aabbView](const auto& e)
		{
			auto t = aabbView.get<TransformComponent>(e);
			auto aabb = aabbView.get<AABBColliderComponent>(e);

			AABB newAABB = Collision::UpdateAABB(aabb.m_Original, glm::mat3(glm::transpose(t.Model)), t.Position);
			std::lock_guard<std::mutex> hitLock(s_AABBTransformMutex);
			aabb.m_Colliders.clear();
			aabb.m_Frame = newAABB;
			aabbs.emplace_back(&aabb);
			aabbEntities.emplace_back(e);
		});
#else

	for (auto& [e, t, aabb] : aabbView.each())
	{
		aabb.m_Frame = Collision::UpdateAABB(aabb.m_Original, glm::mat3(glm::transpose(t.Model)), t.Position);
		aabb.m_Colliders.clear();
		aabbs.emplace_back(&aabb);
		aabbEntities.emplace_back(e);
	}
#endif
	// AABB - AABB Intersection
	size_t numAABBs = aabbs.size();
	if (numAABBs > 0)
	{
		for (int i = numAABBs - 1; i >= 0; i--)
		{
			size_t startIndex = i - 1;;
			AABBColliderComponent* thisAABB = aabbs[i];
			if (i < 0) continue;

			for (int c = numAABBs - 1; c >= 0; c--)
			{
				AABBColliderComponent* currentAABB = aabbs[c];
				if (Collision::Intersects(thisAABB->m_Frame, currentAABB->m_Frame))
				{
					currentAABB->m_Colliders.emplace_back(aabbEntities[i]);
					thisAABB->m_Colliders.emplace_back(aabbEntities[c]);
				}
			}
		}
	}


	auto sphereView = registry.view<TransformComponent, SphereColliderComponent>();
	auto spheres = std::vector<SphereColliderComponent*>();
	auto sphereTransforms = std::vector<TransformComponent*>();
	auto sphereEntities = std::vector<entt::entity>();
	for (auto& [e, t, s] : sphereView.each())
	{
		s.m_Colliders.clear();
		spheres.emplace_back(&s);
		sphereEntities.emplace_back(e);
		sphereTransforms.emplace_back(&t);
	}

	size_t numSpheres = spheres.size();
	if (numSpheres > 0)
	{
		for (int i = numSpheres - 1; i >= 0; i--)
		{
			size_t startIndex = i - 1;;
			SphereColliderComponent* thisSphereComponent = spheres[i];
			TransformComponent* thisTransform = sphereTransforms[i];
			Sphere sphere{ glm::vec4(thisTransform->Position.x,thisTransform->Position.y,thisTransform->Position.z, thisSphereComponent->m_Radius) };
			if (i < 0) continue;
			// Sphere - Sphere Intersection Test
			for (int c = startIndex; c >= 0; c--)
			{
				SphereColliderComponent* currentSphereComponent = spheres[c];
				TransformComponent* currentTransform = sphereTransforms[c];
				Sphere currentSphere{ glm::vec4(currentTransform->Position.x,currentTransform->Position.y,currentTransform->Position.z, currentSphereComponent->m_Radius) };
				if (Collision::Intersects(sphere, currentSphere))
				{
					currentSphereComponent->m_Colliders.emplace_back(sphereEntities[i]);
					thisSphereComponent->m_Colliders.emplace_back(sphereEntities[c]);
				}
			}
			// Sphere - AABB Intersection test
			for (int a = 0; a < aabbs.size(); a++)
			{
				if (Collision::Intersects(sphere, aabbs[a]->m_Frame))
				{
					aabbs[a]->m_Colliders.emplace_back(sphereEntities[i]);
					thisSphereComponent->m_Colliders.emplace_back(aabbEntities[a]);
				}
			}
		}
	}
	for (auto& [e, t, aabb] : aabbView.each())
	{
#if HARMONY_DEBUG
		if (aabb.m_Colliders.size() > 0)
		{
			DrawAABB(aabb.m_Frame, 0xff00ff00);
		}
		else
		{
			DrawAABB(aabb.m_Frame, 0xffffffff);
		}
#endif
	}

	for (auto& [e, t, s] : sphereView.each())
	{
#if HARMONY_DEBUG
		if (s.m_Colliders.size() > 0)
		{
			DrawSphere(t.Position,s.m_Radius, 0xff00ff00);
		}
		else
		{
			DrawSphere(t.Position, s.m_Radius, 0xffffffff);
		}
#endif
	}
}
void harmony::SimpleCollisionSystem::PreUpdate(entt::registry& registry)
{
	
}
#if HARMONY_DEBUG
void harmony::SimpleCollisionSystem::DrawAABB(AABB& aabb, uint32_t color)
{
	bx::Aabb bgfxAABB;
	bgfxAABB.max = bx::Vec3(aabb.Max.x, aabb.Max.y, aabb.Max.z);
	bgfxAABB.min = bx::Vec3(aabb.Min.x, aabb.Min.y, aabb.Min.z);
	GfxDebug::Get()->setColor(GfxDebug::Editor, color);
	GfxDebug::Get()->draw(GfxDebug::Editor, bgfxAABB);
}
void harmony::SimpleCollisionSystem::DrawSphere(glm::vec3 position, float radius, uint32_t color)
{
	bx::Sphere bgfxSphere;
	bgfxSphere.center = bx::Vec3(position.x, position.y, position.z);
	bgfxSphere.radius = radius;
	GfxDebug::Get()->setColor(GfxDebug::Editor, color);
	GfxDebug::Get()->draw(GfxDebug::Editor, bgfxSphere);
}
#endif