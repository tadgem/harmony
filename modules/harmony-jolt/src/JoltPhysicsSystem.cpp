#include "JoltPhysicsSystem.h"
#include "Core/Memory.h"
#include "Core/Time.h"
#include <Jolt/Physics/Collision/CollideShape.h>
#include "Jolt/Core/JobSystem.h"
#include "Jolt/Core/Memory.h"
#include "Jolt/Physics/PhysicsSystem.h"
#include <Jolt/Core/JobSystemThreadPool.h>
#include <Jolt/Geometry/OrientedBox.h>
#include <Jolt/Physics/Body/BodyCreationSettings.h>
#include <Jolt/Physics/PhysicsScene.h>
#include <Jolt/Physics/Collision/RayCast.h>
#include <Jolt/Physics/Collision/ShapeCast.h>
#include <Jolt/Physics/Collision/CastResult.h>
#include <Jolt/Physics/Collision/CollidePointResult.h>
#include <Jolt/Physics/Collision/AABoxCast.h>
#include <Jolt/Physics/Collision/Shape/HeightFieldShape.h>
#include <Jolt/Physics/Character/CharacterVirtual.h>
#include <Jolt/Physics/Collision/ObjectLayer.h>
#include "Jolt/Physics/PhysicsSettings.h"
#include <Jolt/Physics/Collision/BroadPhase/BroadPhaseLayer.h>
#include <Jolt/Core/StreamWrapper.h>
#include <Jolt/Physics/StateRecorderImpl.h>
#include <Jolt/Physics/Collision/CollisionCollectorImpl.h>
#include <Jolt/Physics/Collision/Shape/MeshShape.h>
#include <Jolt/Physics/Collision/Shape/SphereShape.h>
#include <Jolt/Physics/Collision/Shape/BoxShape.h>
#include <Jolt/Physics/Collision/Shape/ConvexHullShape.h>
#include <Jolt/Physics/Collision/Shape/CapsuleShape.h>
#include <Jolt/Physics/Collision/Shape/TaperedCapsuleShape.h>
#include <Jolt/Physics/Collision/Shape/CylinderShape.h>
#include <Jolt/Physics/Collision/Shape/TriangleShape.h>
#include <Jolt/Physics/Collision/Shape/StaticCompoundShape.h>
#include <Jolt/Physics/Collision/Shape/MutableCompoundShape.h>
#include <Jolt/Physics/Collision/Shape/ScaledShape.h>
#include <Jolt/Physics/Collision/NarrowPhaseStats.h>
#include <Jolt/Physics/Constraints/DistanceConstraint.h>
#include <Jolt/Physics/Constraints/PulleyConstraint.h>
#include <Jolt/RegisterTypes.h>
#include <Jolt/Core/Factory.h>
#include "HarmonyContactListener.h"
#include "HarmonyBroadPhaseLayerInterface.h"
#include "HarmonyBodyActivationListener.h"

// Create a factory

