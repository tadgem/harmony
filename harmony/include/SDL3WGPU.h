#pragma once

#include "webgpu/webgpu.h"
#include "SDL3/SDL.h"

namespace harmony {
  WGPUSurface SDL_GetWGPUSurface(WGPUInstance instance, SDL_Window *window);
}