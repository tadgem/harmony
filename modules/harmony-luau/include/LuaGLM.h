#pragma once
#include "lua.h"

class LuaGLM
{
public:

	static void Bind(lua_State* state);

	static int lua_CreateVec2(lua_State* s);
	static int lua_PrintVec2(lua_State* s);
};