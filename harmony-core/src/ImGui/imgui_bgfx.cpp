/*
 * Copyright 2014-2015 Daniel Collin. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include <bgfx/bgfx.h>
#include <bgfx/embedded_shader.h>
#include <bx/allocator.h>
#include <bx/math.h>
#include <bx/timer.h>
#include <ImGui/imgui.h>
#include <ImGui/imgui_internal.h>

#include "ImGui/imgui_bgfx.h"
#include "ImGui/bgfx_utils.h"

//#define USE_ENTRY 1

#ifndef USE_ENTRY
#	define USE_ENTRY 0
#endif // USE_ENTRY

#if USE_ENTRY
#	include "../entry/entry.h"
#	include "../entry/input.h"
#endif // USE_ENTRY

#include "ImGui/vs_ocornut_imgui.bin.h"
#include "ImGui/fs_ocornut_imgui.bin.h"
#include "ImGui/vs_imgui_image.bin.h"
#include "ImGui/fs_imgui_image.bin.h"

#include "ImGui/roboto_regular.ttf.h"
#include "ImGui/robotomono_regular.ttf.h"
#include "ImGui/icons_kenney.ttf.h"
#include "ImGui/icons_font_awesome.ttf.h"
#include "ImGui/icons_kenney.h"
#include "ImGui/icons_font_awesome.h"
#include "SDL.h"
#include "SDL_syswm.h"
#include "ImGui/imgui_bgfx.h"
#include <algorithm>
#include <vector>

static const bgfx::EmbeddedShader s_embeddedShaders[] =
		{
				BGFX_EMBEDDED_SHADER(vs_ocornut_imgui),
				BGFX_EMBEDDED_SHADER(fs_ocornut_imgui),
				BGFX_EMBEDDED_SHADER(vs_imgui_image),
				BGFX_EMBEDDED_SHADER(fs_imgui_image),

				BGFX_EMBEDDED_SHADER_END()
		};

struct FontRangeMerge
{
	const void *data;
	size_t size;
	ImWchar ranges[3];
};

static FontRangeMerge s_fontRangeMerge[] =
		{
				{s_iconsKenneyTtf,      sizeof(s_iconsKenneyTtf),      {ICON_MIN_KI, ICON_MAX_KI, 0}},
				{s_iconsFontAwesomeTtf, sizeof(s_iconsFontAwesomeTtf), {ICON_MIN_FA, ICON_MAX_FA, 0}},
		};

static void *memAlloc(size_t _size, void *_userData);
static void memFree(void *_ptr, void *_userData);
struct ImGuiViewportDataSDL
{
	SDL_Window *Window;
	bgfx::ViewId ViewID;
};

static void *sdlNativeWindowHandle(SDL_Window *_window)
{
	SDL_SysWMinfo wmi;
	SDL_VERSION(&wmi.version);
	if (!SDL_GetWindowWMInfo(_window, &wmi))
	{
		return NULL;
	}

#	if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
#		if ENTRY_CONFIG_USE_WAYLAND
	wl_egl_window* win_impl = (wl_egl_window*)SDL_GetWindowData(_window, "wl_egl_window");
	if (!win_impl)
	{
		int width, height;
		SDL_GetWindowSize(_window, &width, &height);
		struct wl_surface* surface = wmi.info.wl.surface;
		if (!surface)
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

struct OcornutImguiContext
{
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// . . U . .  // Create swap chain, frame buffers etc. (called after Platform_CreateWindow)

	static void renderer_create_window(ImGuiViewport *vp)
	{
		ImGuiViewportDataSDL *data = (ImGuiViewportDataSDL *) vp->PlatformUserData;
		void *native_handle = sdlNativeWindowHandle(data->Window);
		bgfx::FrameBufferHandle handle = bgfx::createFrameBuffer(
				native_handle,
				uint16_t(vp->Size.x),
				uint16_t(vp->Size.y));

		vp->RendererUserData = (void *) (uintptr_t) handle.idx;

		uint32_t newWindowId = BGFX_MAIN_WINDOW_IMGUI_VIEW_ID - 1;

		while (std::find(
				BGFX_SUB_WINDOW_IMGUI_VIEW_IDS.begin(),
				BGFX_SUB_WINDOW_IMGUI_VIEW_IDS.end(),
				newWindowId) != BGFX_SUB_WINDOW_IMGUI_VIEW_IDS.end())
		{
			newWindowId--;
		}

		data->ViewID = (bgfx::ViewId) newWindowId;
		BGFX_SUB_WINDOW_IMGUI_VIEW_IDS.emplace_back(newWindowId);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// N . U . D  // Destroy swap chain, frame buffers etc. (called before Platform_DestroyWindow)

	static void renderer_destroy_window(ImGuiViewport *vp)
	{
		ImGuiViewportDataSDL *data = (ImGuiViewportDataSDL *) vp->PlatformUserData;
		bgfx::FrameBufferHandle handle = {(uint16_t) (uintptr_t) vp->RendererUserData};

		bgfx::destroy(handle);

		// Flush destruction of swap chain before destroying window!
		bgfx::frame();
		bgfx::frame();

		vp->RendererUserData = nullptr;

		uint32_t viewId = data->ViewID;
		auto begin = BGFX_SUB_WINDOW_IMGUI_VIEW_IDS.begin();
		auto end = BGFX_SUB_WINDOW_IMGUI_VIEW_IDS.end();
		auto elementIt = std::find(begin, end, viewId);

		if (elementIt != end)
		{
			BGFX_SUB_WINDOW_IMGUI_VIEW_IDS.erase(elementIt);
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// . . U . .  // Resize swap chain, frame buffers etc. (called after Platform_SetWindowSize)

	static void renderer_set_window_size(ImGuiViewport *vp, ImVec2 size)
	{
		ImGuiViewportDataSDL *data = (ImGuiViewportDataSDL *) vp->PlatformUserData;
		renderer_destroy_window(vp);
		renderer_create_window(vp);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// . . . R .  // (Optional) Clear framebuffer, setup render target, then render the viewport->DrawData. 'render_arg' is the value passed to RenderPlatformWindowsDefault().

	static void renderer_render_window(ImGuiViewport *vp, void *render_arg)
	{
		ImGuiViewportDataSDL *data = (ImGuiViewportDataSDL *) vp->PlatformUserData;
		int display_w, display_h;
		SDL_GetWindowSize(data->Window, &display_w, &display_h);

		bgfx::FrameBufferHandle handle = {(uint16_t) (uintptr_t) vp->RendererUserData};

		bgfx::setViewFrameBuffer(data->ViewID, handle);
		bgfx::setViewRect(data->ViewID, 0, 0, uint16_t(display_w), uint16_t(display_h));

		bgfx::setViewClear(data->ViewID, BGFX_CLEAR_COLOR, 0xff00ffff, 1.0f, 0
		);

		// Set render states.
		bgfx::setState(BGFX_STATE_DEFAULT);

		imguiRenderDraws(vp->DrawData, data->ViewID, display_w, display_h);

		bgfx::touch(data->ViewID);
	}

	void render(ImDrawData *_drawData)
	{
		// Avoid rendering when minimized, scale coordinates for retina displays (screen coordinates != framebuffer coordinates)
		int fb_width = (int) (_drawData->DisplaySize.x * _drawData->FramebufferScale.x);
		int fb_height = (int) (_drawData->DisplaySize.y * _drawData->FramebufferScale.y);
		if (fb_width <= 0 || fb_height <= 0)
		{
			return;
		}

		bgfx::setViewName(m_viewId, "ImGui");
		bgfx::setViewMode(m_viewId, bgfx::ViewMode::Sequential);

		const bgfx::Caps *caps = bgfx::getCaps();
		{
			float ortho[16];
			float x = _drawData->DisplayPos.x;
			float y = _drawData->DisplayPos.y;
			float width = _drawData->DisplaySize.x;
			float height = _drawData->DisplaySize.y;

			bx::mtxOrtho(ortho, x, x + width, y + height, y, 0.0f, 1000.0f, 0.0f, caps->homogeneousDepth);
			bgfx::setViewTransform(m_viewId, NULL, ortho);
			bgfx::setViewRect(m_viewId, 0, 0, uint16_t(width), uint16_t(height));
		}

		const ImVec2 clipPos = _drawData->DisplayPos;       // (0,0) unless using multi-viewports
		const ImVec2 clipScale = _drawData->FramebufferScale; // (1,1) unless using retina display which are often (2,2)

		// Render command lists
		for (int32_t ii = 0, num = _drawData->CmdListsCount; ii < num; ++ii)
		{
			bgfx::TransientVertexBuffer tvb;
			bgfx::TransientIndexBuffer tib;
			const ImDrawList *drawList = _drawData->CmdLists[ii];
			uint32_t numVertices = (uint32_t) drawList->VtxBuffer.size();
			uint32_t numIndices = (uint32_t) drawList->IdxBuffer.size();

			//if (!checkAvailTransientBuffers(numVertices, m_layout, numIndices) )
			//{
			//	// not enough space in transient buffer just quit drawing the rest...
			//	break;
			//}

			bgfx::allocTransientVertexBuffer(&tvb, numVertices, m_layout);
			bgfx::allocTransientIndexBuffer(&tib, numIndices, sizeof(ImDrawIdx) == 4);

			ImDrawVert *verts = (ImDrawVert *) tvb.data;
			bx::memCopy(verts, drawList->VtxBuffer.begin(), numVertices * sizeof(ImDrawVert));

			ImDrawIdx *indices = (ImDrawIdx *) tib.data;
			bx::memCopy(indices, drawList->IdxBuffer.begin(), numIndices * sizeof(ImDrawIdx));

			bgfx::Encoder *encoder = bgfx::begin();

			for (const ImDrawCmd *cmd = drawList->CmdBuffer.begin(), *cmdEnd = drawList->CmdBuffer.end();
				 cmd != cmdEnd; ++cmd)
			{
				if (cmd->UserCallback)
				{
					cmd->UserCallback(drawList, cmd);
				}
				else if (0 != cmd->ElemCount)
				{
					uint64_t state = 0
									 | BGFX_STATE_WRITE_RGB
									 | BGFX_STATE_WRITE_A
									 | BGFX_STATE_MSAA;
					bgfx::TextureHandle th = m_texture;
					bgfx::ProgramHandle program = m_program;

					if (NULL != cmd->TextureId)
					{
						union
						{
							ImTextureID ptr;
							struct
							{
								bgfx::TextureHandle handle;
								uint8_t flags;
								uint8_t mip;
							} s;
						} texture = {cmd->TextureId};
						state |= 0 != (IMGUI_FLAGS_ALPHA_BLEND & texture.s.flags)
								 ? BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_SRC_ALPHA, BGFX_STATE_BLEND_INV_SRC_ALPHA)
								 : BGFX_STATE_NONE;
						th = texture.s.handle;
						if (0 != texture.s.mip)
						{
							const float lodEnabled[4] = {float(texture.s.mip), 1.0f, 0.0f, 0.0f};
							bgfx::setUniform(u_imageLodEnabled, lodEnabled);
							program = m_imageProgram;
						}
					}
					else
					{
						state |= BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_SRC_ALPHA, BGFX_STATE_BLEND_INV_SRC_ALPHA);
					}

					// Project scissor/clipping rectangles into framebuffer space
					ImVec4 clipRect;
					clipRect.x = (cmd->ClipRect.x - clipPos.x) * clipScale.x;
					clipRect.y = (cmd->ClipRect.y - clipPos.y) * clipScale.y;
					clipRect.z = (cmd->ClipRect.z - clipPos.x) * clipScale.x;
					clipRect.w = (cmd->ClipRect.w - clipPos.y) * clipScale.y;

					if (clipRect.x < fb_width
						&& clipRect.y < fb_height
						&& clipRect.z >= 0.0f
						&& clipRect.w >= 0.0f)
					{
						const uint16_t xx = uint16_t(bx::max(clipRect.x, 0.0f));
						const uint16_t yy = uint16_t(bx::max(clipRect.y, 0.0f));
						encoder->setScissor(xx, yy, uint16_t(bx::min(clipRect.z, 65535.0f) - xx),
											uint16_t(bx::min(clipRect.w, 65535.0f) - yy)
						);

						encoder->setState(state);
						encoder->setTexture(0, s_tex, th);
						encoder->setVertexBuffer(0, &tvb, cmd->VtxOffset, numVertices);
						encoder->setIndexBuffer(&tib, cmd->IdxOffset, cmd->ElemCount);
						encoder->submit(m_viewId, program);
					}
				}
			}

			bgfx::end(encoder);
		}
	}

	void create(float _fontSize, bx::AllocatorI *_allocator)
	{
		m_allocator = _allocator;

		if (NULL == _allocator)
		{
			static bx::DefaultAllocator allocator;
			m_allocator = &allocator;
		}

		m_viewId = BGFX_MAIN_WINDOW_IMGUI_VIEW_ID;
		m_lastScroll = 0;
		m_last = bx::getHPCounter();

		ImGui::SetAllocatorFunctions(memAlloc, memFree, NULL);

		m_imgui = ImGui::CreateContext();

		ImGuiIO &io = ImGui::GetIO();

		io.DisplaySize = ImVec2(1280.0f, 720.0f);
		io.DeltaTime = 1.0f / 60.0f;
		io.IniFilename = NULL;

		ImGuiPlatformIO &platform_io = ImGui::GetPlatformIO();
		platform_io.Renderer_CreateWindow = renderer_create_window;
		platform_io.Renderer_DestroyWindow = renderer_destroy_window;
		platform_io.Renderer_SetWindowSize = renderer_set_window_size;
		platform_io.Renderer_RenderWindow = renderer_render_window;
		platform_io.Renderer_SwapBuffers = nullptr;

		setupStyle(true);

		io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;
		io.BackendFlags |= ImGuiBackendFlags_RendererHasViewports;

		bgfx::RendererType::Enum type = bgfx::getRendererType();
		m_program = bgfx::createProgram(
				bgfx::createEmbeddedShader(s_embeddedShaders, type, "vs_ocornut_imgui"),
				bgfx::createEmbeddedShader(s_embeddedShaders, type, "fs_ocornut_imgui"), true
		);

		u_imageLodEnabled = bgfx::createUniform("u_imageLodEnabled", bgfx::UniformType::Vec4);
		m_imageProgram = bgfx::createProgram(
				bgfx::createEmbeddedShader(s_embeddedShaders, type, "vs_imgui_image"),
				bgfx::createEmbeddedShader(s_embeddedShaders, type, "fs_imgui_image"), true
		);

		m_layout
				.begin()
				.add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
				.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
				.add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
				.end();

		s_tex = bgfx::createUniform("s_tex", bgfx::UniformType::Sampler);

		uint8_t *data;
		int32_t width;
		int32_t height;
		{
			ImFontConfig config;
			config.FontDataOwnedByAtlas = false;
			config.MergeMode = false;
			//			config.MergeGlyphCenterV = true;

			const ImWchar *ranges = io.Fonts->GetGlyphRangesCyrillic();
			m_font[ImGui::Font::Regular] = io.Fonts->AddFontFromMemoryTTF((void *) s_robotoRegularTtf,
																		  sizeof(s_robotoRegularTtf), _fontSize,
																		  &config, ranges);
			m_font[ImGui::Font::Mono] = io.Fonts->AddFontFromMemoryTTF((void *) s_robotoMonoRegularTtf,
																	   sizeof(s_robotoMonoRegularTtf), _fontSize,
																	   &config, ranges);

			config.MergeMode = true;
			config.DstFont = m_font[ImGui::Font::Regular];

			for (uint32_t ii = 0; ii < BX_COUNTOF(s_fontRangeMerge); ++ii)
			{
				const FontRangeMerge &frm = s_fontRangeMerge[ii];

				io.Fonts->AddFontFromMemoryTTF((void *) frm.data, (int) frm.size, _fontSize - 3.0f, &config, frm.ranges
				);
			}
		}

		io.Fonts->GetTexDataAsRGBA32(&data, &width, &height);

		m_texture = bgfx::createTexture2D(
				(uint16_t) width, (uint16_t) height, false, 1, bgfx::TextureFormat::BGRA8, 0,
				bgfx::copy(data, width * height * 4)
		);

		//ImGui::InitDockContext();
	}

	void destroy()
	{
		// ImGui::ShutdownDockContext();
		ImGui::DestroyContext(m_imgui);

		bgfx::destroy(s_tex);
		bgfx::destroy(m_texture);

		bgfx::destroy(u_imageLodEnabled);
		bgfx::destroy(m_imageProgram);
		bgfx::destroy(m_program);

		m_allocator = NULL;
	}

	void setupStyle(bool _dark)
	{
		// Doug Binks' darl color scheme
		// https://gist.github.com/dougbinks/8089b4bbaccaaf6fa204236978d165a9
		ImGuiStyle &style = ImGui::GetStyle();
		if (_dark)
		{
			ImGui::StyleColorsDark(&style);
		}
		else
		{
			ImGui::StyleColorsLight(&style);
		}

	}

	void beginFrame(
			int32_t _mx, int32_t _my, uint8_t _button, int32_t _scroll, int _width, int _height, int _inputChar,
			bgfx::ViewId _viewId
	)
	{
		m_viewId = _viewId;

		ImGuiIO &io = ImGui::GetIO();
		if (_inputChar >= 0)
		{
			io.AddInputCharacter(_inputChar);
		}

		// io.DisplaySize = ImVec2( (float)_width, (float)_height);

		const int64_t now = bx::getHPCounter();
		const int64_t frameTime = now - m_last;
		m_last = now;
		const double freq = double(bx::getHPFrequency());
		io.DeltaTime = float(frameTime / freq);

		io.AddMousePosEvent((float) _mx, (float) _my);
		io.AddMouseButtonEvent(ImGuiMouseButton_Left, 0 != (_button & IMGUI_MBUT_LEFT));
		io.AddMouseButtonEvent(ImGuiMouseButton_Right, 0 != (_button & IMGUI_MBUT_RIGHT));
		io.AddMouseButtonEvent(ImGuiMouseButton_Middle, 0 != (_button & IMGUI_MBUT_MIDDLE));
		io.AddMouseWheelEvent(0.0f, (float) (_scroll - m_lastScroll));
		m_lastScroll = _scroll;

#if USE_ENTRY
		uint8_t modifiers = inputGetModifiersState();
		io.AddKeyEvent(ImGuiKey_ModShift, 0 != (modifiers & (entry::Modifier::LeftShift | entry::Modifier::RightShift) ) );
		io.AddKeyEvent(ImGuiKey_ModCtrl,  0 != (modifiers & (entry::Modifier::LeftCtrl  | entry::Modifier::RightCtrl ) ) );
		io.AddKeyEvent(ImGuiKey_ModAlt,   0 != (modifiers & (entry::Modifier::LeftAlt   | entry::Modifier::RightAlt  ) ) );
		io.AddKeyEvent(ImGuiKey_ModSuper, 0 != (modifiers & (entry::Modifier::LeftMeta  | entry::Modifier::RightMeta ) ) );
		for (int32_t ii = 0; ii < (int32_t)entry::Key::Count; ++ii)
		{
			io.AddKeyEvent(m_keyMap[ii], inputGetKeyState(entry::Key::Enum(ii) ) );
			io.SetKeyEventNativeData(m_keyMap[ii], 0, 0, ii);
		}
#endif // USE_ENTRY

		ImGui::NewFrame();

		// ImGuizmo::BeginFrame();
	}

	void endFrame()
	{
		ImGui::Render();
		render(ImGui::GetDrawData());
	}

	ImGuiContext *m_imgui;
	bx::AllocatorI *m_allocator;
	bgfx::VertexLayout m_layout;
	bgfx::ProgramHandle m_program;
	bgfx::ProgramHandle m_imageProgram;
	bgfx::TextureHandle m_texture;
	bgfx::UniformHandle s_tex;
	bgfx::UniformHandle u_imageLodEnabled;
	ImFont *m_font[ImGui::Font::Count];
	int64_t m_last;
	int32_t m_lastScroll;
	bgfx::ViewId m_viewId;
#if USE_ENTRY
	ImGuiKey m_keyMap[(int)entry::Key::Count];
#endif // USE_ENTRY
};

static OcornutImguiContext s_ctx;

static void *memAlloc(size_t _size, void *_userData)
{
	BX_UNUSED(_userData);
	return bx::alloc(s_ctx.m_allocator, _size);
}

static void memFree(void *_ptr, void *_userData)
{
	BX_UNUSED(_userData);
	bx::free(s_ctx.m_allocator, _ptr);
}

void imguiCreate(float _fontSize, bx::AllocatorI *_allocator)
{
	s_ctx.create(_fontSize, _allocator);
}

void imguiDestroy()
{
	s_ctx.destroy();
}

void imguiBeginFrame(int32_t _mx, int32_t _my, uint8_t _button, int32_t _scroll, uint16_t _width, uint16_t _height,
					 int _inputChar, bgfx::ViewId _viewId)
{
	s_ctx.beginFrame(_mx, _my, _button, _scroll, _width, _height, _inputChar, _viewId);
}

void imguiEndFrame()
{
	s_ctx.endFrame();
}

void imguiRenderDraws(ImDrawData *draw_data, int view, int width, int height)
{
	bgfx::ViewId old_view = s_ctx.m_viewId;

	s_ctx.m_viewId = view;
	s_ctx.render(draw_data);
	s_ctx.m_viewId = old_view;
}

BX_PRAGMA_DIAGNOSTIC_IGNORED_MSVC(4505); // error C4505: '' : unreferenced local function has been removed
BX_PRAGMA_DIAGNOSTIC_IGNORED_CLANG_GCC(
		"-Wunused-function"); // warning: 'int rect_width_compare(const void*, const void*)' defined but not used
BX_PRAGMA_DIAGNOSTIC_PUSH();
BX_PRAGMA_DIAGNOSTIC_IGNORED_CLANG("-Wunknown-pragmas")
BX_PRAGMA_DIAGNOSTIC_IGNORED_CLANG_GCC(
		"-Wtype-limits"); // warning: comparison is always true due to limited range of data type
#define STBTT_malloc(_size, _userData) memAlloc(_size, _userData)
#define STBTT_free(_ptr, _userData) memFree(_ptr, _userData)
#define STB_RECT_PACK_IMPLEMENTATION

#include <ThirdParty/stb_rect_pack.h>

#define STB_TRUETYPE_IMPLEMENTATION

#include <ThirdParty/stb_truetype.h>

BX_PRAGMA_DIAGNOSTIC_POP();
