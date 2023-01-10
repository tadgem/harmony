#include "LuaProgramComponent.h"
#include "LuaGLM.h"
#include "Core/Log.hpp"
#include "luacode.h"
harmony::LuaProgramComponent::LuaProgramComponent()
{
    p_State = nullptr;
}

void harmony::LuaProgramComponent::Init()
{
    std::string command = "a = vec2.new()\na.x = 1.0\na.y = 2.0\nprint(a.x)\nprint(a.y)";

    if (p_State != nullptr)
    {
        delete p_State;
    }

    p_State = luaL_newstate();
    LuaGLM::Bind(p_State);
    luaL_openlibs(p_State);

    LuauBytecode bc = GetBytecode(command, "TestLua");
    int result = RunBytecode(p_State, bc,0);
    
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

harmony::LuauBytecode harmony::LuaProgramComponent::GetBytecode(const std::string& source, const std::string& chunkName)
{
    LuauBytecode bc;

    bc.Bytecode = luau_compile(source.c_str(), source.size(), NULL, &bc.BytecodeSize);
    bc.ChunkName = chunkName;

    return bc;
}

int harmony::LuaProgramComponent::RunBytecode(lua_State* state, const LuauBytecode& bc, int env)
{
    int result = luau_load(state, bc.ChunkName.c_str(), bc.Bytecode, bc.BytecodeSize, 0);
    if (result == 0)
    {
        lua_call(state, 0, 0);
        harmony::log::info("LuauProgramComponent : Successfully ran byte code");
    }
    else
    {
        std::string errMsg = lua_tostring(state, -1);
        harmony::log::warn("LuauProgramComponent : Error : {}", errMsg);
    }

    return result;
}
