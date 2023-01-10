#include "LuaProgramComponent.h"
#include "LuaImGui.hpp"
#include "LuaNanoVG.hpp"
#include "Core/Log.hpp"

harmony::LuaProgramComponent::LuaProgramComponent()
{
}

void harmony::LuaProgramComponent::Init()
{
    p_State.open_libraries(sol::lib::base, sol::lib::package);
    sol_ImGui::Init(p_State); 
}

void harmony::LuaProgramComponent::Update()
{
    //std::string debugScript1 = "opened = ImGui.Begin('Lua Window')";
    //auto result = p_State.script(debugScript1);
    //std::string debugScript2 = "ImGui.Text('Dad')";
    //result = p_State.script(debugScript2);
    //std::string debugScript3 = "ImGui.Separator()";
    //result = p_State.script(debugScript3);
    //std::string debugScript4 = "ImGui.Text('Dad 2')";
    //result = p_State.script(debugScript4);
    //std::string debugScript5 = "pressed = ImGui.Button('My Button')";
    //result = p_State.script(debugScript5);
    ///*std::string debugScript7 = "bgfx.dbg_text_print(0, 1, 0xf, 'Some Text from BGFX in LUA :)')";
    //result = p_State.script(debugScript7);*/
    //std::string debugScriptLast = "ImGui.End()";
    //result = p_State.script(debugScriptLast);

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
