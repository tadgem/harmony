#pragma once

#include "Jolt/Jolt.h"
#include "Jolt/Physics/Body/Body.h"
#include "ThirdParty/json.hpp"

namespace harmony {
    enum JoltBodyShape {
        Box = 0,
        Sphere,
        Capsule,
        Cylinder,
        MeshShape,
        Compound
    };

    NLOHMANN_JSON_SERIALIZE_ENUM(JoltBodyShape, {
        { Box, "Box" },
        { Sphere, "Sphere" },
        { Capsule, "Capsule" },
        { Cylinder, "Cylinder" },
        { MeshShape, "MeshShape" },
        { Compound, "Compound" },
    })

    NLOHMANN_JSON_SERIALIZE_ENUM(JPH::EMotionType, {
        { JPH::EMotionType::Static, "Static" },
        { JPH::EMotionType::Kinematic, "Kinematic" },
        { JPH::EMotionType::Dynamic, "Dynamic" }
    })

    struct JoltBodyComponent {
        JPH::Body *Body = nullptr;
        JPH::Shape *ShapePtr = nullptr;
        JPH::EMotionType MotionType;
        JoltBodyShape Shape;
        float Restitution = 0.0f;
        float Friction = 1.0f;

        bool RequiresUpdate = true;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(JoltBodyComponent, MotionType, Shape, Restitution, Friction)
    };

    struct JoltCompoundShapeComponent {
        // todo: implement me
    };
}