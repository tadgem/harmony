#include <algorithm>
#include <mutex>
#include "Core/Thread.h"
#include <execution>
#include <optick.h>
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

harmony::SimpleCollisionSystem::SimpleCollisionSystem(AssetManager &am) : System(GetTypeHash<SimpleCollisionSystem>()),
                                                                          p_AssetManager(am) {
    OPTICK_EVENT();

    m_DebugDraw = true;
}

void harmony::SimpleCollisionSystem::Init(entt::registry &registry) {
    OPTICK_EVENT();

    auto view = registry.view<TransformComponent, AABBColliderComponent>();
    for (auto [e, t, aabb]: view.each()) {
        auto mesh = p_AssetManager.GetAsset<Mesh>(aabb.m_MeshHandle);
        if (mesh.expired()) {
            harmony::log::error("SimpleCollisionSystem : Unable to get aabb for mesh at path : {}",
                                aabb.m_MeshHandle.Path);
            continue;
        }
        auto m = mesh.lock();
        aabb.m_Original = m->m_AABB;
    }
}

void harmony::SimpleCollisionSystem::Update(entt::registry &registry) {
    OPTICK_EVENT();

    PreUpdate(registry);
    UpdateColliders(registry);
}

void harmony::SimpleCollisionSystem::Render(entt::registry &registry) {
    OPTICK_EVENT();

}

void harmony::SimpleCollisionSystem::Cleanup(entt::registry &registry) {
    OPTICK_EVENT();
}

nlohmann::json harmony::SimpleCollisionSystem::SerializeSystem(entt::registry &registry) {
    OPTICK_EVENT();
    nlohmann::json j;

    auto view = registry.view<AABBColliderComponent>();

    for (auto [e, aabb]: view.each()) {
        j["aabb"][GetEntityKey(e)] = aabb;
    }

    auto sphereView = registry.view<SphereColliderComponent>();
    for (auto [e, s]: sphereView.each()) {
        j["sphere"][GetEntityKey(e)] = s;
    }

    return j;
}

void harmony::SimpleCollisionSystem::DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) {
    OPTICK_EVENT();
    auto aabbJson = systemJson["aabb"];
    for (auto entry = aabbJson.begin(); entry != aabbJson.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        nlohmann::json aabb = entry.value();
        AABBColliderComponent c;
        aabb.get_to<AABBColliderComponent>(c);

        registry.emplace<AABBColliderComponent>(e, c);
    }

    auto sphereJson = systemJson["sphere"];
    for (auto entry = sphereJson.begin(); entry != sphereJson.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        nlohmann::json sphereJson = entry.value();
        SphereColliderComponent c;
        sphereJson.get_to<SphereColliderComponent>(c);

        registry.emplace<SphereColliderComponent>(e, c);
    }
}

void harmony::SimpleCollisionSystem::Refresh() {
    OPTICK_EVENT();
}

static std::mutex s_AABBHitsMutex;
static std::mutex s_SphereHitsMutex;

bool hit_sorter(harmony::Hit const &lhs, harmony::Hit const &rhs) {
    return lhs.Distance < rhs.Distance;
}

std::vector<harmony::Hit> harmony::SimpleCollisionSystem::Raycast(Ray ray, entt::registry &registry) {
    OPTICK_EVENT();
    // Ray - AABB Intersection Test
    auto hits = std::vector<Hit>();
    auto aabbView = registry.view<TransformComponent, AABBColliderComponent>();
    std::for_each(
            std::execution::par,
            aabbView.begin(),
            aabbView.end(),
            [&ray, &hits, &aabbView](const auto &e) {
                AABBColliderComponent &aabb = aabbView.get<AABBColliderComponent>(e);
                auto hitPos = Collision::Intersects(ray, aabb.m_Frame);
                if (hitPos.Position.w > 0.0f) {
                    Hit h;
                    h.Position = glm::vec3(hitPos.Position.x, hitPos.Position.y, hitPos.Position.z);
                    h.DidHit = true;
                    h.Entity = e;
                    std::lock_guard<std::mutex> hitLock(s_AABBHitsMutex);
                    hits.push_back(h);
                }
            }
    );

    // Ray - Sphere Intersection Test
    auto sphereView = registry.view<TransformComponent, SphereColliderComponent>();
    std::for_each(
            std::execution::par,
            sphereView.begin(),
            sphereView.end(),
            [&ray, &hits, &sphereView](const auto &e) {
                SphereColliderComponent &s = sphereView.get<SphereColliderComponent>(e);
                TransformComponent &t = sphereView.get<TransformComponent>(e);
                auto hitPos = Collision::Intersects(ray, harmony::Sphere{glm::vec4(t.Position, s.m_Radius)});
                if (hitPos.Position.w > 0.0f) {
                    Hit h;
                    h.Position = glm::vec3(hitPos.Position);
                    h.DidHit = true;
                    h.Entity = e;
                    h.Distance = hitPos.Distance;
                    std::lock_guard<std::mutex> hitLock(s_SphereHitsMutex);
                    hits.push_back(h);
                }
            }
    );

    // Sort hits by distance.
    std::sort(hits.begin(), hits.end(), hit_sorter);
    return hits;
}

