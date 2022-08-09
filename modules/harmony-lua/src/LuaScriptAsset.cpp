#include "LuaScriptAsset.h"

harmony::LuaScriptAsset::LuaScriptAsset(std::string name, std::string source) : m_Name(name), m_Script(source)
{
	m_HasStart = false;
	m_HasEarlyUpdate = false;
	m_HasUpdate = false;
	m_HasLateUpdate = false;
	m_HasPreUpdateRender = false;
	m_HasPostUpdateRender = false;
	m_HasCleanup = false;
}
