#pragma once
#include "ThirdParty/json.hpp"
#include "sol.hpp"
#include "Assets/Asset.h"
#include "LuaScriptAsset.h"

namespace harmony 
{
    struct LuaComponent
    {
        LuaComponent();

        LuaScriptAsset m_LuaScriptAsset;

        bool m_HasStart;
        bool m_HasUpdate;
        bool m_HasCleanup;

        sol::function m_Update;
        sol::function m_Start;
        sol::function m_Cleanup;
    };
}