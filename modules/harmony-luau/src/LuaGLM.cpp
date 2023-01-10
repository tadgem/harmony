#include "Core/Log.hpp"
#include "LuaGLM.h"
#include "lualib.h";

static luaL_Reg funcs[]
{
    luaL_Reg{"vec2.new", LuaGLM::lua_CreateVec2},
};

void LuaGLM::Bind(lua_State* state)
{
    size_t num = sizeof(funcs) / sizeof(funcs[0]);

    for (size_t i = 0; i < num; i++)
    {
        lua_pushcfunction(state, funcs[i].func, funcs[i].name);
    }


    harmony::log::info("Done");
}

int LuaGLM::lua_CreateVec2(lua_State* s)
{
    lua_createtable(s, 0, 2);

    lua_pushnumber(s, 0.0f);
    lua_setfield(s, -2, "x");

    lua_pushnumber(s, 0.0f);
    lua_setfield(s, -2, "y");
    return 1;
}
