#include "HarmonyContactListener.h"

harmony::HarmonyContactListener::HarmonyContactListener() {

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
}

void harmony::HarmonyContactListener::OnContactPersisted(const JPH::Body &inBody1, const JPH::Body &inBody2,
                                                         const JPH::ContactManifold &inManifold,
                                                         JPH::ContactSettings &ioSettings) {
    ContactListener::OnContactPersisted(inBody1, inBody2, inManifold, ioSettings);
}

void harmony::HarmonyContactListener::OnContactRemoved(const JPH::SubShapeIDPair &inSubShapePair) {
    ContactListener::OnContactRemoved(inSubShapePair);
}
