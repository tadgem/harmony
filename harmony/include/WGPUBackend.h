#pragma once
#include "Backend.h"
#include "sdl3webgpu.h"

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

  protected:
    SDL_Window*   window = nullptr;
    WGPUInstance  wgpu_instance = nullptr;
    WGPUSurface   wgpu_surface = nullptr;

    bool          _should_run = true;



  };
}