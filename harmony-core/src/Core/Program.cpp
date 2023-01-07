#include <filesystem>
#include "Core/Program.h"
#include "Core/Log.hpp"
#include "Core/Time.h"
#include "Core/Input.h"
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/timer.h"
#include "SDL_syswm.h"

#if HARMONY_DEBUG
#include "Rendering/VectorGraphics.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_bgfx.h"
#include "ImGui/ImGuizmo.h"
#include "ImGui/backends/imgui_impl_sdl.h"
#include "ImGui/robotomono_regular.ttf.h"
#endif
harmony::Program::Program(const std::string& name) : p_AppName(name), m_Renderer(m_AssetManager)
{
	HARMONY_PROFILE_FUNCTION()
	if(s_Instance != nullptr)
	{
		harmony::log::error("Trying to create new application instance but an application already exists!");
		return;
	}
	s_Instance = this;
	p_Run = true;
	p_ResizedThisFrame = false;
	m_Project = nullptr;
}

harmony::Program::~Program()
{
	HARMONY_PROFILE_FUNCTION()
}

void harmony::Program::Init()
{
	HARMONY_PROFILE_FUNCTION()
	
	harmony::log::info("Harmony Engine");

	using std::filesystem::current_path;

	std::filesystem::path path = std::filesystem::current_path();
	harmony::log::info("Current Working Directory : {}", path.string());
	
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

	SDL_WindowFlags windowFlags = static_cast<SDL_WindowFlags>(SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	// TODO: Add window resizing.
	p_Window = SDL_CreateWindow(
		p_AppName.c_str(),
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		p_WindowWidth,
		p_WindowHeight, 
		windowFlags);

	if (p_Window == nullptr) {
		harmony::log::error("Window could not be created. SDL_Error: ", SDL_GetError());
		return;
	}
	harmony::log::info("SDL Initialized successfully");
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
	// Harmony style from ImThemes
	ImGuiStyle& style = ImGui::GetStyle();

	style.Alpha = 1.0f;
	style.DisabledAlpha = 0.300000011920929f;
	style.WindowPadding = ImVec2(4.0f, 4.0f);
	style.WindowRounding = 0.0f;
	style.WindowBorderSize = 1.0f;
	style.WindowMinSize = ImVec2(32.0f, 32.0f);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_Left;
	style.ChildRounding = 4.0f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 4.0f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(5.0f, 2.0f);
	style.FrameRounding = 4.0f;
	style.FrameBorderSize = 1.0f;
	style.ItemSpacing = ImVec2(4.0f, 4.0f);
	style.ItemInnerSpacing = ImVec2(8.0f, 8.0f);
	style.CellPadding = ImVec2(4.0f, 4.0f);
	style.IndentSpacing = 8.0f;
	style.ColumnsMinSpacing = 4.0f;
	style.ScrollbarSize = 16.0f;
	style.ScrollbarRounding = 4.0f;
	style.GrabMinSize = 4.0f;
	style.GrabRounding = 16.0f;
	style.TabRounding = 4.0f;
	style.TabBorderSize = 1.0f;
	style.TabMinWidthForCloseButton = 4.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

	style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 0.9999899864196777f, 0.9999899864196777f, 1.0f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.6866884231567383f, 0.6866952776908875f, 0.6866907477378845f, 1.0f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1046867966651917f, 0.09624414891004562f, 0.1072961091995239f, 0.9399999976158142f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.2980392277240753f, 0.2980392277240753f, 0.2980392277240753f, 0.239215686917305f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.0784313753247261f, 0.0784313753247261f, 0.0784313753247261f, 0.9399999976158142f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.7854077219963074f, 0.5629317164421082f, 0.7457892894744873f, 0.2078431397676468f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.2426216751337051f, 0.2249811440706253f, 0.266094446182251f, 0.5400000214576721f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.3483740985393524f, 0.2626498937606812f, 0.4163089990615845f, 0.4000000059604645f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.8183903098106384f, 0.7083570957183838f, 0.8969957232475281f, 0.6700000166893005f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.03921568766236305f, 0.03921568766236305f, 0.03921568766236305f, 1.0f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.3235537707805634f, 0.2939822375774384f, 0.3261802792549133f, 1.0f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0f, 0.0f, 0.0f, 0.5099999904632568f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.1372549086809158f, 0.1372549086809158f, 0.1372549086809158f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.01960784383118153f, 0.01960784383118153f, 0.01960784383118153f, 0.5299999713897705f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3098039329051971f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.407843142747879f, 0.407843142747879f, 0.407843142747879f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.5098039507865906f, 0.5098039507865906f, 0.5098039507865906f, 1.0f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.4681426882743835f, 0.9484978318214417f, 0.5464838147163391f, 1.0f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.3257833123207092f, 0.258210688829422f, 0.3690987229347229f, 1.0f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.4161251783370972f, 0.3475842177867889f, 0.4763948321342468f, 1.0f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.6620938777923584f, 0.4334579706192017f, 0.6824034452438354f, 0.4000000059604645f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.6351931095123291f, 0.4470887184143066f, 0.6311566829681396f, 1.0f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.9574683308601379f, 0.9638731479644775f, 0.9699570536613464f, 1.0f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.5310252904891968f, 0.4697084128856659f, 0.5364806652069092f, 0.3100000023841858f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.2629694640636444f, 0.2246127426624298f, 0.2875536680221558f, 0.800000011920929f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.4670648276805878f, 0.3989390134811401f, 0.5107296109199524f, 1.0f);
	style.Colors[ImGuiCol_Separator] = ImVec4(0.2403433322906494f, 0.2063032984733582f, 0.2290941476821899f, 0.5f);
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.3773270845413208f, 0.3065077662467957f, 0.446351945400238f, 0.7799999713897705f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.7690807580947876f, 0.5991637706756592f, 0.9184549450874329f, 1.0f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.7546796202659607f, 0.5537033677101135f, 0.7725322246551514f, 0.2000000029802322f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.8398604989051819f, 0.7507045865058899f, 0.8969957232475281f, 0.6700000166893005f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.9656652212142944f, 0.9814256429672241f, 1.0f, 0.949999988079071f);
	style.Colors[ImGuiCol_Tab] = ImVec4(0.2806892693042755f, 0.2443589121103287f, 0.2875536680221558f, 0.8619999885559082f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(0.6093054413795471f, 0.5780544877052307f, 0.6094420552253723f, 0.800000011920929f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(0.518200159072876f, 0.4374735057353973f, 0.5364806652069092f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.274678111076355f, 0.08134244382381439f, 0.2356791347265244f, 0.9724000096321106f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.2202123701572418f, 0.03311905264854431f, 0.2489270567893982f, 1.0f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(1.0f, 0.9999899864196777f, 0.9999899864196777f, 1.0f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.4274509847164154f, 0.3490196168422699f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.5179687142372131f, 0.7939914464950562f, 0.7762216329574585f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.8953007459640503f, 0.5955718755722046f, 0.9313304424285889f, 1.0f);
	style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.2428884953260422f, 0.214684396982193f, 0.270386278629303f, 1.0f);
	style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.4720982611179352f, 0.4720982611179352f, 0.4721029996871948f, 1.0f);
	style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.3733868300914764f, 0.3733868300914764f, 0.3733905553817749f, 1.0f);
	style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.5897689461708069f, 0.4960120320320129f, 0.6566523313522339f, 0.3499999940395355f);
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 0.6437768340110779f, 0.0f, 0.8999999761581421f);
	style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.8508104085922241f, 0.646760880947113f, 0.8969957232475281f, 1.0f);
	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);

}

