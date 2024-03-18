#include <optick.h>
#include "Script/Lua/LuaScriptAsset.h"

harmony::LuaScriptAsset::LuaScriptAsset(String name, String source) : m_Name(name), m_Script(source) {
    OPTICK_EVENT();
}
