#pragma once

#include "Jolt/Jolt.h"
#include <Jolt/Physics/Collision/ContactListener.h>
#include "Core/Alias.h"
#include "Core/Memory.h"

namespace harmony {
    class HarmonyContactListenerCallback
    {
    public:

        virtual void OnContactAdded(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                                    JPH::ContactSettings &ioSettings) = 0;

        virtual void OnContactPersisted(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                                        JPH::ContactSettings &ioSettings) = 0;

        virtual void OnContactRemoved(const JPH::SubShapeIDPair &inSubShapePair) = 0;
    };

    class HarmonyContactListener final : public JPH::ContactListener {
    public:
        HarmonyContactListener();

        ~HarmonyContactListener() override = default;

        void AddContactCallback(RefCntPtr<HarmonyContactListenerCallback> callback);

        JPH::ValidateResult
        OnContactValidate(const JPH::Body &inBody1, const JPH::Body &inBody2, JPH::RVec3Arg inBaseOffset,
                          const JPH::CollideShapeResult &inCollisionResult) override;

        void OnContactAdded(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                            JPH::ContactSettings &ioSettings) override;

        void
        OnContactPersisted(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                           JPH::ContactSettings &ioSettings) override;

        void OnContactRemoved(const JPH::SubShapeIDPair &inSubShapePair) override;

    protected:
        Vector<RefCntPtr<HarmonyContactListenerCallback>> p_Callbacks;

    };


}