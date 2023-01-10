#pragma once
#include <sol/sol.hpp>
extern "C"
{
#include "luabgfx.h"
}
namespace harmony
{
	inline static void InitBGFX(sol::state& state)
	{
		luaopen_bgfx(state);
	}
};