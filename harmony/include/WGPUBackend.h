#pragma once
#include "Backend.h"
#include "sdl3webgpu.h"
#include "imgui.h"

namespace harmony
{
  class WGPUBackend : public Backend
  {
  public:

    void init()         override;
    void pre_frame()    override;
    void end_frame()    override;
    void cleanup()      override;
    bool should_run()   override;

    SDL_Window*   window = nullptr;
    WGPUInstance  wgpu_instance = nullptr;
    WGPUSurface   wgpu_surface = nullptr;
    WGPUAdapter   wgpu_adapter = nullptr;
    WGPUDevice    wgpu_device = nullptr;
    ImGuiContext* imgui_ctx;

  protected:

    bool          _should_run     = true;
    bool          _waitingAdapter = true;
    bool          _waitingDevice  = true;



  };
}