harmony::JoltPhysicsSystem::JoltPhysicsSystem() : System(GetTypeHash<JoltPhysicsSystem>()),
m_NumJobs(JPH::thread::hardware_concurrency() - 1)
{
    JPH::RegisterDefaultAllocator();

    JPH::Factory::sInstance = new JPH::Factory();

    JPH::RegisterTypes();

    const static uint32_t MB_MULTIPLIER = 1024 * 1024;
    m_TempAllocator         = CreateUnique<JPH::TempAllocatorImpl>(s_TempAllocatorSizeMb * MB_MULTIPLIER);
    m_JobSystem             = CreateUnique<JPH::JobSystemThreadPool>(s_MaxPhysicsJobs, s_MaxPhysicsBarriers, m_NumJobs);
    m_JobSystemValidating   = CreateUnique<JPH::JobSystemThreadPool>(s_MaxPhysicsJobs, s_MaxPhysicsBarriers, s_ValidatingJobSystemNumThreads);

    m_BroadPhaseLayerInterface  = CreateUnique<HarmonyBroadPhaseLayerInterface>();
    m_BodyActivationListener    = CreateUnique<HarmonyBodyActivationListener>();
    m_PhysicsSystem             = CreateUnique<JPH::PhysicsSystem>();

    m_PhysicsSystem->Init(s_NumBodies, s_NumBodyMutexes, s_MaxBodyPairs, s_MaxContactConstraints, *m_BroadPhaseLayerInterface, BroadPhaseCanCollide, ObjectCanCollide );
    m_PhysicsSystem->SetPhysicsSettings(m_PhysicsSettings);
    m_PhysicsSystem->SetGravity(s_DefaultGravity);

    if(s_UseContactListener)
    {
        m_ContactListener = CreateUnique<HarmonyContactListener>();
        m_PhysicsSystem->SetContactListener(m_ContactListener.get());
    }

    m_PhysicsSystem->SetBodyActivationListener(m_BodyActivationListener.get());

    m_BodyInterface = &m_PhysicsSystem->GetBodyInterface();
}

harmony::JoltPhysicsSystem::~JoltPhysicsSystem()
{

}

void harmony::JoltPhysicsSystem::Init(entt::registry &registry)
{
    const float inSize = 200.0f;
    const float scale = 1.0f;
    using namespace JPH;
    Body* floor = m_BodyInterface->CreateBody(BodyCreationSettings(new BoxShape(scale * Vec3(0.5f * inSize, 1.0f, 0.5f * inSize), 0.0f), RVec3(scale * Vec3(0.0f, -1.0f, 0.0f)), Quat::sIdentity(), EMotionType::Static, Layers::NON_MOVING));
    m_BodyInterface->AddBody(floor->GetID(), EActivation::DontActivate);

    RefConst<Shape> box_shape = new BoxShape(Vec3(0.5f, 1.0f, 2.0f));

    // Dynamic body 1
    Body &body1 = *m_BodyInterface->CreateBody(BodyCreationSettings(box_shape, RVec3(0, 10, 0), Quat::sIdentity(), EMotionType::Dynamic, Layers::MOVING));
    m_BodyInterface->AddBody(body1.GetID(), EActivation::Activate);

    // Dynamic body 2
    Body &body2 = *m_BodyInterface->CreateBody(BodyCreationSettings(box_shape, RVec3(5, 10, 0), Quat::sRotation(Vec3::sAxisX(), 0.25f * JPH_PI), EMotionType::Dynamic, Layers::MOVING));
    m_BodyInterface->AddBody(body2.GetID(), EActivation::Activate);

    // Dynamic body 3
    Body &body3 = *m_BodyInterface->CreateBody(BodyCreationSettings(new SphereShape(2.0f), RVec3(10, 10, 0), Quat::sRotation(Vec3::sAxisX(), 0.25f * JPH_PI), EMotionType::Dynamic, Layers::MOVING));
    m_BodyInterface->AddBody(body3.GetID(), EActivation::Activate);

    m_PhysicsSystem->OptimizeBroadPhase();
}

void harmony::JoltPhysicsSystem::Update(entt::registry &registry)
{
    float deltaTime = static_cast<float>(Time::GetFrameTime());
    m_PhysicsSystem->Update(deltaTime, s_CollisionSteps, s_IntegrationSubSteps, m_TempAllocator.get(), m_JobSystem.get());
}

void harmony::JoltPhysicsSystem::Render(entt::registry &registry)
{

}

void harmony::JoltPhysicsSystem::Cleanup(entt::registry &registry)
{

}

nlohmann::json harmony::JoltPhysicsSystem::SerializeSystem(entt::registry &registry)
{
    return nlohmann::json();
}

void harmony::JoltPhysicsSystem::DeserializeSystem(entt::registry &registry, nlohmann::json systemJson)
{

}

void harmony::JoltPhysicsSystem::Refresh() {

}
