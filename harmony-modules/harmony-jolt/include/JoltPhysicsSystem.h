#pragma once

#include "ECS/System.h"
#include "Core/Memory.h"
#include "Jolt/Jolt.h"
#include "Jolt/Physics/PhysicsSettings.h"
#include <Jolt/Core/TempAllocator.h>

namespace JPH {
    class BroadPhaseLayerInterface;

    class JobSystem;

    class PhysicsSystem;

    class BodyInterface;

    class ObjectVsBroadPhaseLayerFilter;

    class ObjectLayerPairFilter;
}
namespace harmony {
    struct JoltBodyComponent;

    class HarmonyContactListener;

    class HarmonyBodyActivationListener;

    class HarmonyDebugRenderer;

    class TransformComponent;

    enum JoltBodyShape;

    class JoltPhysicsSystem : public System {
    public:
        JoltPhysicsSystem();

        ~JoltPhysicsSystem() override;

        void Init(entt::registry &registry) override;

        void Update(entt::registry &registry) override;

        void Render(entt::registry &registry) override;

        void Cleanup(entt::registry &registry) override;

        nlohmann::json SerializeSystem(entt::registry &registry) override;

        void DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) override;

        void Refresh() override;

        JoltBodyComponent &CreateBodyComponent(entt::registry registry, entt::entity e, JoltBodyShape shape);

        void DestroyBody(JoltBodyComponent &body);

    protected:

        const bool m_DrawDebug = true;

        void InitBody(entt::entity e, TransformComponent &t, JoltBodyComponent &b);

        static constexpr bool s_UseContactListener = true;
        static constexpr uint32_t s_NumBodyMutexes = 0; // Autodetect
        static constexpr uint32_t s_MaxBodyPairs = 65536;
        static constexpr uint32_t s_NumBodies = 10240;
        static constexpr uint32_t s_MaxContactConstraints = 10240;
        static constexpr uint32_t s_MaxPhysicsJobs = 2048;
        static constexpr uint32_t s_MaxPhysicsBarriers = 8;
        static constexpr uint32_t s_ValidatingJobSystemNumThreads = 0;
        static constexpr uint32_t s_CollisionSteps = 1;
        static constexpr uint32_t s_IntegrationSubSteps = 1;
        static constexpr uint32_t s_TempAllocatorSizeMb = 16;
        static constexpr float s_DefaultCollisionTolerance = 1.0e-4f;
        static constexpr float s_DefaultPenetrationTolerance = 1.0e-4f; ///< Stop when there's less than 1% change
        static constexpr float s_DefaultConvexRadius = 0.05f;
        static constexpr float s_CapsuleProjectionSlop = 0.02f;
        const JPH::Vec3 s_DefaultGravity = JPH::Vec3(0.0f, -9.81f, 0.0f);

        const uint32_t m_NumJobs;
        float m_UpdateFrequency = 60.0f;    // Physics update frequency

        JPH::PhysicsSettings m_PhysicsSettings;
        Unique<JPH::TempAllocator> m_TempAllocator;            // Allocator for temporary allocations
        Unique<JPH::JobSystem> m_JobSystem;                // The job system that runs physics jobs
        Unique<JPH::JobSystem> m_JobSystemValidating;        // The job system to use when validating determinism
        Unique<JPH::PhysicsSystem> m_PhysicsSystem;            // The physics system that simulates the world
        Unique<JPH::BroadPhaseLayerInterface> m_BroadPhaseLayerInterface;
        Unique<JPH::ObjectVsBroadPhaseLayerFilter> m_ObjectVsBroadphaseFilter;
        Unique<JPH::ObjectLayerPairFilter> m_ObjectLayerPairFilter;
        Unique<HarmonyBodyActivationListener> m_BodyActivationListener;
        Unique<HarmonyContactListener> m_ContactListener;          // Contact listener implementation
        Unique<HarmonyDebugRenderer> m_DebugRenderer;
        JPH::BodyInterface *m_BodyInterface;

        friend class JoltDebugRendererComponent;
    };
}