//void harmony::Program::SetStyle()
//{
//	// Photoshop style by Derydoca from ImThemes
//	ImGuiStyle& style = ImGui::GetStyle();
//
//	style.Alpha = 1.0f;
//	style.DisabledAlpha = 0.6000000238418579f;
//	style.WindowPadding = ImVec2(2.0f, 2.0f);
//	style.WindowRounding = 4.0f;
//	style.WindowBorderSize = 1.0f;
//	style.WindowMinSize = ImVec2(32.0f, 32.0f);
//	style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
//	style.WindowMenuButtonPosition = ImGuiDir_Left;
//	style.ChildRounding = 4.0f;
//	style.ChildBorderSize = 1.0f;
//	style.PopupRounding = 2.0f;
//	style.PopupBorderSize = 1.0f;
//	style.FramePadding = ImVec2(2.0f, 2.0f);
//	style.FrameRounding = 2.0f;
//	style.FrameBorderSize = 1.0f;
//	style.ItemSpacing = ImVec2(4.0f, 2.0f);
//	style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
//	style.CellPadding = ImVec2(4.0f, 2.0f);
//	style.IndentSpacing = 21.0f;
//	style.ColumnsMinSpacing = 6.0f;
//	style.ScrollbarSize = 13.0f;
//	style.ScrollbarRounding = 12.0f;
//	style.GrabMinSize = 7.0f;
//	style.GrabRounding = 0.0f;
//	style.TabRounding = 0.0f;
//	style.TabBorderSize = 1.0f;
//	style.TabMinWidthForCloseButton = 0.0f;
//	style.ColorButtonPosition = ImGuiDir_Right;
//	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
//	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);
//
//	style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
//	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.4980392158031464f, 0.4980392158031464f, 0.4980392158031464f, 1.0f);
//	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1764705926179886f, 0.1764705926179886f, 0.1764705926179886f, 1.0f);
//	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.2784313857555389f, 0.2784313857555389f, 0.2784313857555389f, 0.0f);
//	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3098039329051971f, 1.0f);
//	style.Colors[ImGuiCol_Border] = ImVec4(0.2627451121807098f, 0.2627451121807098f, 0.2627451121807098f, 1.0f);
//	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
//	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
//	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2000000029802322f, 1.0f);
//	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.2784313857555389f, 0.2784313857555389f, 0.2784313857555389f, 1.0f);
//	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f, 1.0f);
//	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f, 1.0f);
//	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f, 1.0f);
//	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.1921568661928177f, 0.1921568661928177f, 0.1921568661928177f, 1.0f);
//	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
//	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.2745098173618317f, 0.2745098173618317f, 0.2745098173618317f, 1.0f);
//	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.2980392277240753f, 0.2980392277240753f, 0.2980392277240753f, 1.0f);
//	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
//	style.Colors[ImGuiCol_CheckMark] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
//	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.3882353007793427f, 0.3882353007793427f, 0.3882353007793427f, 1.0f);
//	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
//	style.Colors[ImGuiCol_Button] = ImVec4(1.0f, 1.0f, 1.0f, 0.13f);
//	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.2560000032186508f);
//	style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.0f, 1.0f, 1.0f, 0.3910000026226044f);
//	style.Colors[ImGuiCol_Header] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3098039329051971f, 1.0f);
//	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.4666666686534882f, 0.4666666686534882f, 0.4666666686534882f, 1.0f);
//	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.4666666686534882f, 0.4666666686534882f, 0.4666666686534882f, 1.0f);
//	style.Colors[ImGuiCol_Separator] = ImVec4(0.2627451121807098f, 0.2627451121807098f, 0.2627451121807098f, 1.0f);
//	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.3882353007793427f, 0.3882353007793427f, 0.3882353007793427f, 1.0f);
//	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
//	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.0f, 1.0f, 1.0f, 0.25f);
//	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.6700000166893005f);
//	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
//	style.Colors[ImGuiCol_Tab] = ImVec4(0.09411764889955521f, 0.09411764889955521f, 0.09411764889955521f, 1.0f);
//	style.Colors[ImGuiCol_TabHovered] = ImVec4(0.3490196168422699f, 0.3490196168422699f, 0.3490196168422699f, 1.0f);
//	style.Colors[ImGuiCol_TabActive] = ImVec4(0.1921568661928177f, 0.1921568661928177f, 0.1921568661928177f, 1.0f);
//	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.09411764889955521f, 0.09411764889955521f, 0.09411764889955521f, 1.0f);
//	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1921568661928177f, 0.1921568661928177f, 0.1921568661928177f, 1.0f);
//	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.4666666686534882f, 0.4666666686534882f, 0.4666666686534882f, 1.0f);
//	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
//	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.5843137502670288f, 0.5843137502670288f, 0.5843137502670288f, 1.0f);
//	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
//	style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
//	style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3490196168422699f, 1.0f);
//	style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2274509817361832f, 0.2274509817361832f, 0.2470588237047195f, 1.0f);
//	style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
//	style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
//	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.1560000032186508f);
//	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
//	style.Colors[ImGuiCol_NavHighlight] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
//	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
//	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.5860000252723694f);
//	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.5860000252723694f);
//}

