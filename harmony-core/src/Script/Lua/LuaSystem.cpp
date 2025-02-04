#include "Script/Lua/LuaSystem.h"
#include "Script/Lua/LuaProgramComponent.h"
#include "Script/Lua/LuaScriptAsset.h"
#include "Script/Lua/LuaScriptEntity.h"
#include "Script/Lua/LuaComponent.h"
#include "Assets/AssetManager.h"
#include "Core/Scene.h"
#include "STL/Thread.h"
#include "Core/Program.h"
#include "STL/String.h"
#include <optick.h>

harmony::LuaSystem::LuaSystem(AssetManager &am, RefCntPtr<LuaProgramComponent> luaPc) : System(GetTypeHash<LuaSystem>()),
                                                                                        p_LuaProgramComponent(luaPc),
                                                                                        p_AssetManager(am) {
}

void harmony::LuaSystem::Init(entt::registry &registry) {
    OPTICK_EVENT();

    auto view = registry.view<LuaComponent>();
    sol::state &state = p_LuaProgramComponent->p_State;
    for (auto [entity, lua]: view.each()) {
        p_CurrentEntity = entity;
        InitEntityScript(entity, registry, state, lua);

        if (lua.m_HasStart && lua.m_Start) {
            sol::protected_function_result result = lua.m_Start();
            if (!result.valid()) {
                sol::error err = result;
                String what = err.what();
                String entityStr = ToString((uint32_t) entity);
                harmony::log::error(
                        "LuaSystem : InitEntityScript : Error : {} : in executing start() for Entity : {} : Script : {}",
                        what, entityStr, lua.m_LuaScriptAsset.m_Handle.Path);
            }
        }
    }
}

void harmony::LuaSystem::Update(entt::registry &registry) {
    OPTICK_EVENT();

    auto view = registry.view<LuaComponent>();
    sol::state &state = p_LuaProgramComponent->p_State;
    for (auto [entity, lua]: view.each()) {
        p_CurrentEntity = entity;
        if (lua.m_HasUpdate && lua.m_Update) {
            try {
                auto result = lua.m_Update();
                if (!result.valid()) {
                    sol::error err = result;
                    String what = err.what();
                    String entityStr = ToString((uint32_t) entity);
                    harmony::log::error("LuaSystem : Error : {} : in executing update() for Entity : {} : Script : {}",
                                        what, entityStr, lua.m_LuaScriptAsset.m_Handle.Path);
                }
            }
            catch (...) {
                harmony::log::error("LuaSystem : Failed running update, resetting.");
            }
        }
    }
}

void harmony::LuaSystem::Render(entt::registry &registry) {
    OPTICK_EVENT();

}

void harmony::LuaSystem::Cleanup(entt::registry &registry) {
    OPTICK_EVENT();

    auto view = registry.view<LuaComponent>();
    sol::state &state = p_LuaProgramComponent->p_State;
    for (auto [entity, lua]: view.each()) {
        p_CurrentEntity = entity;

        if (lua.m_HasCleanup && lua.m_Cleanup) {
            auto result = lua.m_Cleanup();
            if (!result.valid()) {
                sol::error err = result;
                String what = err.what();
                String entityStr = ToString((uint32_t) entity);
                harmony::log::error("LuaSystem : Error : {} : in executing cleanup() for Entity : {} : Script : {}",
                                    what, entityStr, lua.m_LuaScriptAsset.m_Handle.Path);
            }
        }
    }
}

harmony::Json harmony::LuaSystem::SerializeSystem(entt::registry &registry) {
    OPTICK_EVENT();

    Json j;
    auto view = registry.view<LuaComponent>();

    for (auto [e, lua]: view.each()) {
        j[GetEntityKey(e)] = lua;
    }

    return j;
}

void harmony::LuaSystem::DeserializeSystem(entt::registry &registry, Json systemJson) {
    OPTICK_EVENT();

    for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        Json luaJson = entry.value();
        DeserializeEntity(registry, e, luaJson);
    }
}

