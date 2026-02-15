#pragma once

#include "SDL3/SDL.h"
#include "webgpu/webgpu.h"


namespace harmony {
  WGPUSurface SDL_GetWGPUSurface(WGPUInstance instance, SDL_Window *window);
}