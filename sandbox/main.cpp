#include <iostream>
#include "Core/Program.h"
#include "ScriptSandboxComponent.h"

#include "Core/Log.hpp"
int main()
{
	harmony::Program app("Harmony Test");

	app.AddProgramComponent<harmony::ScriptSandboxComponent>(app.m_AssetManager);

	app.Init();
	app.Run([&]()
	{
	});
}