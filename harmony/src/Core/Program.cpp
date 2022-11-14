#include <filesystem>
#include "Core/Program.h"
#include "Core/Log.hpp"
#include "Core/Time.h"
#include "Core/Input.h"
#include "SDL_syswm.h"
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/timer.h"
#if HARMONY_DEBUG
#include "ImGui/imgui.h"
#include "ImGui/imgui_bgfx.h"
#include "ImGui/ImGuizmo.h"
#include "ImGui/backends/imgui_impl_sdl.h"
#include "ImGui/robotomono_regular.ttf.h"
#endif
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
	
	harmony::log::info("Harmony Engine");
	
	InitSDL();
	InitBGFX();
	InitImGui();
}

void harmony::Program::LoadBuiltInAssets()
{
}

void harmony::Program::SetupBGFXCapabilities(bgfx::Init& init)
{
	uint64_t caps;

	if (m_Capabilities->supported && BGFX_CAPS_BLEND_INDEPENDENT)
	{
		caps |= BGFX_CAPS_BLEND_INDEPENDENT;
	}

	init.capabilities = caps;
}

std::string harmony::Program::GetVendorName(uint16_t vendorId)
{
	switch (vendorId)
	{
		case BGFX_PCI_ID_AMD:
			return "AMD";
		case BGFX_PCI_ID_NVIDIA:
			return "NVIDIA";
		case BGFX_PCI_ID_APPLE:
			return "Apple";
		case BGFX_PCI_ID_INTEL:
			return "Intel";
		case BGFX_PCI_ID_MICROSOFT:
			return "Microsoft";
		case BGFX_PCI_ID_SOFTWARE_RASTERIZER:
			return "Software";
		default:
			return "Unknown";
	}
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
	p_WindowHeight	= rect.h - 24;

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
	

	// SetupBGFXCapabilities(bgfx_init);
	bgfx::init(bgfx_init);

	uint32_t bgfxDebugFlags = 0;

#ifdef HARMONY_DEBUG
	bgfxDebugFlags |= BGFX_DEBUG_TEXT;
#endif
#ifdef HARMONY_PROFILE
	bgfxDebugFlags |= BGFX_DEBUG_STATS;
	bgfxDebugFlags |= BGFX_DEBUG_PROFILER;
#endif

	bgfx::setDebug(bgfxDebugFlags);

	harmony::log::info("Program : BGFX : Successfully initialized");
	
	m_Capabilities = (bgfx::Caps*)bgfx::getCaps();
	ListCapabilities();

}
void harmony::Program::ListCapabilities()
{
	harmony::log::info("Program : BGFX : Capabilities");
	harmony::log::info("Program : BGFX : Alpha To Coverage? : {}", m_Capabilities->supported && BGFX_CAPS_ALPHA_TO_COVERAGE);
	harmony::log::info("Program : BGFX : Support Compute? : {}", m_Capabilities->supported && BGFX_CAPS_COMPUTE);
	harmony::log::info("Program : BGFX : Blend Independent? : {}", m_Capabilities->supported && BGFX_CAPS_BLEND_INDEPENDENT);
	harmony::log::info("Program : BGFX : Draw Indirect? : {}", m_Capabilities->supported && BGFX_CAPS_DRAW_INDIRECT);
	harmony::log::info("Program : BGFX : Texture Blit? : {}", m_Capabilities->supported && BGFX_CAPS_TEXTURE_BLIT);
	harmony::log::info("Program : BGFX : Texture Direct Access? : {}", m_Capabilities->supported && BGFX_CAPS_TEXTURE_DIRECT_ACCESS);
	harmony::log::info("Program : BGFX : Texture Readback? : {}", m_Capabilities->supported && BGFX_CAPS_TEXTURE_READ_BACK);
	harmony::log::info("Program : BGFX : Image R/W? : {}", m_Capabilities->supported && BGFX_CAPS_IMAGE_RW);
}
void harmony::Program::SetStyle()
{
	// Photoshop style by Derydoca from ImThemes
	ImGuiStyle& style = ImGui::GetStyle();

	style.Alpha = 1.0f;
	style.DisabledAlpha = 0.6000000238418579f;
	style.WindowPadding = ImVec2(2.0f, 2.0f);
	style.WindowRounding = 4.0f;
	style.WindowBorderSize = 1.0f;
	style.WindowMinSize = ImVec2(32.0f, 32.0f);
	style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_Left;
	style.ChildRounding = 4.0f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 2.0f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(2.0f, 2.0f);
	style.FrameRounding = 2.0f;
	style.FrameBorderSize = 1.0f;
	style.ItemSpacing = ImVec2(4.0f, 2.0f);
	style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
	style.CellPadding = ImVec2(4.0f, 2.0f);
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 13.0f;
	style.ScrollbarRounding = 12.0f;
	style.GrabMinSize = 7.0f;
	style.GrabRounding = 0.0f;
	style.TabRounding = 0.0f;
	style.TabBorderSize = 1.0f;
	style.TabMinWidthForCloseButton = 0.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

	style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.4980392158031464f, 0.4980392158031464f, 0.4980392158031464f, 1.0f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1764705926179886f, 0.1764705926179886f, 0.1764705926179886f, 1.0f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.2784313857555389f, 0.2784313857555389f, 0.2784313857555389f, 0.0f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3098039329051971f, 1.0f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.2627451121807098f, 0.2627451121807098f, 0.2627451121807098f, 1.0f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2000000029802322f, 1.0f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.2784313857555389f, 0.2784313857555389f, 0.2784313857555389f, 1.0f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f, 1.0f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f, 1.0f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f, 1.0f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.1921568661928177f, 0.1921568661928177f, 0.1921568661928177f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.2745098173618317f, 0.2745098173618317f, 0.2745098173618317f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.2980392277240753f, 0.2980392277240753f, 0.2980392277240753f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.3882353007793427f, 0.3882353007793427f, 0.3882353007793427f, 1.0f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_Button] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.1560000032186508f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.0f, 1.0f, 1.0f, 0.3910000026226044f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3098039329051971f, 1.0f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.4666666686534882f, 0.4666666686534882f, 0.4666666686534882f, 1.0f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.4666666686534882f, 0.4666666686534882f, 0.4666666686534882f, 1.0f);
	style.Colors[ImGuiCol_Separator] = ImVec4(0.2627451121807098f, 0.2627451121807098f, 0.2627451121807098f, 1.0f);
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.3882353007793427f, 0.3882353007793427f, 0.3882353007793427f, 1.0f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.0f, 1.0f, 1.0f, 0.25f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.6700000166893005f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_Tab] = ImVec4(0.09411764889955521f, 0.09411764889955521f, 0.09411764889955521f, 1.0f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(0.3490196168422699f, 0.3490196168422699f, 0.3490196168422699f, 1.0f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(0.1921568661928177f, 0.1921568661928177f, 0.1921568661928177f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.09411764889955521f, 0.09411764889955521f, 0.09411764889955521f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1921568661928177f, 0.1921568661928177f, 0.1921568661928177f, 1.0f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.4666666686534882f, 0.4666666686534882f, 0.4666666686534882f, 1.0f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.5843137502670288f, 0.5843137502670288f, 0.5843137502670288f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
	style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3490196168422699f, 1.0f);
	style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2274509817361832f, 0.2274509817361832f, 0.2470588237047195f, 1.0f);
	style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.1560000032186508f);
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_NavHighlight] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.5860000252723694f);
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.5860000252723694f);
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

