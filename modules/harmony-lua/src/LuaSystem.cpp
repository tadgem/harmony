#include "LuaSystem.h"
#include "LuaProgramComponent.h"
#include "LuaScriptAsset.h"


harmony::LuaSystem::LuaSystem(Ref<LuaProgramComponent> luaPc) : System(GetTypeHash<LuaScriptAsset>()), p_LuaProgramComponent(luaPc)
{
}

void harmony::LuaSystem::Init(entt::registry& registry)
{
}

void harmony::LuaSystem::Update(entt::registry& registry)
{
}

void harmony::LuaSystem::Render(entt::registry& registry)
{
}

void harmony::LuaSystem::Cleanup(entt::registry& registry)
{
}

nlohmann::json harmony::LuaSystem::SerializeSystem(entt::registry& registry)
{
    return nlohmann::json();
}

void harmony::LuaSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
}

void harmony::LuaSystem::Refresh()
{
}