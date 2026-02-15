#include "WGPUBackend.h"

void harmony::WGPUBackend::Init() {
  mWindow = SDL_CreateWindow("HARMONY", 1600, 900, SDL_WINDOW_RESIZABLE);
}

void harmony::WGPUBackend::PreFrame() {

}

void harmony::WGPUBackend::EndFrame() {

}

void harmony::WGPUBackend::Cleanup() {

}

bool harmony::WGPUBackend::ShouldRun() {
  return true;
}