static std::mutex s_AABBTransformMutex;
static std::mutex s_SphereIntersectionMutex;

struct AABBCol {
    entt::entity Entity;
    harmony::AABB Col;

    bool operator==(const AABBCol &c2) {
        return Entity == c2.Entity;
    }

    bool operator!=(const AABBCol &c2) {
        return Entity != c2.Entity;
    }
};

struct SphereCol {
    entt::entity Entity;
    harmony::Sphere Col;

    bool operator==(const SphereCol &c2) {
        return Entity == c2.Entity;
    }

    bool operator!=(const SphereCol &c2) {
        return Entity != c2.Entity;
    }
};

struct EntityCollision {
    entt::entity A;
    entt::entity B;

    bool operator==(const EntityCollision &c2) {
        return
                (A == c2.A && B == c2.B) ||
                (A == c2.B && B == c2.A);
    }

    bool operator!=(const EntityCollision &c2) {
        return
                (A != c2.A || B != c2.B) ||
                (A != c2.B || B != c2.A);
    }
};

void harmony::SimpleCollisionSystem::UpdateColliders(entt::registry &registry) {
    OPTICK_EVENT();
    auto aabbView = registry.view<TransformComponent, AABBColliderComponent>();
    auto sphereView = registry.view<TransformComponent, SphereColliderComponent>();

    std::vector<entt::entity> EntitiesToUpdate;

    // Collect all entities that need to be updated.
    // Collect all of their previous colliders and update them too
    // ensure no dupes.
    {
        for (auto [e, t, aabb]: aabbView.each()) {
            // TODO: support updating only if needed.
            if (t.UpdateCollision) {
                EntitiesToUpdate.push_back(e);
                aabb.m_Frame = Collision::UpdateAABB(aabb.m_Original, glm::mat3(glm::transpose(t.Model)), t.Position);
                for (entt::entity ce: aabb.m_Colliders) {
                    if (std::find(EntitiesToUpdate.begin(), EntitiesToUpdate.end(), ce) == EntitiesToUpdate.end()) {
                        EntitiesToUpdate.push_back(ce);
                    }
                }
                t.UpdateCollision = false;
            }
        }


        for (auto [e, t, sphere]: sphereView.each()) {
            // TODO: support updating only if needed.
            if (t.UpdateCollision) {
                EntitiesToUpdate.push_back(e);

                for (entt::entity ce: sphere.m_Colliders) {
                    if (std::find(EntitiesToUpdate.begin(), EntitiesToUpdate.end(), ce) == EntitiesToUpdate.end()) {
                        EntitiesToUpdate.push_back(ce);
                    }
                }
                t.UpdateCollision = false;
            }
        }
    }
    // Create list of colliders to intersect test.
    std::vector<AABBCol> UpdateAABBs;
    std::vector<SphereCol> UpdateSpheres;
    std::vector<AABBCol> AABBs;
    std::vector<SphereCol> Spheres;
    {
        for (auto [e, t, aabb]: aabbView.each()) {
            auto findIt = std::find(EntitiesToUpdate.begin(), EntitiesToUpdate.end(), e);
            AABBCol col = AABBCol{e, aabb.m_Frame};
            if (findIt != EntitiesToUpdate.end()) {
                aabb.m_Colliders.clear();
                UpdateAABBs.push_back(col);
                EntitiesToUpdate.erase(findIt);
            }
            AABBs.push_back(col);
        }

        for (auto [e, t, sphere]: sphereView.each()) {
            auto findIt = std::find(EntitiesToUpdate.begin(), EntitiesToUpdate.end(), e);
            SphereCol col = SphereCol{e, Sphere{glm::vec4(t.Position, sphere.m_Radius)}};
            if (findIt != EntitiesToUpdate.end()) {
                sphere.m_Colliders.clear();
                UpdateSpheres.push_back(col);
                EntitiesToUpdate.erase(findIt);
            }
            Spheres.push_back(col);
        }
    }
    // Warn if some entities have been missed.
    if (!EntitiesToUpdate.empty()) {
        harmony::log::warn("SimpleCollisionSystem : Not all entities requiring collision could be updated!");
    }

    std::vector<std::future<std::vector<EntityCollision>>> futures;

    // Intersection Tests (needs to be performed against ALL colliders.)
    // AABB-AABB
    for (AABBCol &col: UpdateAABBs) {
        futures.emplace_back(
                ThreadPool.submit(
                        [col, AABBs]() {
                            std::vector<EntityCollision> collisions;
                            for (int i = 0; i < AABBs.size(); i++) {
                                if (col.Entity == AABBs[i].Entity) continue;
                                if (Collision::Intersects(col.Col, AABBs[i].Col)) {
                                    collisions.push_back({col.Entity, AABBs[i].Entity});
                                }
                            }
                            return collisions;
                        }
                )
        );
    }
    // AABB-Sphere
    for (AABBCol &col: UpdateAABBs) {
        futures.emplace_back(
                ThreadPool.submit(
                        [col, Spheres]() {
                            std::vector<EntityCollision> collisions;
                            for (int i = 0; i < Spheres.size(); i++) {
                                if (Collision::Intersects(col.Col, Spheres[i].Col)) {
                                    collisions.push_back({col.Entity, Spheres[i].Entity});
                                }
                            }
                            return collisions;
                        }
                )
        );
    }
    // Sphere-Sphere
    for (SphereCol &col: UpdateSpheres) {
        futures.emplace_back(
                ThreadPool.submit(
                        [col, Spheres]() {
                            std::vector<EntityCollision> collisions;
                            for (int i = 0; i < Spheres.size(); i++) {
                                if (col.Entity == Spheres[i].Entity) continue;
                                if (Collision::Intersects(col.Col, Spheres[i].Col)) {
                                    collisions.push_back({col.Entity, Spheres[i].Entity});
                                }
                            }
                            return collisions;
                        }
                )
        );
    }
    // Sphere-AABB
    for (SphereCol &col: UpdateSpheres) {
        futures.emplace_back(
                ThreadPool.submit(
                        [col, AABBs]() {
                            std::vector<EntityCollision> collisions;
                            for (int i = 0; i < AABBs.size(); i++) {
                                if (Collision::Intersects(col.Col, AABBs[i].Col)) {
                                    collisions.push_back({col.Entity, AABBs[i].Entity});
                                }
                            }
                            return collisions;
                        }
                )
        );
    }
    std::vector<EntityCollision> collisions;
    while (futures.size() > 0) {
        for (int i = futures.size() - 1; i >= 0; i--) {
            if (is_ready<std::vector<EntityCollision>>(futures[i])) {
                auto cols = futures[i].get();
                collisions.insert(collisions.end(), cols.begin(), cols.end());
                futures.erase(futures.begin() + i);
            }
        }
    }

    for (int i = collisions.size() - 1; i >= 0; i--) {
        EntityCollision ec = collisions[i];
        if (registry.any_of<AABBColliderComponent>(ec.A)) {
            AABBColliderComponent &a = registry.get<AABBColliderComponent>(ec.A);
            if (registry.any_of<AABBColliderComponent>(ec.B)) {
                AABBColliderComponent &b = registry.get<AABBColliderComponent>(ec.B);
                if (std::find(b.m_Colliders.begin(), b.m_Colliders.end(), ec.A) == b.m_Colliders.end()) {
                    b.m_Colliders.emplace_back(ec.A);
                }
                if (std::find(a.m_Colliders.begin(), a.m_Colliders.end(), ec.B) == a.m_Colliders.end()) {
                    a.m_Colliders.emplace_back(ec.B);
                }
            }
            if (registry.any_of<SphereColliderComponent>(ec.B)) {
                SphereColliderComponent &b = registry.get<SphereColliderComponent>(ec.B);
                if (std::find(b.m_Colliders.begin(), b.m_Colliders.end(), ec.A) == b.m_Colliders.end()) {
                    b.m_Colliders.emplace_back(ec.A);
                }
                if (std::find(a.m_Colliders.begin(), a.m_Colliders.end(), ec.B) == a.m_Colliders.end()) {
                    a.m_Colliders.emplace_back(ec.B);
                }
            }
        }
        if (registry.any_of<SphereColliderComponent>(ec.A)) {
            SphereColliderComponent &a = registry.get<SphereColliderComponent>(ec.A);
            if (registry.any_of<AABBColliderComponent>(ec.B)) {
                AABBColliderComponent &b = registry.get<AABBColliderComponent>(ec.B);
                if (std::find(b.m_Colliders.begin(), b.m_Colliders.end(), ec.A) == b.m_Colliders.end()) {
                    b.m_Colliders.emplace_back(ec.A);
                }
                if (std::find(a.m_Colliders.begin(), a.m_Colliders.end(), ec.B) == a.m_Colliders.end()) {
                    a.m_Colliders.emplace_back(ec.B);
                }
            }
            if (registry.any_of<SphereColliderComponent>(ec.B)) {
                SphereColliderComponent &b = registry.get<SphereColliderComponent>(ec.B);
                if (std::find(b.m_Colliders.begin(), b.m_Colliders.end(), ec.A) == b.m_Colliders.end()) {
                    b.m_Colliders.emplace_back(ec.A);
                }
                if (std::find(a.m_Colliders.begin(), a.m_Colliders.end(), ec.B) == a.m_Colliders.end()) {
                    a.m_Colliders.emplace_back(ec.B);
                }
            }
        }
    }

    // Draw Collision Primitives
    {
        if (m_DebugDraw) {
            for (auto [e, t, aabb]: aabbView.each()) {
#if HARMONY_DEBUG
                if (aabb.m_Colliders.size() > 0) {
                    DrawAABB(aabb.m_Frame, 0xff00ff00);
                } else {
                    DrawAABB(aabb.m_Frame, 0xffffffff);
                }
#endif
            }

            for (auto [e, t, s]: sphereView.each()) {
#if HARMONY_DEBUG
                if (s.m_Colliders.size() > 0) {
                    DrawSphere(t.Position, s.m_Radius, 0xff00ff00);
                } else {
                    DrawSphere(t.Position, s.m_Radius, 0xffffffff);
                }
#endif
            }
        }
    }
}

void harmony::SimpleCollisionSystem::PreUpdate(entt::registry &registry) {
    OPTICK_EVENT();
}

#if HARMONY_DEBUG

void harmony::SimpleCollisionSystem::DrawAABB(AABB &aabb, uint32_t color) {
    OPTICK_EVENT();
    bx::Aabb bgfxAABB;
    bgfxAABB.max = bx::Vec3(aabb.Max.x, aabb.Max.y, aabb.Max.z);
    bgfxAABB.min = bx::Vec3(aabb.Min.x, aabb.Min.y, aabb.Min.z);
    GfxDebug::Get()->setColor(GfxDebug::Editor, color);
    GfxDebug::Get()->draw(GfxDebug::Editor, bgfxAABB);
}

void harmony::SimpleCollisionSystem::DrawSphere(glm::vec3 position, float radius, uint32_t color) {
    OPTICK_EVENT();
    bx::Sphere bgfxSphere;
    bgfxSphere.center = bx::Vec3(position.x, position.y, position.z);
    bgfxSphere.radius = radius;
    GfxDebug::Get()->setColor(GfxDebug::Editor, color);
    GfxDebug::Get()->draw(GfxDebug::Editor, bgfxSphere);
}

#endif