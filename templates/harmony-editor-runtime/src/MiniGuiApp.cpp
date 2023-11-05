//
// Created by liam_ on 11/4/2023.
//
#include "Core/Log.hpp"
#include "MiniGuiApp.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_bgfx.h"
#include "ImGui/backends/imgui_impl_sdl.h"
#include "bgfx/bgfx.h"
#include "bx/timer.h"
#include "SDL_syswm.h"
#include "SDL_video.h"
#include "bgfx/platform.h"
#if BX_PLATFORM_WINDOWS
#include "windows.h"
#include <dwmapi.h>
#include <Core/Input.h>

#endif


bool harmony::MiniGuiApp::OnImGui()
{
    if(ImGui::Begin(p_Name.c_str()))
    {

    }
    ImGui::End();

    return true;

}

harmony::MiniGuiApp::MiniGuiApp(const harmony::String &appName) : p_Name(appName)
{

}