void harmony::Program::InitImGui()
{
	HARMONY_PROFILE_FUNCTION()
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	p_ImGuiAllocator = new bx::DefaultAllocator();
	
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

	imguiCreate(20.0f, p_ImGuiAllocator);

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
	bgfx::reset(p_WindowWidth, p_WindowHeight);
}

void harmony::Program::HandleSDLEvent()
{
	SDL_Event sdlEvent;
	p_ResizedThisFrame = false;

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
				if (!p_ResizedThisFrame)
				{
					ResizeApplicationWindow(sdlEvent.window.data1, sdlEvent.window.data2);
					p_ResizedThisFrame = true;
				}
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
	bgfx::setViewClear((bgfx::ViewId)BGFX_MAIN_WINDOW_IMGUI_VIEW_ID, BGFX_CLEAR_COLOR, 0x00000000);
	ImGui::NewFrame();
	ImGui_ImplSDL2_NewFrame(p_Window);
	ImGuizmo::BeginFrame();
}

void harmony::Program::ImGuiPostUpdate()
{
	imguiEndFrame();

	ImGui::UpdatePlatformWindows();
	ImGui::RenderPlatformWindowsDefault();

}

void harmony::Program::RunProgramLoop()
{
	while (p_Run)
	{
		UpdateTimeVariables();

		HandleSDLEvent();

		RunRendererPreUpdate();

		RunProgramComponentUpdate();

		RunSystemUpdate();

		RunRendererPostUpdate();

		RunProgramComponentRender();

		RunSystemRender();

		Input::Get()->PostFrame();

		bgfx::frame();
	}
}

