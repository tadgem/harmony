#include <optick.h>
#include "Script/Lua/LuaProgramComponent.h"
#include "Script/Lua/LuaNanoVG.hpp"
#include "Script/Lua/LuaHarmony.hpp"
#include "Core/Log.hpp"

harmony::LuaProgramComponent::LuaProgramComponent() {
}

void harmony::LuaProgramComponent::Init() {
    OPTICK_EVENT();
    p_State.open_libraries(sol::lib::base, sol::lib::package, sol::lib::jit, sol::lib::ffi);
    harmony::InitNanoVG(p_State);
    harmony::InitHarmony(p_State);
}

void harmony::LuaProgramComponent::Update() {
    OPTICK_EVENT();
    return;
}

void harmony::LuaProgramComponent::Render() {
    OPTICK_EVENT();
}

void harmony::LuaProgramComponent::Cleanup() {
    OPTICK_EVENT();
}

nlohmann::json harmony::LuaProgramComponent::ToJson() {
    OPTICK_EVENT();
    return nlohmann::json();
}

void harmony::LuaProgramComponent::FromJson(const nlohmann::json &json) {
}
