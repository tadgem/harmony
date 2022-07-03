#include <filesystem>
#include "Core/Program.h"
#include "Core/Log.hpp"
#include "Core/Time.h"
#include "SDL_syswm.h"
#include "ImGui/imgui.h"
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "ImGui/backends/imgui_impl_sdl.h"
#include "ImGui/imgui_bgfx.h"
#include "ImGui/robotomono_regular.ttf.h"
#include "bx/timer.h"
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
	m_Project = nullptr;
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

void harmony::Program::ChangeWorkingDirectory(const std::string& directory)
{
	std::filesystem::current_path(std::filesystem::path(directory));
}

void harmony::Program::Cleanup()
{
	HARMONY_PROFILE_FUNCTION()
	ImGui_ImplSDL2_Shutdown();
	imguiDestroy();
		
	RunSystemCleanup();
	RunProgramComponentCleanup();

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
	
	SDL_Rect rect;
	SDL_GetDisplayUsableBounds(0, &rect);

	p_WindowWidth	= rect.w;
	p_WindowHeight	= rect.h;

	// TODO: Add window resizing.
	p_Window = SDL_CreateWindow(
		"Harmony", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_WindowWidth,
		p_WindowHeight, SDL_WINDOW_SHOWN);

	if (p_Window == nullptr) {
		harmony::log::error("Window could not be created. SDL_Error: ", SDL_GetError());
		return;
	}
	harmony::log::info("SDL Initialized successfully");
}

static void* sdlNativeWindowHandle(SDL_Window* _window)
	{
		SDL_SysWMinfo wmi;
		SDL_VERSION(&wmi.version);
		if (!SDL_GetWindowWMInfo(_window, &wmi) )
		{
			return NULL;
		}

#	if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
#		if ENTRY_CONFIG_USE_WAYLAND
		wl_egl_window *win_impl = (wl_egl_window*)SDL_GetWindowData(_window, "wl_egl_window");
		if(!win_impl)
		{
			int width, height;
			SDL_GetWindowSize(_window, &width, &height);
			struct wl_surface* surface = wmi.info.wl.surface;
			if(!surface)
				return nullptr;
			win_impl = wl_egl_window_create(surface, width, height);
			SDL_SetWindowData(_window, "wl_egl_window", win_impl);
		}
		return (void*)(uintptr_t)win_impl;
#		else
		return (void*)wmi.info.x11.window;
#		endif
#	elif BX_PLATFORM_OSX || BX_PLATFORM_IOS
		return wmi.info.cocoa.window;
#	elif BX_PLATFORM_WINDOWS
		return wmi.info.win.window;
#   elif BX_PLATFORM_ANDROID
		return wmi.info.android.window;
#	endif // BX_PLATFORM_
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
	#if ENTRY_CONFIG_USE_WAYLAND
		pd.ndt          = wmi.info.wl.display;
	#else
		pd.ndt          = wmi.info.x11.display;
	#endif

	pd.nwh          = sdlNativeWindowHandle(p_Window);
#elif BX_PLATFORM_EMSCRIPTEN
	pd.nwh = (void*)"#canvas";
#endif

	bgfx::Init bgfx_init;
	bgfx_init.type = bgfx::RendererType::Count; // auto choose renderer
	bgfx_init.resolution.width = p_WindowWidth;
	bgfx_init.resolution.height = p_WindowHeight;
	bgfx_init.resolution.reset = BGFX_RESET_VSYNC;
	bgfx_init.platformData = pd;
	bgfx_init.debug = true;
	bgfx_init.callback = &p_DebugCallback;
	bgfx::init(bgfx_init);

	bgfx::setViewClear(
		0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, Utils::EncodeRGBA(32,36,32, 255), 1.0f, 0);
	bgfx::setViewRect(0, 0, 0, p_WindowWidth, p_WindowHeight);

	uint32_t bgfxDebugFlags = 0;

#ifdef HARMONY_DEBUG
	bgfxDebugFlags |= BGFX_DEBUG_TEXT;
#endif
#ifdef HARMONY_PROFILE
	bgfxDebugFlags |= BGFX_DEBUG_STATS;
	bgfxDebugFlags |= BGFX_DEBUG_PROFILER;
#endif

	bgfx::setDebug(bgfxDebugFlags);

	m_Capabilities = *bgfx::getCaps();
	harmony::log::info("Successfully initialized BGFX");
}

