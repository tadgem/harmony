#include <optick.h>
#include "Script/Lua/LuaProgramComponent.h"
#include "Script/Lua/LuaNanoVG.hpp"
#include "Script/Lua/LuaHarmony.hpp"
#include "Core/Log.hpp"

harmony::LuaProgramComponent::LuaProgramComponent() {
}

void harmony::LuaProgramComponent::Init() {
    OPTICK_EVENT();
    p_State.open_libraries(sol::lib::base, sol::lib::package, sol::lib::jit, sol::lib::ffi);
    harmony::InitNanoVG(p_State);
    harmony::InitHarmony(p_State);
    RedirectPrintOutput();
}

void harmony::LuaProgramComponent::Update() {
    OPTICK_EVENT();
    return;
}

void harmony::LuaProgramComponent::Render() {
    OPTICK_EVENT();
}

void harmony::LuaProgramComponent::Cleanup() {
    OPTICK_EVENT();
}

nlohmann::json harmony::LuaProgramComponent::ToJson() {
    OPTICK_EVENT();
    return nlohmann::json();
}

void harmony::LuaProgramComponent::FromJson(const nlohmann::json &json) {
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
