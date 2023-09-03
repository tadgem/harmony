#include "SDL_main.h"
#include "RuntimeProgram.h"
#include <filesystem>

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

int main() {
    harmony::RuntimeProgram app;
    std::cout << "Current Path : " << std::filesystem::current_path() << "\n";
    app.Run("../../../../../../projects/JoltTest/JoltTest.harmonyproj");
}

#endif