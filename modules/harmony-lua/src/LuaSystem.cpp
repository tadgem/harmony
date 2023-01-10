#include "LuaSystem.h"
#include "LuaProgramComponent.h"
#include "LuaScriptAsset.h"
#include "LuaComponent.h"
#include "Assets/AssetManager.h"

harmony::LuaSystem::LuaSystem(AssetManager& am, Ref<LuaProgramComponent> luaPc) : System(GetTypeHash<LuaComponent>()), p_LuaProgramComponent(luaPc), p_AssetManager(am)
{
}

void harmony::LuaSystem::Init(entt::registry& registry)
{
    auto view = registry.view<LuaComponent>();

    sol::state& state = p_LuaProgramComponent->p_State;
    for (auto [entity, lua] : view.each())
    {
        state.do_string(lua.m_LuaScriptAsset.m_Script, lua.m_LuaScriptAsset.m_Name);

        sol::function startFx   = state["start"];
        sol::function updateFx  = state["update"];
        sol::function cleanupFx = state["cleanup"];

        if (startFx.valid())
        {
            lua.m_HasStart = true;
            lua.m_Start = startFx;
            startFx();
        }

        if (updateFx.valid())
        {
            lua.m_HasUpdate = true;
            lua.m_Update = updateFx;
        }

        if (cleanupFx.valid())
        {
            lua.m_HasCleanup = true;
            lua.m_Cleanup = cleanupFx;
        }
    }
}

void harmony::LuaSystem::Update(entt::registry& registry)
{
    auto view = registry.view<LuaComponent>();
    sol::state& state = p_LuaProgramComponent->p_State;
    for (auto [entity, lua] : view.each())
    {
        if (lua.m_HasUpdate)
        {
            lua.m_Update();
        }
    }
}

void harmony::LuaSystem::Render(entt::registry& registry)
{
}

void harmony::LuaSystem::Cleanup(entt::registry& registry)
{
    auto view = registry.view<LuaComponent>();
    sol::state& state = p_LuaProgramComponent->p_State;
    for (auto [entity, lua] : view.each())
    {
        if (lua.m_HasCleanup)
        {
            lua.m_Cleanup();
        }
    }
}

nlohmann::json harmony::LuaSystem::SerializeSystem(entt::registry& registry)
{
    nlohmann::json j;

    auto view = registry.view<LuaComponent>();

    for (auto [e, lua] : view.each())
    {
        j[GetEntityKey(e)] = lua;
    }

    return j;
}

void harmony::LuaSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
    for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++)
    {
        entt::entity e = GetEntityFromKey(entry.key());
        nlohmann::json luaJson = entry.value();
        LuaComponent lc;
        luaJson.get_to<LuaComponent>(lc);

        auto luaWr = p_AssetManager.GetAsset<LuaScriptAsset>(lc.m_LuaScriptAsset.m_Handle);
        lc.m_LuaScriptAsset = *luaWr.lock();
        registry.emplace<LuaComponent>(e, lc);
    }
}

void harmony::LuaSystem::Refresh()
{
}
