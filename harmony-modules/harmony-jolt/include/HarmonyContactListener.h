#pragma once

#include "Jolt/Jolt.h"
#include <Jolt/Physics/Collision/ContactListener.h>
#include "Core/Alias.h"
#include "Core/Memory.h"
#include "Core/TypeDef.h"
#include "Jolt/Physics/PhysicsSystem.h"

namespace harmony {
    class HarmonyContactListenerCallback
    {
    public:

        HarmonyContactListenerCallback(HashString typeHash);

        virtual void OnContactAdded(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                                    JPH::ContactSettings &ioSettings) = 0;

        virtual void OnContactPersisted(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                                        JPH::ContactSettings &ioSettings) = 0;

        virtual void OnContactRemoved(JPH::Body* inBody1, JPH::Body* inBody2) = 0;

        const HashString m_TypeHash;
    };

    class HarmonyContactListener final : public JPH::ContactListener {
    public:
        HarmonyContactListener(JPH::PhysicsSystem* physicsSystem);

        ~HarmonyContactListener() override = default;

        void AddContactCallback(RefCntPtr<HarmonyContactListenerCallback> callback);

        template<typename T>
        RefCntPtr<HarmonyContactListenerCallback> GetContactCallback() {
            HashString typeHash = GetTypeHash<T>();
            for (auto c: p_Callbacks) {
                if(typeHash == c->m_TypeHash) {
                    return c;
                }
            }
            return nullptr;
        }

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
        JPH::PhysicsSystem* p_PhysicsSystem;
        Vector<RefCntPtr<HarmonyContactListenerCallback>> p_Callbacks;

    };


}