harmony::Json harmony::LuaSystem::SerializeEntity(entt::registry& registry, entt::entity e)
{
    Json j;

    if(registry.any_of<LuaComponent>(e))
    {
        LuaComponent& lc = registry.get<LuaComponent>(e);
        j = lc;
    }

    return j;
}

void harmony::LuaSystem::DeserializeEntity(entt::registry& registry, entt::entity e, Json entityJson)
{
    LuaComponent lc;
    entityJson.get_to<LuaComponent>(lc);
    AssetHandle ah = lc.m_LuaScriptAsset.m_Handle;
    auto luaWr = p_AssetManager.GetAsset<LuaScriptAsset>(lc.m_LuaScriptAsset.m_Handle);
    if (luaWr.expired()) {
        harmony::log::warn("LuaSystem : Could not find asset with handle : {}", ah.Path);
        return;
    }

    lc.m_LuaScriptAsset = *luaWr.lock();

    lc.m_LuaScriptAsset.m_Handle = ah;
    registry.emplace<LuaComponent>(e, lc);
}

void harmony::LuaSystem::Refresh() {
    OPTICK_EVENT();
}

entt::entity harmony::LuaSystem::GetCurrentEntity() {
    OPTICK_EVENT();
    return p_CurrentEntity;
}

void harmony::LuaSystem::UpdateScripts(WeakPtr<Scene> scene) {
    OPTICK_EVENT();
    if (scene.expired()) {
        harmony::log::error("LuaSystem : Cannot update scripts, scene is expired!");
        return;
    }

    auto scriptHandles = p_AssetManager.GetLoadedAssets<LuaScriptAsset>();
    entt::registry &r = scene.lock()->m_Registry;
    auto luaView = r.view<LuaComponent>();

    for (auto [e, lua]: luaView.each()) {
        auto luaScriptAsset = lua.m_LuaScriptAsset;

        for (int i = 0; i < scriptHandles.size(); i++) {
            if (scriptHandles[i] == luaScriptAsset.m_Handle) {
                auto luaAsset = p_AssetManager.GetAsset<LuaScriptAsset>(scriptHandles[i]);
                if (luaAsset.expired()) {
                    harmony::log::warn("LuaSystem : Script with handle : {} : not found in asset manager.",
                                       scriptHandles[i].Path);
                    break;
                }

                auto l = luaAsset.lock();

                lua.m_LuaScriptAsset = *l;
                lua.m_LuaScriptAsset.m_Handle = scriptHandles[i];

                InitEntityScript(e, r, p_LuaProgramComponent->p_State, lua);
            }
        }
    }

}

void harmony::LuaSystem::InitEntityScript(entt::entity e, entt::registry &r, sol::state &state, LuaComponent &lua) {
    OPTICK_EVENT();
    String chunkName = ToString(static_cast<uint32_t>(e));
    sol::environment env(state, sol::create, state.globals());
    // TODO: fix this.
    env["this_entity"] = LuaScriptEntity(Program::Get()->GetActiveScene().lock().get(), e);

    auto compilationResult = state.do_string(lua.m_LuaScriptAsset.m_Script, env);

    if (!compilationResult.valid()) {
        sol::error err = compilationResult;
        String what = err.what();
        String entityStr = ToString((uint32_t) e);
        harmony::log::error(
                "LuaSystem : InitEntityScript : Error : {} : in compiling file for Entity : {} : Script : {}", what,
                entityStr, lua.m_LuaScriptAsset.m_Handle.Path);
    }

    sol::function startFx = env["start"];
    sol::function updateFx = env["update"];
    sol::function cleanupFx = env["cleanup"];

    if (startFx.valid()) {
        lua.m_HasStart = true;
        lua.m_Start = startFx;
    }

    if (updateFx.valid()) {
        lua.m_HasUpdate = true;
        lua.m_Update = updateFx;
    }

    if (cleanupFx.valid()) {
        lua.m_HasCleanup = true;
        lua.m_Cleanup = cleanupFx;
    }
}
