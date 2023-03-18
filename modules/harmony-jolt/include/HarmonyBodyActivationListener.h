#pragma once

#include "Jolt/Jolt.h"
#include "Jolt/Physics/Body/BodyActivationListener.h"

namespace harmony
{
    class HarmonyBodyActivationListener : public JPH::BodyActivationListener
    {
    public:
        ~HarmonyBodyActivationListener() override = default;

        void OnBodyActivated(const JPH::BodyID &inBodyID, JPH::uint64 inBodyUserData) override;

        void OnBodyDeactivated(const JPH::BodyID &inBodyID, JPH::uint64 inBodyUserData) override;

    public:

    };
}