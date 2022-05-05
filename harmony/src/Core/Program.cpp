#include <filesystem>
#include "Core/Program.h"
#include "SDL_syswm.h"
#include "imgui.h"
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "src/imgui/imgui_bgfx.h"
#include "backends/imgui_impl_sdl.h"
#include "Core/Log.hpp"

harmony::Program::Program(std::string name) : p_AppName(name)
{
	p_Run = true;
	using std::filesystem::current_path;

	std::filesystem::path path = std::filesystem::current_path();
	harmony::log::info("Current Working Directory : {}", path.string());
}

harmony::Program::~Program()
{
	Cleanup();
}

void harmony::Program::Init()
{
	InitSDL();
	InitBGFX();
	InitImGui();

	for (int i = 0; i < p_ProgramComponents.size(); i++)
	{
		p_ProgramComponents[i]->Init();
	}
}

void harmony::Program::Cleanup()
{
	ImGui_ImplSDL2_Shutdown();
	imguiDestroy();

	ImGui::DestroyContext();
	bgfx::shutdown();

	SDL_DestroyWindow(p_Window);
	SDL_Quit();
}

void harmony::Program::InitSDL()
{
	// init SDL window
	Uint32 flags = SDL_INIT_VIDEO | SDL_INIT_EVENTS;
	SDL_Init(flags);

	p_Window = SDL_CreateWindow(
		"Harmony", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_StartingWidth,
		p_StartingHeight, SDL_WINDOW_SHOWN);

	if (p_Window == nullptr) {
		printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
		return;
	}
}

void harmony::Program::InitBGFX()
{
#if !BX_PLATFORM_EMSCRIPTEN
	SDL_SysWMinfo wmi;
	SDL_VERSION(&wmi.version);
	if (!SDL_GetWindowWMInfo(p_Window, &wmi)) {
		printf(
			"SDL_SysWMinfo could not be retrieved. SDL_Error: %s\n",
			SDL_GetError());
	}
	bgfx::renderFrame(); // single threaded mode
#endif // !BX_PLATFORM_EMSCRIPTEN

	bgfx::PlatformData pd{};
#if BX_PLATFORM_WINDOWS
	pd.nwh = wmi.info.win.window;
#elif BX_PLATFORM_OSX
	pd.nwh = wmi.info.cocoa.window;
#elif BX_PLATFORM_LINUX
	pd.ndt = wmi.info.x11.display;
	pd.nwh = (void*)(uintptr_t)wmi.info.x11.window;
#elif BX_PLATFORM_EMSCRIPTEN
	pd.nwh = (void*)"#canvas";
#endif // BX_PLATFORM_WINDOWS ? BX_PLATFORM_OSX ? BX_PLATFORM_LINUX ?
	// BX_PLATFORM_EMSCRIPTEN

	bgfx::Init bgfx_init;
	bgfx_init.type = bgfx::RendererType::Count; // auto choose renderer
	bgfx_init.resolution.width = p_StartingWidth;
	bgfx_init.resolution.height = p_StartingHeight;
	bgfx_init.resolution.reset = BGFX_RESET_VSYNC;
	bgfx_init.platformData = pd;
	bgfx::init(bgfx_init);

	bgfx::setViewClear(
		0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x6495EDFF, 1.0f, 0);
	bgfx::setViewRect(0, 0, 0, p_StartingWidth, p_StartingHeight);
}

void harmony::Program::InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	p_ImGuiAllocator = new bx::DefaultAllocator();
	
	imguiCreate(18.0f, p_ImGuiAllocator);

//	ImGui_Implbgfx_Init(255);
#if BX_PLATFORM_WINDOWS
	ImGui_ImplSDL2_InitForD3D(p_Window);
#elif BX_PLATFORM_OSX
	ImGui_ImplSDL2_InitForMetal(p_Window);
#elif BX_PLATFORM_LINUX || BX_PLATFORM_EMSCRIPTEN
	ImGui_ImplSDL2_InitForOpenGL(p_Window, nullptr);
#endif // BX_PLATFORM_WINDOWS ? BX_PLATFORM_OSX ? BX_PLATFORM_LINUX ?
//	// BX_PLATFORM_EMSCRIPTEN
}

void harmony::Program::Run(harmony::Callback callback)
{
	while (p_Run)
	{
		bgfx::touch(0);
		SDL_Event sdlEvent;
		while (SDL_PollEvent(&sdlEvent))
		{
			ImGui_ImplSDL2_ProcessEvent(&sdlEvent);
			if (sdlEvent.type == SDL_QUIT)
			{
				p_Run = false;
			}
		}
		imguiBeginFrame();
		ImGui_ImplSDL2_NewFrame(p_Window);

		for (int i = 0; i < p_ProgramComponents.size(); i++)
		{
			p_ProgramComponents[i]->Update();
		}

		callback();

		ImGui::Render();
		imguiEndFrame();

		for (int i = 0; i < p_ProgramComponents.size(); i++)
		{
			p_ProgramComponents[i]->Render();
		}

		bgfx::frame();
	}
}

void harmony::Program::SaveProject(Project& proj)
{
	proj.UpdateProjectComponentSerializationAttributes(p_ProgramComponents);
	proj.Save();
	nlohmann::json projectJson = proj;
	Utils::SaveJsonToPath(projectJson, proj.m_ProjectPath);
}

void harmony::Program::LoadProject(Project& proj)
{
	proj.Load();
	for (auto typeAssetPair : proj.p_ProgramComponentSerializationAttributes)
	{
		for (auto component : p_ProgramComponents)
		{
			if (component->m_TypeHash == typeAssetPair.first)
			{
				component->FromJson(typeAssetPair.second);
				component->Refresh();
			}
		}
	}
}
