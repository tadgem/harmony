#include <iostream>
#include "Program.h"
#include "ScriptSandboxComponent.h"

#include "Log.hpp"
int main()
{
	harmony::Program app("Harmony Test");

	app.AddProgramComponent<harmony::ScriptSandboxComponent>();

	app.Init();
	app.Run([&]()
	{
	});
}