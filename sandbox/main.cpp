#include <iostream>
#include "Program.h"
#include "daScript/daScript.h"
#include "src/dasBGFX.h"
#include "Log.hpp"
int main()
{
	harmony::log::warn("Hello from SPD");
	// Provide all built in daScript modules.
	NEED_ALL_DEFAULT_MODULES;
	// Add dasBGFX
	NEED_MODULE(Module_dasBGFX);
	// Initialize modules
	das::Module::Initialize();

	harmony::Program app("Harmony Test");
	app.Init();
	app.Run([&]()
	{
	});
	das::Module::Shutdown();
}