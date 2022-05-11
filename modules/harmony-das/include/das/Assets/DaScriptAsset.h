#pragma once
#include "Assets/Asset.h"

namespace harmony
{
    class DaScriptAsset : public Asset
    {
    public:
        std::string m_ScriptContent;
    };
};