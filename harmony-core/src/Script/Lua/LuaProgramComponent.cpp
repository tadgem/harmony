#include <optick.h>
#include "Script/Lua/LuaProgramComponent.h"
#include "Script/Lua/LuaComponent.h"
#include "Script/Lua/LuaScriptAsset.h"
#include "Core/Log.hpp"
#include "Assets/AssetManager.h"
harmony::LuaProgramComponent::LuaProgramComponent(AssetManager &am) : ProgramComponent(
        GetTypeHash<LuaProgramComponent>()), p_AssetManager(am) {

}

void harmony::LuaProgramComponent::Init() {
    OPTICK_EVENT();
    p_State.open_libraries(sol::lib::base, sol::lib::package, sol::lib::jit, sol::lib::ffi);
    // harmony::InitHarmony(p_State);
    RedirectPrintOutput();

    p_LuaProgramScripts.clear();

    for (AssetHandle ah: m_LuaProgramScripts) {
        auto script = p_AssetManager.GetAsset<LuaScriptAsset>(ah).lock();
        if(!script) {
            harmony::log::error("LuaProgramComponent : Failed to get script from asset path : {}", ah.Path);
            continue;
        }
        auto lc = LuaComponent::Create(p_State, *script);
        if(!lc.m_HasStart) {
            continue;
        }

        try {
            auto result = lc.m_Start();
            if (!result.valid()) {
                sol::error err = result;
                String what = err.what();
                harmony::log::error("LuaSystem : Error : {} : in executing start() for : Script : {}",
                                    what, ah.Path);
            }
        }
        catch (...) {
            harmony::log::error("LuaSystem : Failed running start, resetting.");
        }
        p_LuaProgramScripts.emplace_back(lc);
    }
}

void harmony::LuaProgramComponent::Update() {
    OPTICK_EVENT();
    for(LuaComponent& lc : p_LuaProgramScripts) {
        if(!lc.m_HasUpdate) {
            continue;
        }
        try {
            auto result = lc.m_Update();
            if (!result.valid()) {
                sol::error err = result;
                String what = err.what();
                harmony::log::error("LuaSystem : Error : {} : in executing update() for : Script : {}",
                                    what, lc.m_LuaScriptAsset.m_Name);
            }
        }
        catch (...) {
            harmony::log::error("LuaSystem : Failed running update, resetting.");
        }
    }
}

void harmony::LuaProgramComponent::Render() {
    OPTICK_EVENT();
}

void harmony::LuaProgramComponent::Cleanup() {
    for(LuaComponent& lc : p_LuaProgramScripts) {
        if(!lc.m_HasCleanup) {
            continue;
        }
        try {
            auto result = lc.m_Cleanup();
            if (!result.valid()) {
                sol::error err = result;
                String what = err.what();
                harmony::log::error("LuaSystem : Error : {} : in executing cleanup() for : Script : {}",
                                    what, lc.m_LuaScriptAsset.m_Name);
            }
        }
        catch (...) {
            harmony::log::error("LuaSystem : Failed running cleanup, resetting.");
        }
    }
    OPTICK_EVENT();
}

harmony::Json harmony::LuaProgramComponent::ToJson() {
    OPTICK_EVENT();
    auto j = Json();

    auto& scripts = j["program-scripts"];

    for(AssetHandle& ah : m_LuaProgramScripts)
    {
        scripts.emplace_back(ah);
    }

    return j;
}

void harmony::LuaProgramComponent::FromJson(const Json &json) {
    OPTICK_EVENT();
    if(!json.contains("program-scripts"))
    {
        return;
    }
    for(auto assetHandleJson : json["program-scripts"])
    {
        AssetHandle ah = assetHandleJson;
        m_LuaProgramScripts.emplace_back(ah);
    }
}

static int l_my_print(lua_State *L) {
    int nargs = lua_gettop(L);

    for (int i = 1; i <= nargs; i++) {
        if (lua_isstring(L, i)) {
            /* Pop the next arg using lua_tostring(L, i) and do your print */
            auto str = lua_tostring(L, i);
            harmony::log::info("Lua : {}", str);
        } else {
            /* Do something with non-strings if you like */
            harmony::log::warn("LuaProgramComponent : Invalid message tryig to be printed.");
        }
    }

    return 0;
}

static const struct luaL_Reg printlib[] = {
        {"print", l_my_print},
        {NULL, NULL} /* end of array */
};

void harmony::LuaProgramComponent::RedirectPrintOutput() {
    lua_State *L = p_State.lua_state();
    lua_getglobal(L, "_G");
    luaL_register(L, NULL, printlib); // for Lua versions < 5.2
    //luaL_setfuncs(L, printlib, 0);  // for Lua versions 5.2 or greater
    lua_pop(L, 1);

}
