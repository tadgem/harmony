#pragma once
#include "Backend.h"
#include "SDL3WGPU.h"

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
    SDL_Window* window = nullptr;


  };
}