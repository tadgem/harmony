#include "WGPUBackend.h"

void harmony::WGPUBackend::init() {
  window = SDL_CreateWindow("HARMONY", 1600, 900, SDL_WINDOW_RESIZABLE);
}

void harmony::WGPUBackend::pre_frame() {

}

void harmony::WGPUBackend::end_frame() {

}

void harmony::WGPUBackend::cleanup() {

}

bool harmony::WGPUBackend::should_run() {
  return true;
}
