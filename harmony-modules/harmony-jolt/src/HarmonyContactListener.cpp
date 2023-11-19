#include "HarmonyContactListener.h"
#include "Core/Log.hpp"

harmony::HarmonyContactListenerCallback::HarmonyContactListenerCallback(HashString typeHash) : m_TypeHash(typeHash)
{
}

harmony::HarmonyContactListener::HarmonyContactListener(JPH::PhysicsSystem* physicsSystem) :
p_PhysicsSystem(physicsSystem)
{
    p_Callbacks = Vector<RefCntPtr<HarmonyContactListenerCallback>>();
}

JPH::ValidateResult
harmony::HarmonyContactListener::OnContactValidate(const JPH::Body &inBody1, const JPH::Body &inBody2,
                                                   JPH::RVec3Arg inBaseOffset,
                                                   const JPH::CollideShapeResult &inCollisionResult) {
    return ContactListener::OnContactValidate(inBody1, inBody2, inBaseOffset, inCollisionResult);
}

void harmony::HarmonyContactListener::OnContactAdded(const JPH::Body &inBody1, const JPH::Body &inBody2,
                                                     const JPH::ContactManifold &inManifold,
                                                     JPH::ContactSettings &ioSettings) {
    ContactListener::OnContactAdded(inBody1, inBody2, inManifold, ioSettings);
    for(auto& c : p_Callbacks)
    {
        c->OnContactAdded(inBody1, inBody2, inManifold, ioSettings);
    }
}

void harmony::HarmonyContactListener::OnContactPersisted(const JPH::Body &inBody1, const JPH::Body &inBody2,
                                                         const JPH::ContactManifold &inManifold,
                                                         JPH::ContactSettings &ioSettings) {

    ContactListener::OnContactPersisted(inBody1, inBody2, inManifold, ioSettings);
    for(auto& c : p_Callbacks)
    {
        c->OnContactPersisted(inBody1, inBody2, inManifold, ioSettings);
    }
}

void harmony::HarmonyContactListener::OnContactRemoved(const JPH::SubShapeIDPair &inSubShapePair) {
    ContactListener::OnContactRemoved(inSubShapePair);

    // JPH::Body* a = p_PhysicsSystem->GetBodyLockInterface().TryGetBody(inSubShapePair.GetBody1ID());
    // JPH::Body* b = p_PhysicsSystem->GetBodyLockInterface().TryGetBody(inSubShapePair.GetBody2ID());
    //
    // if(!a) {
    //     log::error("HarmonyContactListener::OnContactRemoved : Could not get Body A from sub shape pair.");
    //     return;
    // }
    //
    // if(!b) {
    //     log::error("HarmonyContactListener::OnContactRemoved : Could not get Body B from sub shape pair.");
    //     return;
    // }
    //
    // for(auto& c : p_Callbacks)
    // {
    //     c->OnContactRemoved(a, b);
    // }
    //
    // p_PhysicsSystem->GetBodyInterface().
}

void harmony::HarmonyContactListener::AddContactCallback(
        harmony::RefCntPtr<harmony::HarmonyContactListenerCallback> callback) {
    p_Callbacks.emplace_back(callback);
}