void harmony::Program::SetStyle()
{
	HARMONY_PROFILE_FUNCTION()
	auto& style = ImGui::GetStyle();
	style.ChildRounding = 0;
	style.GrabRounding = 0;
	style.FrameRounding = 2;
	style.PopupRounding = 0;
	style.ScrollbarRounding = 0;
	style.TabRounding = 2;
	style.WindowRounding = 0;
	style.FramePadding = { 4, 4 };

	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_DockingPreview] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_DockingEmptyBg] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TableBorderLight] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);
	ImGuiCol_DockingEmptyBg;
	ImGuiCol_DockingPreview;
}

void harmony::Program::InitImGui()
{
	HARMONY_PROFILE_FUNCTION()
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	p_ImGuiAllocator = new bx::DefaultAllocator();
	
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	imguiCreate(18.0f, p_ImGuiAllocator);

#if BX_PLATFORM_WINDOWS
	ImGui_ImplSDL2_InitForD3D(p_Window);
#elif BX_PLATFORM_OSX
	ImGui_ImplSDL2_InitForMetal(p_Window);
#elif BX_PLATFORM_LINUX || BX_PLATFORM_EMSCRIPTEN
	ImGui_ImplSDL2_InitForOpenGL(p_Window, nullptr);
#endif
	harmony::log::info("Successfully initialized ImGui");
}

void harmony::Program::ResizeApplicationWindow(int w, int h)
{
	HARMONY_PROFILE_FUNCTION()

	p_WindowWidth	= static_cast<uint16_t>(w);
	p_WindowHeight	= static_cast<uint16_t>(h);
	SDL_SetWindowSize(p_Window, w, h);
	ImGui::GetIO().DisplaySize = ImVec2(p_WindowWidth, p_WindowHeight);
	for (uint16_t i = 0; i < m_Capabilities.limits.maxViews; i++)
	{
		bgfx::setViewRect(i, 0, 0, bgfx::BackbufferRatio::Equal);
	}
	bgfx::reset(p_WindowWidth, p_WindowHeight);
}

void harmony::Program::Run(harmony::Callback callback)
{
	HARMONY_PROFILE_FUNCTION()

	RunSystemInit();
	bgfx::touch(0);
	m_Renderer.Init();
	SetStyle();
	while (p_Run)
	{
		int64_t now = bx::getHPCounter();
		static int64_t last = now;
		const int64_t frameTime = now - last;
		last = now;
		const double freq = double(bx::getHPFrequency());

		Time::p_FrameTime = (double)(frameTime * 1.0 / freq);
		SDL_Event sdlEvent;

		while (SDL_PollEvent(&sdlEvent))
		{
			ImGui_ImplSDL2_ProcessEvent(&sdlEvent);
			if (sdlEvent.type == SDL_QUIT)
			{
				p_Run = false;
			}

			if (sdlEvent.type == SDL_WINDOWEVENT)
			{
				if (sdlEvent.window.event == SDL_WINDOWEVENT_RESIZED)
				{
					ResizeApplicationWindow(sdlEvent.window.data1, sdlEvent.window.data2);
				}
			}
		}

		RunRendererPreUpdate();

		// TODO move to pipeline
		ImGui::NewFrame();
		ImGui_ImplSDL2_NewFrame(p_Window);

		callback();

		RunProgramComponentUpdate();
		
		RunSystemUpdate();

		RunRendererPostUpdate();

		bgfx::touch(0);

		RunProgramComponentRender();

		RunSystemRender();

		// Use last available view for imgui. 
		// probably not great but will be ammended with view manager impl.
		bgfx::touch(0);
		ImGui::Render();
		imguiEndFrame();

		bgfx::frame();
	}
}

void harmony::Program::CreateProject(const std::string& name, const std::string& path)
{
	HARMONY_PROFILE_FUNCTION()
	CloseActiveProject();
	m_Project = CreateRef<Project>(name);
	p_LoadedProjectPath = path + "/" + name + ".harmonyproj";
}

void harmony::Program::SaveProject()
{
	HARMONY_PROFILE_FUNCTION()
	if (m_Project == nullptr)
	{
		harmony::log::warn("Program::SaveProject : cannot save project, as there is no active project.");
		return;
	}
	m_Project->UpdateProjectComponentSerializationAttributes(p_ProgramComponents);
	m_Project->Save();
	nlohmann::json projectJson = *m_Project;
	Utils::SaveJsonToPath(projectJson, p_LoadedProjectPath);
}

