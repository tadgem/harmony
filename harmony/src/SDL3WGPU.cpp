#include "SDL3WGPU.h"

#if defined(SDL_PLATFORM_WIN32)
#include "windows.h"
#endif

namespace harmony
{
  WGPUSurface SDL_GetWGPUSurface(WGPUInstance instance, SDL_Window *window)
  {
#if defined(SDL_PLATFORM_WIN32)
    HWND hwnd = (HWND)SDL_GetPointerProperty(SDL_GetWindowProperties(window), SDL_PROP_WINDOW_WIN32_HWND_POINTER, NULL);
    if (hwnd) {
      HINSTANCE hinstance = GetModuleHandle(NULL);

      WGPUSurfaceSourceWindowsHWND fromWindowsHWND;
      fromWindowsHWND.chain.sType = WGPUSType_SurfaceSourceWindowsHWND;
      fromWindowsHWND.chain.next = NULL;
      fromWindowsHWND.hinstance = hinstance;
      fromWindowsHWND.hwnd = hwnd;

      WGPUSurfaceDescriptor surfaceDescriptor;
      surfaceDescriptor.nextInChain = &fromWindowsHWND.chain;
      surfaceDescriptor.label = (WGPUStringView){ NULL, WGPU_STRLEN };

      return wgpuInstanceCreateSurface(instance, &surfaceDescriptor);
    }
#elif defined(SDL_PLATFORM_EMSCRIPTEN)
#elif defined(SDL_VIDEO_DRIVER_EMSCRIPTEN)
    {
#  ifdef WEBGPU_BACKEND_EMDAWNWEBGPU
      WGPUEmscriptenSurfaceSourceCanvasHTMLSelector fromCanvasHTMLSelector;
      fromCanvasHTMLSelector.chain.sType = WGPUSType_EmscriptenSurfaceSourceCanvasHTMLSelector;
#  else
      WGPUSurfaceDescriptorFromCanvasHTMLSelector fromCanvasHTMLSelector;
      fromCanvasHTMLSelector.chain.sType = WGPUSType_SurfaceDescriptorFromCanvasHTMLSelector;
#  endif
      fromCanvasHTMLSelector.chain.next = NULL;
      fromCanvasHTMLSelector.selector = "canvas";

      WGPUSurfaceDescriptor surfaceDescriptor;
      surfaceDescriptor.nextInChain = &fromCanvasHTMLSelector.chain;
      surfaceDescriptor.label = NULL;

      return wgpuInstanceCreateSurface(instance, &surfaceDescriptor);
    }

#elif defined(SDL_PLATFORM_MACOS)
    NSWindow *nswindow = (__bridge NSWindow *)SDL_GetPointerProperty(SDL_GetWindowProperties(window), SDL_PROP_WINDOW_COCOA_WINDOW_POINTER, NULL);
    if (nswindow) {
      [ns_window.contentView setWantsLayer : YES];
      metal_layer = [CAMetalLayer layer];
      [ns_window.contentView setLayer : metal_layer];

      WGPUSurfaceSourceMetalLayer fromMetalLayer;
      fromMetalLayer.chain.sType = WGPUSType_SurfaceSourceMetalLayer;
      fromMetalLayer.chain.next = NULL;
      fromMetalLayer.layer = metal_layer;

      WGPUSurfaceDescriptor surfaceDescriptor;
      surfaceDescriptor.nextInChain = &fromMetalLayer.chain;
      surfaceDescriptor.label = (WGPUStringView){ NULL, WGPU_STRLEN };

      return wgpuInstanceCreateSurface(instance, &surfaceDescriptor);
    }
#elif defined(SDL_PLATFORM_LINUX)
    if (SDL_strcmp(SDL_GetCurrentVideoDriver(), "x11") == 0) {
      Display *xdisplay = (Display *)SDL_GetPointerProperty(SDL_GetWindowProperties(window), SDL_PROP_WINDOW_X11_DISPLAY_POINTER, NULL);
      Window xwindow = (Window)SDL_GetNumberProperty(SDL_GetWindowProperties(window), SDL_PROP_WINDOW_X11_WINDOW_NUMBER, 0);
      if (xdisplay && xwindow) {
        WGPUSurfaceSourceXlibWindow fromXlibWindow;
        fromXlibWindow.chain.sType = WGPUSType_SurfaceSourceXlibWindow;
        fromXlibWindow.chain.next = NULL;
        fromXlibWindow.display = xdisplay;
        fromXlibWindow.window = xwindow;

        WGPUSurfaceDescriptor surfaceDescriptor;
        surfaceDescriptor.nextInChain = &fromXlibWindow.chain;
        surfaceDescriptor.label = (WGPUStringView){ NULL, WGPU_STRLEN };

        return wgpuInstanceCreateSurface(instance, &surfaceDescriptor);
      }
    } else if (SDL_strcmp(SDL_GetCurrentVideoDriver(), "wayland") == 0) {
      struct wl_display *display = (struct wl_display *)SDL_GetPointerProperty(SDL_GetWindowProperties(window), SDL_PROP_WINDOW_WAYLAND_DISPLAY_POINTER, NULL);
      struct wl_surface *surface = (struct wl_surface *)SDL_GetPointerProperty(SDL_GetWindowProperties(window), SDL_PROP_WINDOW_WAYLAND_SURFACE_POINTER, NULL);
      if (display && surface) {
        WGPUSurfaceSourceWaylandSurface fromWaylandSurface;
        fromWaylandSurface.chain.sType = WGPUSType_SurfaceSourceWaylandSurface;
        fromWaylandSurface.chain.next = NULL;
        fromWaylandSurface.display = display;
        fromWaylandSurface.surface = surface;

        WGPUSurfaceDescriptor surfaceDescriptor;
        surfaceDescriptor.nextInChain = &fromWaylandSurface.chain;
        surfaceDescriptor.label = (WGPUStringView){ NULL, WGPU_STRLEN };

        return wgpuInstanceCreateSurface(instance, &surfaceDescriptor);
      }
    }
#elif defined(SDL_PLATFORM_IOS)
    SDL_PropertiesID props = SDL_GetWindowProperties(window);
    UIWindow *ui_window = (__bridge UIWindow *)SDL_GetPointerProperty(props, SDL_PROP_WINDOW_UIKIT_WINDOW_POINTER, NULL);
    if (ui_window) {
      GLuint framebuffer = (GLuint)SDL_GetNumberProperty(props, SDL_PROP_WINDOW_UIKIT_OPENGL_FRAMEBUFFER_NUMBER, 0);
      GLuint colorbuffer = (GLuint)SDL_GetNumberProperty(props, SDL_PROP_WINDOW_UIKIT_OPENGL_RENDERBUFFER_NUMBER, 0);
      GLuint resolveFramebuffer = (GLuint)SDL_GetNumberProperty(props, SDL_PROP_WINDOW_UIKIT_OPENGL_RESOLVE_FRAMEBUFFER_NUMBER, 0);

      UIView* ui_view = ui_window.rootViewController.view;
      CAMetalLayer* metal_layer = [CAMetalLayer new];
      metal_layer.opaque = true;
      metal_layer.frame = ui_view.frame;
      metal_layer.drawableSize = ui_view.frame.size;

      [ui_view.layer addSublayer: metal_layer];

      WGPUSurfaceSourceMetalLayer fromMetalLayer;
      fromMetalLayer.chain.sType = WGPUSType_SurfaceSourceMetalLayer;
      fromMetalLayer.chain.next = NULL;
      fromMetalLayer.layer = metal_layer;

      WGPUSurfaceDescriptor surfaceDescriptor;
      surfaceDescriptor.nextInChain = &fromMetalLayer.chain;
      surfaceDescriptor.label = (WGPUStringView){ NULL, WGPU_STRLEN };

      return wgpuInstanceCreateSurface(instance, &surfaceDescriptor);
    }
#endif
  }
}