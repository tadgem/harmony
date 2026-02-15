#pragma once
#include "Alloc.h"
#include "AssetManager.h"
#include "Macros.h"
#include "Primitives.h"
#include "Backend.h"
#include "WGPUBackend.h"

namespace harmony {
class Engine {
private:
  struct Prelude
  {
    Memory        engine_memory;
    AssetManager* asset_manager;
  };

  static Prelude _internal_init(uint64 upfrontMemory);

public:
  Memory engine_memory;
  Unique<AssetManager>  asset_manager;
  Unique<Backend>       backend;
  bool mEnableMSAA = false;

  template<typename _Backend = WGPUBackend, typename ... Args>
  static Engine Init(uint32 swapchainWidth = 1920,
                     uint32 swapchainHeight = 1080, bool enableMSAA = false,
                     uint64 upfrontMemory = GIGABYTES(4),
                     bool enableValidation = true, Args&& ... args )
  {
    static_assert(std::is_base_of<Backend, _Backend>());

    Prelude p = _internal_init(upfrontMemory);

    _Backend* b = HNY_NEW(_Backend, std::forward<Args>(args) ...);

    // spin up backend
    b->init();

    return Engine {
        p.engine_memory,
        Unique<AssetManager>(p.asset_manager),
        Unique<Backend>(static_cast<Backend*>(b)),
        enableMSAA
    };
  }

  [[nodiscard]]
  bool should_run() const;
  void pre_frame() const;
  void end_frame() const;
  void shutdown();

  ~Engine() { shutdown(); }


};
} // namespace harmony
