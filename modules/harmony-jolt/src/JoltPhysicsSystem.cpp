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
#include "Core/Log.hpp"
#include "ECS/TransformComponent.h"
#include <Jolt/Core/Factory.h>
#include "HarmonyContactListener.h"
#include "HarmonyBroadPhaseLayerInterface.h"
#include "HarmonyBodyActivationListener.h"
#include "HarmonyDebugRenderer.h"
#include "JoltComponents.h"

// Trace to TTY
void TraceImpl(const char* inFMT, ...)
{
    harmony::log::info(inFMT);
}

void FatalError [[noreturn]] (const char* inFMT, ...)
{
    harmony::log::error(inFMT);
}


harmony::JoltPhysicsSystem::JoltPhysicsSystem() : System(GetTypeHash<JoltPhysicsSystem>()),
m_NumJobs(JPH::thread::hardware_concurrency() - 1)
{
    JPH::Trace = TraceImpl;

    JPH::RegisterDefaultAllocator();

    JPH::Factory::sInstance = new JPH::Factory();

    JPH::RegisterTypes();

    const static uint32_t MB_MULTIPLIER = 1024 * 1024;
    m_TempAllocator         = CreateUnique<JPH::TempAllocatorImpl>(s_TempAllocatorSizeMb * MB_MULTIPLIER);
    m_JobSystem             = CreateUnique<JPH::JobSystemThreadPool>(s_MaxPhysicsJobs, s_MaxPhysicsBarriers, m_NumJobs);
    m_JobSystemValidating   = CreateUnique<JPH::JobSystemThreadPool>(s_MaxPhysicsJobs, s_MaxPhysicsBarriers, s_ValidatingJobSystemNumThreads);

    m_BroadPhaseLayerInterface  = CreateUnique<HarmonyBroadPhaseLayerInterface>();
    m_BodyActivationListener    = CreateUnique<HarmonyBodyActivationListener>();
    m_DebugRenderer = CreateUnique<HarmonyDebugRenderer>();
    
}

harmony::JoltPhysicsSystem::~JoltPhysicsSystem()
{

}

void harmony::JoltPhysicsSystem::Init(entt::registry &registry)
{
    m_PhysicsSystem = CreateUnique<JPH::PhysicsSystem>();

    m_PhysicsSystem->Init(s_NumBodies, s_NumBodyMutexes, s_MaxBodyPairs, s_MaxContactConstraints, *m_BroadPhaseLayerInterface, BroadPhaseCanCollide, ObjectCanCollide);
    m_PhysicsSystem->SetPhysicsSettings(m_PhysicsSettings);
    m_PhysicsSystem->SetGravity(s_DefaultGravity);

    if (s_UseContactListener)
    {
        m_ContactListener = CreateUnique<HarmonyContactListener>();
        m_PhysicsSystem->SetContactListener(m_ContactListener.get());
    }

    m_PhysicsSystem->SetBodyActivationListener(m_BodyActivationListener.get());

    m_BodyInterface = &m_PhysicsSystem->GetBodyInterface();

    auto bodyView = registry.view<TransformComponent, JoltBodyComponent>();

    for (auto [e, t, b] : bodyView.each())
    {
        InitBody(e, t, b);
    }

    m_PhysicsSystem->OptimizeBroadPhase();
}

void harmony::JoltPhysicsSystem::Update(entt::registry &registry)
{
    float deltaTime = static_cast<float>(Time::GetFrameTime());
    m_PhysicsSystem->Update(deltaTime, s_CollisionSteps, s_IntegrationSubSteps, m_TempAllocator.get(), m_JobSystem.get());
    JPH::BodyManager::DrawSettings settings;

#ifdef HARMONY_DEBUG
    if (m_DrawDebug)
    {
        JPH::DebugRenderer* dr = m_DebugRenderer.get();
        m_PhysicsSystem->DrawBodies(settings, dr);
        m_PhysicsSystem->DrawConstraints(dr);
    }
#endif
    auto bodyView = registry.view<TransformComponent, JoltBodyComponent>();

    for (auto [e, t, b] : bodyView.each())
    {
        if (t.UpdateCollision)
        {
            b.RequiresUpdate = true;
        }
        if (b.RequiresUpdate)
        {
            InitBody(e, t, b);
        }
    }
}

