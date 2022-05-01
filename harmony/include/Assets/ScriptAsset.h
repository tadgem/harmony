#pragma once
#include "Assets/Asset.h"

namespace harmony
{
    struct ScriptAsset : public Asset
    {
        std::string m_ScriptContent;
    };
};