void harmony::Program::Run()
{
	HARMONY_PROFILE_FUNCTION()

	PreRunInit();
	RunProgramLoop();
	
}

void harmony::Program::Run(const std::string& projectPath)
{
	HARMONY_PROFILE_FUNCTION()

	PreRunInit();
	RunProgramLoop();
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

	nlohmann::json projectJson = *m_Project;
	Utils::SaveJsonToPath(projectJson, p_LoadedProjectPath);
}

void harmony::Program::LoadProject(const std::string& path)
{
	HARMONY_PROFILE_FUNCTION()
	CloseActiveProject();

	nlohmann::json projectJson = Utils::LoadJsonFromPath(path);
	m_Project = CreateRef<Project>(projectJson);
		
	UpdateProjectDirectory(path);
	
	m_AssetManager.Deserialize(m_Project->m_AssetManagerSerializationAttributes);
	m_Renderer.Deserialize(m_AssetManager, m_Project->m_RendererSerializationAttributes);

	p_LoadedProjectPath = m_Project->m_ProjectDirectory + "/" + m_Project->m_ProjectName + ".harmonyproj";

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

	m_AssetManager.UnloadAllAssets();

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

void harmony::Program::SaveImGuiSettings()
{
	m_Project->m_ImGuiIniPath = m_Project->m_ProjectName + "_ImGui.ini";
	ImGui::SaveIniSettingsToDisk(m_Project->m_ImGuiIniPath.c_str());
}

void harmony::Program::LoadImGuiSettings()
{
	m_Project->m_ImGuiIniPath = m_Project->m_ProjectName + "_ImGui.ini";
	if (std::filesystem::exists(m_Project->m_ImGuiIniPath))
	{
		ImGui::LoadIniSettingsFromDisk(m_Project->m_ImGuiIniPath.c_str());
	}
}

void harmony::Program::UpdateProjectDirectory(const std::string& path)
{
	std::string directory = Utils::GetFilePathDirectory(path);
	ChangeWorkingDirectory(directory);
	directory = GetWorkingDirectory();
	harmony::log::info("Current working directory : {}", directory);

	m_Project->m_ProjectDirectory = directory;
}