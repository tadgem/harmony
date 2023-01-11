#include "LuaComponent.h"
#include "Assets/Asset.h"

harmony::LuaComponent::LuaComponent() : m_LuaScriptAsset("", "")
{
	m_HasStart = false;
	m_HasUpdate = false;
	m_HasCleanup = false;
}
