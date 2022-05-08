#pragma once
#include "Assets/Asset.h"

namespace harmony
{
    class ScriptAsset : public Asset
    {
    public:
        std::string m_ScriptContent;
    };
};