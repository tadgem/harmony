#pragma once

#include "Jolt/Jolt.h"
#include "Jolt/Physics/Collision/BroadPhase/BroadPhaseLayer.h"

namespace harmony {
    namespace Layers {
        static constexpr uint8_t UNUSED1 = 0; // 4 unused values so that broadphase layers values don't match with object layer values (for testing purposes)
        static constexpr uint8_t UNUSED2 = 1;
        static constexpr uint8_t UNUSED3 = 2;
        static constexpr uint8_t UNUSED4 = 3;
        static constexpr uint8_t NON_MOVING = 4;
        static constexpr uint8_t MOVING = 5;
        static constexpr uint8_t DEBRIS = 6; // Example: Debris collides only with NON_MOVING
        static constexpr uint8_t SENSOR = 7; // Sensors only collide with MOVING objects
        static constexpr uint8_t NUM_LAYERS = 8;
    };

    /// Broadphase layers
    namespace BroadPhaseLayers {
        static constexpr JPH::BroadPhaseLayer NON_MOVING(0);
        static constexpr JPH::BroadPhaseLayer MOVING(1);
        static constexpr JPH::BroadPhaseLayer DEBRIS(2);
        static constexpr JPH::BroadPhaseLayer SENSOR(3);
        static constexpr JPH::BroadPhaseLayer UNUSED(4);
        static constexpr uint8_t NUM_LAYERS(5);
    };

    /// Function that determines if two object layers can collide
    static inline bool ObjectCanCollide(JPH::ObjectLayer inObject1, JPH::ObjectLayer inObject2) {

    };

    class HarmonyBroadPhaseLayerInterface : public JPH::BroadPhaseLayerInterface {
    public:
        HarmonyBroadPhaseLayerInterface();

        ~HarmonyBroadPhaseLayerInterface() override = default;

        JPH::uint GetNumBroadPhaseLayers() const override;

        JPH::BroadPhaseLayer GetBroadPhaseLayer(JPH::ObjectLayer inLayer) const override;

        const char *GetBroadPhaseLayerName(JPH::BroadPhaseLayer inLayer) const override;

    protected:
        JPH::BroadPhaseLayer m_ObjectToBroadPhase[Layers::NUM_LAYERS];
    };

    class HarmonyObjectVsBroadPhaseLayerFilter : public JPH::ObjectVsBroadPhaseLayerFilter
    {
    public:
        HarmonyObjectVsBroadPhaseLayerFilter();

        bool ShouldCollide(JPH::ObjectLayer inLayer1, JPH::BroadPhaseLayer inLayer2) const override;


    };

class HarmonyObjectLayerPairFilter : public JPH::ObjectLayerPairFilter
{
public:
    bool ShouldCollide(JPH::ObjectLayer inLayer1, JPH::ObjectLayer inLayer2) const override;
};


}