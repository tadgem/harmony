//
// Created by liam_ on 9/24/2023.
//
#include "MonoSystem.h"


harmony::MonoSystem::MonoSystem(WeakRef<MonoProgramComponent> mono) : System(GetTypeHash<MonoSystem>()), p_Mono(mono)
{
}

void harmony::MonoSystem::Init(entt::registry& registry)
{
}

void harmony::MonoSystem::Update(entt::registry& registry)
{
}

void harmony::MonoSystem::Render(entt::registry& registry)
{
}

void harmony::MonoSystem::Cleanup(entt::registry& registry)
{
}

nlohmann::json harmony::MonoSystem::SerializeSystem(entt::registry& registry)
{
    return nlohmann::json();
}

void harmony::MonoSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
}

void harmony::MonoSystem::Refresh()
{
}