void harmony::Program::LoadProject(const std::string& path)
{
	HARMONY_PROFILE_FUNCTION()
	CloseActiveProject();
	nlohmann::json projectJson = Utils::LoadJsonFromPath(path);
	m_Project = CreateRef<Project>(projectJson);
		
	std::string directory = Utils::GetFilePathDirectory(path);
	ChangeWorkingDirectory(directory);
	directory = GetWorkingDirectory();
	harmony::log::info("Current working directory : {}", directory);

	m_Project->m_ProjectDirectory = directory;
	m_Project->Load();
	p_LoadedProjectPath = path;
}

void harmony::Program::CloseActiveProject()
{
	HARMONY_PROFILE_FUNCTION()
	if (m_Project == nullptr)
	{
		return;
	}

	CloseActiveScene();

	for (unsigned int i = 0; i < p_ProgramComponents.size(); i++)
	{
		p_ProgramComponents[i]->Refresh();
	}

	m_Project.reset();
	m_Project = nullptr;
}

void harmony::Program::CreateScene(const std::string& name)
{
	HARMONY_PROFILE_FUNCTION()
	if (m_Project == nullptr)
	{
		harmony::log::warn("Program::CreateScene : No project loaded, cannot create scene");
	}
	if (p_ActiveScene != nullptr)
	{
		CloseActiveScene();
	}

	p_ActiveScene = CreateRef<Scene>(name);
}

void harmony::Program::SaveScene(const std::string& path)
{
	if (p_ActiveScene == nullptr)
	{
		harmony::log::warn("Program::SaveScene : cannot save scene, as there is no active scene.");
		return;
	}
	p_ActiveScene->UpdateSceneSystemSerializationAttributes(p_ECSSystems);
	nlohmann::json sceneJson = *p_ActiveScene;
	Utils::SaveJsonToPath(sceneJson, path);
	m_Project->m_SerializedScenes.push_back(path);
}

void harmony::Program::LoadScene(const std::string& path)
{
	nlohmann::json sceneJson = Utils::LoadJsonFromPath(path);
}

void harmony::Program::OpenScene(uint32_t index)
{
	CloseActiveScene();
	nlohmann::json sceneJson = m_Project->m_SerializedScenes[index];
	p_ActiveScene = CreateRef<Scene>(sceneJson);
	p_ActiveScene->Deserialize(p_ECSSystems);
}

void harmony::Program::CloseActiveScene()
{
	HARMONY_PROFILE_FUNCTION()
	if(p_ActiveScene == nullptr)
	{
		return;
	}

	for (unsigned int i = 0; i < p_ECSSystems.size(); i++)
	{
		p_ECSSystems[i]->Refresh();
	}

	p_ActiveScene.reset();
	p_ActiveScene = nullptr;


}

harmony::WeakRef<harmony::Scene> harmony::Program::GetActiveScene()
{
	if (p_ActiveScene == nullptr)
	{
		return WeakRef<Scene>();
	}
	return GetWeakRef<Scene>(p_ActiveScene);
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
	if (p_ActiveScene == nullptr)
	{
		return;
	}
	for (int i = 0; i < p_ECSSystems.size(); i++)
	{
		p_ECSSystems[i]->Init(p_ActiveScene->m_Registry);
	}	
}

void harmony::Program::RunSystemUpdate()
{
	HARMONY_PROFILE_FUNCTION()
	if (p_ActiveScene == nullptr)
	{
		return;
	}
	for (int i = 0; i < p_ECSSystems.size(); i++)
	{
		p_ECSSystems[i]->Update(p_ActiveScene->m_Registry);
	}
	
}

void harmony::Program::RunSystemRender()
{
	HARMONY_PROFILE_FUNCTION()

	if (p_ActiveScene == nullptr)
	{
		return;
	}
	for (int i = 0; i < p_ECSSystems.size(); i++)
	{
		p_ECSSystems[i]->Render(p_ActiveScene->m_Registry);
	}
	
}

void harmony::Program::RunSystemCleanup()
{
	HARMONY_PROFILE_FUNCTION()

	if (p_ActiveScene == nullptr)
	{
		return;
	}
	for (int i = 0; i < p_ECSSystems.size(); i++)
	{
		p_ECSSystems[i]->Cleanup(p_ActiveScene->m_Registry);
	}
}

void harmony::Program::RunRendererPreUpdate()
{
	if (p_ActiveScene == nullptr)
	{
		return;
	}
	m_Renderer.OnPreUpdate(p_ActiveScene->m_Registry);
}

void harmony::Program::RunRendererPostUpdate()
{
	if (p_ActiveScene == nullptr)
	{
		return;
	}
	m_Renderer.OnPostUpdate(p_ActiveScene->m_Registry);
}

std::string harmony::Program::GetWorkingDirectory()
{
	return std::filesystem::current_path().string();
}
