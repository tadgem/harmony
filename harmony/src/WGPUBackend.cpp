#include "WGPUBackend.h"

void harmony::WGPUBackend::init() {

  wgpu_instance = wgpuCreateInstance(NULL);

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("HARMONY", 1600, 900, SDL_WINDOW_RESIZABLE);
  wgpu_surface = SDL_GetWGPUSurface(wgpu_instance, window);
  _should_run = true;
}

void harmony::WGPUBackend::pre_frame() {
  SDL_Event event = {};
  while (SDL_PollEvent(&event))
    if (event.type == SDL_EVENT_QUIT)
    {
      _should_run = false;
    }

}

void harmony::WGPUBackend::end_frame() {

}

void harmony::WGPUBackend::cleanup() {
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool harmony::WGPUBackend::should_run() {
  return _should_run;
}