void harmony::JoltPhysicsSystem::Render(entt::registry &registry)
{

}

void harmony::JoltPhysicsSystem::Cleanup(entt::registry &registry)
{
    m_PhysicsSystem.reset();
}

nlohmann::json harmony::JoltPhysicsSystem::SerializeSystem(entt::registry &registry)
{
    auto j =  nlohmann::json();

    auto bodyView = registry.view<JoltBodyComponent>();

    for (auto [e, b] : bodyView.each())
    {
        j[GetEntityKey(e)] = b;
    }

    return j;
}

void harmony::JoltPhysicsSystem::DeserializeSystem(entt::registry &registry, nlohmann::json systemJson)
{
    for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++)
    {
        entt::entity e = GetEntityFromKey(entry.key());
        nlohmann::json transformJson = entry.value();
        JoltBodyComponent b;
        transformJson.get_to<JoltBodyComponent>(b);
        b.RequiresUpdate = true;
        registry.emplace<JoltBodyComponent>(e, b);
    }
}

void harmony::JoltPhysicsSystem::Refresh() {

}

harmony::JoltBodyComponent& harmony::JoltPhysicsSystem::CreateBodyComponent(entt::registry registry, entt::entity e, JoltBodyShape shape)
{
    if (registry.any_of<JoltBodyComponent>(e))
    {
        harmony::log::warn("JoltPhysicsSystem : Entity {} already has a Body Component.", (uint32_t)e);
        return registry.get<JoltBodyComponent>(e);
    }

    JoltBodyComponent& c = registry.emplace<JoltBodyComponent>(e);
    c.RequiresUpdate = true;
    c.Shape = shape;

    return c;
}

void harmony::JoltPhysicsSystem::DestroyBody(JoltBodyComponent& body)
{
    if (body.Body == nullptr)
    {
        harmony::log::warn("JoltPhysicsSystem : No jolt body with supplied component");
        return;
    }
    m_BodyInterface->DestroyBody(body.Body->GetID());
    delete body.ShapePtr;
}

void harmony::JoltPhysicsSystem::InitBody(entt::entity e, TransformComponent& t, JoltBodyComponent& b)
{
    if (b.Body != nullptr)
    {
        if (!b.Body->IsActive())
        {
            m_BodyInterface->DestroyBody(b.Body->GetID());
        }
        b.Body = nullptr;
    }

    JPH::BodyCreationSettings bodyCreationSettings; 
    switch (b.Shape)
    {
        case JoltBodyShape::Box:
        {
            b.ShapePtr = new JPH::BoxShape(JPH::Vec3(t.Scale.x, t.Scale.y, t.Scale.x));
        }
        break;
        case JoltBodyShape::Sphere:
        {
            // TOOD: Improve to be anything better.
            float scaleNorm = (t.Scale.x + t.Scale.y + t.Scale.x) / 3.0f;
            b.ShapePtr = new JPH::SphereShape(scaleNorm);
        }
        break;
        case JoltBodyShape::Capsule:
        {
            b.ShapePtr = new JPH::CapsuleShape(t.Scale.x, t.Scale.y / 2.0f);
        }
        break;
        case JoltBodyShape::Cylinder:
        {
            b.ShapePtr = new JPH::CylinderShape(t.Scale.x, t.Scale.y / 2.0f);
        }
        break;
        case JoltBodyShape::MeshShape:
        {    // TODO
        }
        break;
    }
    bodyCreationSettings.SetShape(b.ShapePtr);

    bodyCreationSettings.mMotionType    = b.MotionType;
    bodyCreationSettings.mObjectLayer   = b.MotionType == JPH::EMotionType::Static ? Layers::NON_MOVING : Layers::MOVING;

    b.Body = m_BodyInterface->CreateBody(bodyCreationSettings);

    m_BodyInterface->AddBody(b.Body->GetID(), JPH::EActivation::Activate);

    b.RequiresUpdate = false;
}
