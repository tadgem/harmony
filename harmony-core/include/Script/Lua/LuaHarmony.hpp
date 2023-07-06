#pragma once

#include "sol.hpp"

namespace harmony
{
	void InitHarmony(sol::state &state);
	void InitHarmonyAssets(sol::state &state, sol::table &h);
	void InitHarmonyRendering(sol::state &state, sol::table &h);
	void InitHarmonyInput(sol::state &state, sol::table &h);
	void InitHarmonyECS(sol::state &state, sol::table &h);
	void InitHarmonyTime(sol::state &state, sol::table &h);
	void InitGLM(sol::state &state, sol::table &h);

#if HARMONY_DEBUG

	void InitHarmonyDebug(sol::state &state, sol::table &h);

#endif
} // namespace harmony