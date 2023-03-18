#include "JoltPhysicsSystem.h"
#include "Core/Memory.h"
#include <Jolt/Physics/Collision/CollideShape.h>
#include <Jolt/Physics/Collision/ObjectLayer.h>
#include "Jolt/Core/JobSystem.h"
#include "Jolt/Core/TempAllocator.h"
#include "Jolt/Physics/PhysicsSystem.h"
#include "Jolt/Physics/PhysicsSettings.h"
#include <Jolt/Physics/Collision/BroadPhase/BroadPhaseLayer.h>

harmony::JoltPhysicsSystem::JoltPhysicsSystem() : System(GetTypeHash<JoltPhysicsSystem>())
{

}

harmony::JoltPhysicsSystem::~JoltPhysicsSystem() {

}

void harmony::JoltPhysicsSystem::Init(entt::registry &registry)
{

}

void harmony::JoltPhysicsSystem::Update(entt::registry &registry)
{

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
