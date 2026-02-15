#pragma once
#include "Backend.h"
#include "SDL3WGPU.h"

namespace harmony
{
  class WGPUBackend : public Backend
  {
  public:

    void Init()       override;
    void PreFrame()   override;
    void EndFrame()   override;
    void Cleanup()    override;
    bool ShouldRun()  override;

  protected:
    SDL_Window* mWindow = nullptr;


  };
}