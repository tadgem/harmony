#include "SDL_main.h"
#include "RuntimeProgram.h"
#if __WINRT__
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
int main()
{
	harmony::RuntimeProgram app;
	app.Run("../../../projects/Test3/Test3.harmonyproj");
}
#endif