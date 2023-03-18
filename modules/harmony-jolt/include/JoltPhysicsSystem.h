#pragma once
#include "ECS/System.h"
#include "Jolt/Jolt.h"
#include "Jolt/Physics/PhysicsSettings.h"

class BroadPhaseLayerInterface;
namespace JPH
{
    class TempAllocator;
    class JobSystem;
    class PhysicsSystem;
}
namespace harmony
{
    class JoltPhysicsSystem : public System
    {
    public:
        JoltPhysicsSystem();
        ~JoltPhysicsSystem() override;

        void Init(entt::registry &registry) override;
        void Update(entt::registry &registry) override;
        void Render(entt::registry &registry) override;
        void Cleanup(entt::registry &registry) override;
        nlohmann::json SerializeSystem(entt::registry &registry) override;
        void DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) override;

    protected:
        void Refresh() override;

        static constexpr uint32_t s_NumBodyMutexes = 0; // Autodetect
        static constexpr uint32_t s_MaxBodyPairs = 65536;
        static constexpr uint32_t s_MaxContactConstraints = 10240;

        float					mUpdateFrequency = 60.0f;									// Physics update frequency
        int						mCollisionSteps = 1;										// How many collision detection steps per physics update
        int						mIntegrationSubSteps = 1;									// How many integration steps per physics update
        JPH::TempAllocator *			mTempAllocator = nullptr;									// Allocator for temporary allocations
        JPH::JobSystem *				mJobSystem = nullptr;										// The job system that runs physics jobs
        JPH::JobSystem *				mJobSystemValidating = nullptr;								// The job system to use when validating determinism
        JPH::PhysicsSystem *			mPhysicsSystem = nullptr;									// The physics system that simulates the world
        JPH::PhysicsSettings			mPhysicsSettings;
        BroadPhaseLayerInterface* mBroadPhaseLayerInterface;
        // JPH::ContactListenerImpl *	mContactListener = nullptr;									// Contact listener implementation


    };
}