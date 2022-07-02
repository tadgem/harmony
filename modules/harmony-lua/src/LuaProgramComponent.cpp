#include "LuaProgramComponent.h"
#include "LuaImGui.hpp"
#include "LuaBGFX.hpp"
#include "Core/Log.hpp"

harmony::LuaProgramComponent::LuaProgramComponent()
{
}

void harmony::LuaProgramComponent::Init()
{
    p_State.open_libraries(sol::lib::base, sol::lib::package);
    bind_imgui(p_State);
    bind_bgfx(p_State);
}

void harmony::LuaProgramComponent::Update()
{
    /*std::string debugScript1 = "opened = imgui.Begin('Lua Window')";
    auto result = p_State.script(debugScript1);
    std::string debugScript2 = "imgui.Text('Dad')";
    result = p_State.script(debugScript2);
    std::string debugScript3 = "imgui.Separator()";
    result = p_State.script(debugScript3);
    std::string debugScript4 = "imgui.Text('Dad 2')";
    result = p_State.script(debugScript4);
    std::string debugScript5 = "pressed = imgui.Button('My Button')";
    result = p_State.script(debugScript5);
    std::string debugScriptLast = "imgui.End()";
    result = p_State.script(debugScriptLast);*/

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
