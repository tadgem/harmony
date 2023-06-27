#pragma once

#include "Assets/Asset.h"
#include "Script/Lua/LuaScriptAsset.h"
#include "ThirdParty/json.hpp"
#include "sol.hpp"

namespace harmony
{
	class LuaComponent
	{
	public:
		LuaComponent();
		LuaScriptAsset m_LuaScriptAsset;
		bool m_HasStart;
		bool m_HasUpdate;
		bool m_HasCleanup;
		sol::environment m_Env;
		sol::function m_Start;
		sol::function m_Update;
		sol::function m_Cleanup;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(LuaComponent, m_LuaScriptAsset, m_HasStart,
									   m_HasUpdate, m_HasCleanup)
	};
} // namespace harmony