void harmony::Program::PreRunInit()
{
	HARMONY_PROFILE_FUNCTION()

	RunSystemInit();
	LoadBuiltInAssets();
	SetStyle();
}

void harmony::Program::UpdateTimeVariables()
{
	int64_t now = bx::getHPCounter();
	static int64_t last = now;
	const int64_t frameTime = now - last;
	last = now;
	const double freq = double(bx::getHPFrequency());

	Time::p_FrameTime = (double)(frameTime * 1.0 / freq);
}

void harmony::Program::ResizeApplicationWindow(int w, int h)
{
	HARMONY_PROFILE_FUNCTION()

	p_WindowWidth	= static_cast<uint16_t>(w);
	p_WindowHeight	= static_cast<uint16_t>(h);
	SDL_SetWindowSize(p_Window, w, h);
	ImGui::GetIO().DisplaySize = ImVec2(p_WindowWidth, p_WindowHeight);
	for (uint16_t i = 0; i < m_Capabilities->limits.maxViews; i++)
	{
		bgfx::setViewRect(i, 0, 0, bgfx::BackbufferRatio::Equal);
	}
	bgfx::reset(p_WindowWidth, p_WindowHeight);
}

void harmony::Program::HandleSDLEvent()
{
	SDL_Event sdlEvent;

	while (SDL_PollEvent(&sdlEvent))
	{
		ImGui_ImplSDL2_ProcessEvent(&sdlEvent);
		if (sdlEvent.type == SDL_QUIT)
		{
			p_Run = false;
			return;
		}

		if (sdlEvent.type == SDL_WINDOWEVENT)
		{
			if (sdlEvent.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				ResizeApplicationWindow(sdlEvent.window.data1, sdlEvent.window.data2);
			}
		}
		HandleInputEvent(sdlEvent);
	}
}

