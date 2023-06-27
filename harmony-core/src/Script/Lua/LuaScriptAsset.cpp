#include <optick.h>
#include "Script/Lua/LuaScriptAsset.h"

harmony::LuaScriptAsset::LuaScriptAsset(std::string name, std::string source) : m_Name(name), m_Script(source)
{
	OPTICK_EVENT();
}
