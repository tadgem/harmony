#if __WINRT__
#include "SDL_main.h"
#include "RuntimeProgram.h"
int SDL_main(int argc, char* argv[])
{
	harmony::RuntimeProgram app;
	app.Run("Test3/Test3.harmonyproj");

	return 0;
}

int main()
{
	SDL_WinRTRunApp(SDL_main, NULL);
}
#else
#include "RuntimeProgram.h"
int main()
{
	harmony::RuntimeProgram app;
	app.Run("../../../projects/Test3/Test3.harmonyproj");
}
#endif