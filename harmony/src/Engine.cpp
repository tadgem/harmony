#define FLECS_USE_OS_ALLOC
#include "Engine.h"
#include "flecs.h"
#include "mimalloc.h"

void *flecs_mi_malloc(int32 s) {
  void *ptr = mi_malloc(s);
  return ptr;
}

void *flecs_mi_calloc(ecs_size_t s) {
  void *ptr = mi_calloc(1, s);
  return ptr;
}

void *flecs_mi_realloc(void *p, int32 s) {
  void *ptr = mi_realloc(p, s);
  return ptr;
}

void flecs_mi_free(void *p) { mi_free(p); }

namespace harmony {
void InitFlecsCustomAllocator() {
  ecs_os_set_api_defaults();

  ecs_os_api_t api = ecs_os_api;
  api.malloc_ = reinterpret_cast<ecs_os_api_malloc_t>(flecs_mi_malloc);
  api.calloc_ = reinterpret_cast<ecs_os_api_calloc_t>(flecs_mi_calloc);
  api.realloc_ = reinterpret_cast<ecs_os_api_realloc_t>(flecs_mi_realloc);
  api.free_ = reinterpret_cast<ecs_os_api_free_t>(flecs_mi_free);

  ecs_os_set_api(&api);
}

bool Engine::should_run() const { return backend->should_run(); }

void Engine::pre_frame() const {
  backend->pre_frame();
}

void Engine::end_frame() const {
  backend->end_frame();
}
void Engine::shutdown() {
  backend->cleanup();
  asset_manager.reset();

  // Free all engine memory
  // mMemory.Free();
}
Engine::Prelude Engine::_internal_init(uint64 upfrontMemory ) {
  Memory mem = Memory::create();

  // pass mimalloc functions so SDL uses the same memory space.
  SDL_SetMemoryFunctions(mi_malloc, mi_calloc, mi_realloc, mi_free);
  InitFlecsCustomAllocator();

  HNY_LOG_INFO("Allocated Engine Memory : %llu MB\n",
               upfrontMemory / (MEGABYTES(1)));

  auto* am = HNY_NEW(AssetManager);

  return {mem, am};
}
} // namespace harmony
