#pragma once

#include "Jolt/Jolt.h"
#include <Jolt/Physics/Collision/ContactListener.h>

namespace harmony {
    class HarmonyContactListener final : public JPH::ContactListener {
    public:
        HarmonyContactListener();

        ~HarmonyContactListener() override = default;

        JPH::ValidateResult
        OnContactValidate(const JPH::Body &inBody1, const JPH::Body &inBody2, JPH::RVec3Arg inBaseOffset,
                          const JPH::CollideShapeResult &inCollisionResult) override;

        void OnContactAdded(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                            JPH::ContactSettings &ioSettings) override;

        void
        OnContactPersisted(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                           JPH::ContactSettings &ioSettings) override;

        void OnContactRemoved(const JPH::SubShapeIDPair &inSubShapePair) override;

    public:

    };
}