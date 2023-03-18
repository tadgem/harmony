#include "HarmonyBroadPhaseLayerInterface.h"

harmony::HarmonyBroadPhaseLayerInterface::HarmonyBroadPhaseLayerInterface() 
{
	m_ObjectToBroadPhase[Layers::UNUSED1] = BroadPhaseLayers::UNUSED;
	m_ObjectToBroadPhase[Layers::UNUSED2] = BroadPhaseLayers::UNUSED;
	m_ObjectToBroadPhase[Layers::UNUSED3] = BroadPhaseLayers::UNUSED;
	m_ObjectToBroadPhase[Layers::UNUSED4] = BroadPhaseLayers::UNUSED;
	m_ObjectToBroadPhase[Layers::NON_MOVING] = BroadPhaseLayers::NON_MOVING;
	m_ObjectToBroadPhase[Layers::MOVING] = BroadPhaseLayers::MOVING;
	m_ObjectToBroadPhase[Layers::DEBRIS] = BroadPhaseLayers::DEBRIS;
	m_ObjectToBroadPhase[Layers::SENSOR] = BroadPhaseLayers::SENSOR;
}

JPH::uint harmony::HarmonyBroadPhaseLayerInterface::GetNumBroadPhaseLayers() const
{
    return Layers::NUM_LAYERS;
}

JPH::BroadPhaseLayer harmony::HarmonyBroadPhaseLayerInterface::GetBroadPhaseLayer(JPH::ObjectLayer inLayer) const
{
	//TODO: Add assert
	return m_ObjectToBroadPhase[inLayer];
}

const char *harmony::HarmonyBroadPhaseLayerInterface::GetBroadPhaseLayerName(JPH::BroadPhaseLayer inLayer) const
{
	switch ((JPH::BroadPhaseLayer::Type)inLayer)
	{
	case (JPH::BroadPhaseLayer::Type)BroadPhaseLayers::NON_MOVING:	return "NON_MOVING";
	case (JPH::BroadPhaseLayer::Type)BroadPhaseLayers::MOVING:		return "MOVING";
	case (JPH::BroadPhaseLayer::Type)BroadPhaseLayers::DEBRIS:		return "DEBRIS";
	case (JPH::BroadPhaseLayer::Type)BroadPhaseLayers::SENSOR:		return "SENSOR";
	case (JPH::BroadPhaseLayer::Type)BroadPhaseLayers::UNUSED:		return "UNUSED";
	default:													return "INVALID";
	}
}
