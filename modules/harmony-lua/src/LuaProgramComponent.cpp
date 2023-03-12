#include "LuaProgramComponent.h"
#include "LuaNanoVG.hpp"
#include "LuaHarmony.hpp"
#include "Core/Log.hpp"

harmony::LuaProgramComponent::LuaProgramComponent()
{
}

void harmony::LuaProgramComponent::Init()
{
    p_State.open_libraries(sol::lib::base, sol::lib::package, sol::lib::jit, sol::lib::ffi);
    harmony::InitNanoVG(p_State);
    harmony::InitHarmony(p_State);
}

void harmony::LuaProgramComponent::Update()
{
    return;
}

void harmony::LuaProgramComponent::Render()
{
}

void harmony::LuaProgramComponent::Cleanup()
{
}

nlohmann::json harmony::LuaProgramComponent::ToJson()
{
    return nlohmann::json();
}

void harmony::LuaProgramComponent::FromJson(const nlohmann::json& json)
{
}
