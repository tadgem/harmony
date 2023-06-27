#include <optick.h>
#include "Script/Lua/LuaComponent.h"
#include "Assets/Asset.h"

harmony::LuaComponent::LuaComponent() : m_LuaScriptAsset("", "")
{
	OPTICK_EVENT();
	m_HasStart = false;
	m_HasUpdate = false;
	m_HasCleanup = false;
}
