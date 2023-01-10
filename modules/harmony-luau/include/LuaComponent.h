#pragma once
#include "ThirdParty/json.hpp"
#include "Assets/Asset.h"
namespace harmony 
{
    struct AssetHandle;

    struct LuaComponent
    {
        LuaComponent();

        AssetHandle m_LuaScriptAsset;


        bool m_HasStart;
        bool m_HasEarlyUpdate;
        bool m_HasUpdate;
        bool m_HasLateUpdate;
        bool m_HasPreUpdateRender;
        bool m_HasPostUpdateRender;
        bool m_HasCleanup;
    };
}