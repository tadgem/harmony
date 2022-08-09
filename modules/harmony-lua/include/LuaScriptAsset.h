#pragma once
#include "Assets/Asset.h"


namespace harmony
{
    class LuaScriptAsset : public Asset
    {
    public:
        LuaScriptAsset(std::string name, std::string source);
        std::string m_Name;
        std::string m_Script;

        bool m_HasStart;
        bool m_HasEarlyUpdate;
        bool m_HasUpdate;
        bool m_HasLateUpdate;
        bool m_HasPreUpdateRender;
        bool m_HasPostUpdateRender;
        bool m_HasCleanup;
    };
}