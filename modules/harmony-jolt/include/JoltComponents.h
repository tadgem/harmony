#pragma once
#include "Jolt/Jolt.h"
#include "Jolt/Physics/Body/Body.h"

namespace harmony
{
    enum JoltBodyShape
    {
        Box = 0,
        Sphere,
        Capsule,
        Cylinder,
        Mesh
    };

    struct JoltBodyComponent
    {
        JPH::Body*          Body = nullptr;
        JPH::EMotionType    MotionType;
        JoltBodyShape       Shape;

        bool                RequiresUpdate = true;
    };
}