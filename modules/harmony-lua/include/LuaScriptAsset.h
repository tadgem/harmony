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
    };
}