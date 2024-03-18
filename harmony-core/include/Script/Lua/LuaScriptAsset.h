#pragma once

#include "Assets/Asset.h"

namespace harmony {
    class LuaScriptAsset : public Asset {
    public:
        LuaScriptAsset(String name, String source);

        String m_Name;
        String m_Script;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(LuaScriptAsset, m_Name, m_Handle)
    };
} // namespace harmony