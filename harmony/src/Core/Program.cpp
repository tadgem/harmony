#include <filesystem>
#include "Core/Program.h"
#include "SDL_syswm.h"
#include "ImGui/imgui.h"
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "ImGui/backends/imgui_impl_sdl.h"
#include "ImGui/imgui_bgfx.h"
#include "Core/Log.hpp"

harmony::Program::Program(std::string name) : p_AppName(name), m_Renderer(m_AssetManager)
{
	HARMONY_PROFILE_FUNCTION()
	if(s_Instance != nullptr)
	{
		harmony::log::error("Trying to create new application instance but an application already exists!");
		return;
	}
	s_Instance = this;
	p_Run = true;
	p_ActiveScene = nullptr;
	using std::filesystem::current_path;

	std::filesystem::path path = std::filesystem::current_path();
	harmony::log::info("Current Working Directory : {}", path.string());
}

harmony::Program::~Program()
{
	HARMONY_PROFILE_FUNCTION()
	Cleanup();
}

void harmony::Program::Init()
{
	HARMONY_PROFILE_FUNCTION()
	InitSDL();
	InitBGFX();
	InitImGui();
	RunProgramComponentInit();
}

void harmony::Program::Cleanup()
{
	HARMONY_PROFILE_FUNCTION()
	ImGui_ImplSDL2_Shutdown();
	imguiDestroy();
		
	RunSystemCleanup();
	RunProgramComponentCleanup();

	ImGui::DestroyContext();
	bgfx::shutdown();

	SDL_DestroyWindow(p_Window);
	SDL_Quit();
}

void harmony::Program::InitSDL()
{
	HARMONY_PROFILE_FUNCTION()
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
	HARMONY_PROFILE_FUNCTION()

#if !BX_PLATFORM_EMSCRIPTEN
	SDL_SysWMinfo wmi;
	SDL_VERSION(&wmi.version);
	if (!SDL_GetWindowWMInfo(p_Window, &wmi)) {
		printf(
			"SDL_SysWMinfo could not be retrieved. SDL_Error: %s\n",
			SDL_GetError());
	}
	bgfx::renderFrame(); // single threaded mode
#endif

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
#endif

	bgfx::Init bgfx_init;
	bgfx_init.type = bgfx::RendererType::Count; // auto choose renderer
	bgfx_init.resolution.width = p_StartingWidth;
	bgfx_init.resolution.height = p_StartingHeight;
	bgfx_init.resolution.reset = BGFX_RESET_VSYNC;
	bgfx_init.platformData = pd;
	bgfx_init.debug = true;
	bgfx_init.callback = &p_DebugCallback;
	bgfx::init(bgfx_init);

	bgfx::setViewClear(
		0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x6495EDFF, 1.0f, 0);
	bgfx::setViewRect(0, 0, 0, p_StartingWidth, p_StartingHeight);

	uint32_t bgfxDebugFlags = 0;

#ifdef HARMONY_DEBUG
	bgfxDebugFlags |= BGFX_DEBUG_TEXT;
#endif
#ifdef HARMONY_PROFILE
	bgfxDebugFlags |= BGFX_DEBUG_STATS;
	bgfxDebugFlags |= BGFX_DEBUG_PROFILER;
#endif

	bgfx::setDebug(bgfxDebugFlags);
}

void harmony::Program::InitImGui()
{
	HARMONY_PROFILE_FUNCTION()
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	p_ImGuiAllocator = new bx::DefaultAllocator();
	
	imguiCreate(18.0f, p_ImGuiAllocator);

#if BX_PLATFORM_WINDOWS
	ImGui_ImplSDL2_InitForD3D(p_Window);
#elif BX_PLATFORM_OSX
	ImGui_ImplSDL2_InitForMetal(p_Window);
#elif BX_PLATFORM_LINUX || BX_PLATFORM_EMSCRIPTEN
	ImGui_ImplSDL2_InitForOpenGL(p_Window, nullptr);
#endif
}

