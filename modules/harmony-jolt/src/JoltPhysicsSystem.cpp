#include "JoltPhysicsSystem.h"
#include "Core/Memory.h"

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
