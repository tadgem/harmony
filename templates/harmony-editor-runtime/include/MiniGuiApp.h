//
// Created by liam_ on 11/4/2023.
//

#pragma once

#include "Core/Alias.h"
#include <bx/allocator.h>
#include "SDL.h"

namespace harmony
{
    // PC only helper class to display dialogs outwith the main engine loop.
    class MiniGuiApp
    {
    public:
        MiniGuiApp(const String& appName);
        virtual bool OnImGui();

    protected:
        const String p_Name;
    };
}