#include "SDL.h"
#undef main
#include <string>

// class SDL_Window;

namespace harmony
{
	class Application
	{
	public:
		Application(std::string name);

	private:

		void Init();
		void Cleanup();

		void InitSDL();
		void InitBGFX();
		void InitImGui();

		void Run();

		SDL_Window* p_Window;

		std::string p_AppName;

		const uint32_t p_StartingWidth = 1280;
		const uint32_t p_StartingHeight = 720;

		bool p_Run;
	};
};