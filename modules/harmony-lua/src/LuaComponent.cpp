#include "LuaComponent.h"
#include "Assets/Asset.h"

harmony::LuaComponent::LuaComponent()
{
	m_HasStart = false;
	m_HasEarlyUpdate = false;
	m_HasUpdate = false;
	m_HasLateUpdate = false;
	m_HasPreUpdateRender = false;
	m_HasPostUpdateRender = false;
	m_HasCleanup = false;
}
