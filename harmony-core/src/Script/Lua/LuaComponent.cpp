#include <optick.h>
#include "Script/Lua/LuaComponent.h"
#include "Assets/Asset.h"
#include "Core/Log.hpp"
harmony::LuaComponent::LuaComponent() : m_LuaScriptAsset("", "") {
    OPTICK_EVENT();
    m_HasStart = false;
    m_HasUpdate = false;
    m_HasCleanup = false;
}

harmony::LuaComponent harmony::LuaComponent::Create(sol::state &state, LuaScriptAsset scriptAsset) {

    LuaComponent lua =  harmony::LuaComponent();
    lua.m_LuaScriptAsset = scriptAsset;
    sol::environment env(state, sol::create, state.globals());

    auto compilationResult = state.do_string(scriptAsset.m_Script, env);

    if (!compilationResult.valid()) {
        sol::error err = compilationResult;
        std::string what = err.what();
        harmony::log::error(
                "LuaComponent : CreateLuaComponent : {} : in compiling script {}", what, scriptAsset.m_Name);
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

    lua.m_Env = env;

    return lua;
}