void harmony::Program::Run(harmony::Callback callback)
{
	HARMONY_PROFILE_FUNCTION()

	RunSystemInit();
	while (p_Run)
	{
		SDL_Event sdlEvent;
		while (SDL_PollEvent(&sdlEvent))
		{
			ImGui_ImplSDL2_ProcessEvent(&sdlEvent);
			if (sdlEvent.type == SDL_QUIT)
			{
				p_Run = false;
			}
		}
		ImGui::NewFrame();
		ImGui_ImplSDL2_NewFrame(p_Window);

		RunProgramComponentUpdate();

		RunSystemUpdate();

		callback();
		
		bgfx::touch(0);

		RunProgramComponentRender();

		RunSystemRender();

		// Use last available view for imgui. 
		// probably not great but will be ammended with view manager impl.
		bgfx::touch(UINT16_MAX);

		ImGui::Render();
		imguiEndFrame();

		bgfx::frame();
	}
}

void harmony::Program::Run()
{
	HARMONY_PROFILE_FUNCTION()

		RunSystemInit();
	while (p_Run)
	{
		SDL_Event sdlEvent;
		while (SDL_PollEvent(&sdlEvent))
		{
			ImGui_ImplSDL2_ProcessEvent(&sdlEvent);
			if (sdlEvent.type == SDL_QUIT)
			{
				p_Run = false;
			}
		}
		ImGui::NewFrame();
		ImGui_ImplSDL2_NewFrame(p_Window);

		RunProgramComponentUpdate();

		RunSystemUpdate();

		bgfx::touch(0);

		RunProgramComponentRender();

		RunSystemRender();

		// Use last available view for imgui. 
		// probably not great but will be ammended with view manager impl.
		bgfx::touch(UINT16_MAX);

		ImGui::Render();
		imguiEndFrame();

		bgfx::frame();
	}
}

void harmony::Program::SaveProject(Project& proj)
{
	HARMONY_PROFILE_FUNCTION()
	proj.UpdateProjectComponentSerializationAttributes(p_ProgramComponents);
	proj.Save();
	nlohmann::json projectJson = proj;
	Utils::SaveJsonToPath(projectJson, proj.m_ProjectPath);
}

void harmony::Program::LoadProject(Project& proj)
{
	HARMONY_PROFILE_FUNCTION()
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

void harmony::Program::RunProgramComponentInit()
{
	HARMONY_PROFILE_FUNCTION()
	for (int i = 0; i < p_ProgramComponents.size(); i++)
	{
		p_ProgramComponents[i]->Init();
	}
}

void harmony::Program::RunProgramComponentUpdate()
{
	HARMONY_PROFILE_FUNCTION()
	for (int i = 0; i < p_ProgramComponents.size(); i++)
	{
		p_ProgramComponents[i]->Update();
	}
}

void harmony::Program::RunProgramComponentRender()
{
	HARMONY_PROFILE_FUNCTION()
	for (int i = 0; i < p_ProgramComponents.size(); i++)
	{
		p_ProgramComponents[i]->Render();
	}
}

void harmony::Program::RunProgramComponentCleanup()
{
	HARMONY_PROFILE_FUNCTION()
	for (int i = 0; i < p_ProgramComponents.size(); i++)
	{
		p_ProgramComponents[i]->Cleanup();
	}
}

void harmony::Program::RunSystemInit()
{
	HARMONY_PROFILE_FUNCTION()
	if (p_ActiveScene != nullptr)
	{
		for (int i = 0; i < p_ECSSystems.size(); i++)
		{
			p_ECSSystems[i]->Init(p_ActiveScene->m_Registry);
		}
	}
}

void harmony::Program::RunSystemUpdate()
{
	HARMONY_PROFILE_FUNCTION()
	if (p_ActiveScene != nullptr)
	{
		for (int i = 0; i < p_ECSSystems.size(); i++)
		{
			p_ECSSystems[i]->Update(p_ActiveScene->m_Registry);
		}
	}
}

void harmony::Program::RunSystemRender()
{
	HARMONY_PROFILE_FUNCTION()
	if (p_ActiveScene != nullptr)
	{
		for (int i = 0; i < p_ECSSystems.size(); i++)
		{
			p_ECSSystems[i]->Render(p_ActiveScene->m_Registry);
		}
	}
}

void harmony::Program::RunSystemCleanup()
{
	HARMONY_PROFILE_FUNCTION()
	if (p_ActiveScene != nullptr)
	{
		for (int i = 0; i < p_ECSSystems.size(); i++)
		{
			p_ECSSystems[i]->Cleanup(p_ActiveScene->m_Registry);
		}
	}
}
