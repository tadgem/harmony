//
// Created by liam_ on 11/5/2023.
//

#pragma once
#include "MiniGuiApp.h"
namespace harmony
{
    class Program;
    class LoadProjectGui : public MiniGuiApp
    {
    public:
        LoadProjectGui(Program& prog);

        bool OnImGui() override;

    protected:
        bool p_DialogOpen;
        Program& p_Program;
    };
}