void harmony::Program::HandleInputEvent(SDL_Event& event)
{
	// Keyboard
	if (event.type == SDL_KEYDOWN)
	{
		SDL_KeyboardEvent keyEvent = event.key;
		SDL_Keysym keySym = keyEvent.keysym;
		Key key = Input::GetKeyFromSDLKeycode(keySym.sym);
		Input::Get()->UpdateKey(key, true);
	}

	if (event.type == SDL_KEYUP)
	{
		SDL_KeyboardEvent keyEvent = event.key;
		SDL_Keysym keySym = keyEvent.keysym;
		Key key = Input::GetKeyFromSDLKeycode(keySym.sym);
		Input::Get()->UpdateKey(key, false);
	}

	if (event.type == SDL_MOUSEMOTION)
	{
		SDL_MouseMotionEvent motionEvent = event.motion;
		glm::vec2 currentPosition = glm::vec2(motionEvent.x, motionEvent.y);
		Input::Get()->UpdateMousePosition(currentPosition);
	}

	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		SDL_MouseButtonEvent buttonEvent = event.button;
		Mouse::Button button = buttonEvent.button == 3 ? Mouse::Button::Right : Mouse::Button::Left;
		Input::Get()->UpdateMouseButton(button, true);
	}

	if (event.type == SDL_MOUSEBUTTONUP)
	{
		SDL_MouseButtonEvent buttonEvent = event.button;
		Mouse::Button button = buttonEvent.button == 3 ? Mouse::Button::Right : Mouse::Button::Left;
		Input::Get()->UpdateMouseButton(button, false);
	}
	// Mouse
}

void harmony::Program::ImGuiPreUpdate()
{
	bgfx::setViewClear((bgfx::ViewId)255, BGFX_CLEAR_COLOR, 0x00000000);
	ImGui::NewFrame();
	ImGui_ImplSDL2_NewFrame(p_Window);
	ImGuizmo::BeginFrame();
}

void harmony::Program::ImGuiPostUpdate()
{
	ImGui::Render();
	imguiEndFrame();
}

void harmony::Program::Run()
{
	HARMONY_PROFILE_FUNCTION()

	PreRunInit();

	while (p_Run)
	{
		UpdateTimeVariables();
		
		HandleSDLEvent();

		RunRendererPreUpdate();

		ImGuiPreUpdate();

		RunProgramComponentUpdate();
		
		RunSystemUpdate();

		RunRendererPostUpdate();

		RunProgramComponentRender();

		RunSystemRender();

		Input::Get()->PostFrame();

		ImGuiPostUpdate();

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
	m_Project->UpdateRendererSerializationAttributes(m_Renderer);
	m_Project->UpdateProjectAssetsSerializationAttributes(m_AssetManager);
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
	m_Project->Load(m_AssetManager, m_Renderer);
	p_LoadedProjectPath = path;

	RunProgramComponentInit();
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

	std::string cleanPath = path;
	if (m_Project)
	{
		std::string projectDir = m_Project->m_ProjectDirectory;
		size_t pos = cleanPath.find(projectDir);
		if (pos != std::string::npos && projectDir.length() > 0)
		{
			cleanPath.erase(pos, projectDir.length() + 1);
		}
	}

	p_ActiveScene->UpdateSceneSystemSerializationAttributes(p_ECSSystems);
	nlohmann::json sceneJson = *p_ActiveScene;
	Utils::SaveJsonToPath(sceneJson, cleanPath);

	auto it = std::find(m_Project->m_SerializedScenes.begin(), m_Project->m_SerializedScenes.end(), cleanPath);
	int findIndex = -1;
	int removeIndex = -1;
	for (int i = 0; i < m_Project->m_SerializedScenes.size(); i++)
	{
		if (m_Project->m_SerializedScenes[i] == cleanPath)
		{
			findIndex = i;
		}

		if (m_Project->m_SerializedScenes[i] == path)
		{
			removeIndex = i;
		}
	}
	if (removeIndex > 0)
	{
		m_Project->m_SerializedScenes.erase(m_Project->m_SerializedScenes.begin() + removeIndex);
	}
	if (findIndex < 0)
	{
		m_Project->m_SerializedScenes.push_back(cleanPath);
	}
}

void harmony::Program::LoadScene(const std::string& path)
{
	CloseActiveScene();
	nlohmann::json sceneJson = Utils::LoadJsonFromPath(path);
	p_ActiveScene = CreateRef<Scene>(sceneJson);

	p_ActiveScene->Deserialize(p_ECSSystems);
}

void harmony::Program::OpenScene(uint32_t index)
{
	CloseActiveScene();
	std::string scenePath = m_Project->m_SerializedScenes[index];
	nlohmann::json sceneJson = Utils::LoadJsonFromPath(scenePath);
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
