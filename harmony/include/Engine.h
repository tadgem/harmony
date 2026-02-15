#pragma once
#include "Alloc.h"
#include "AssetManager.h"
#include "Macros.h"
#include "Primitives.h"
#include "Backend.h"

namespace harmony {
class Engine {
private:
  struct Prototype
  {
    Memory        mMemory;
    AssetManager* mAssetManager;
  };

  static Prototype InternalInit(uint64 upfrontMemory);

public:
  Memory mMemory;
  Unique<AssetManager>  mAssetManager;
  Unique<Backend>       mBackend;
  bool mEnableMSAA = false;

  template<typename _Backend, typename ... Args>
  static Engine Init(uint32 swapchainWidth = 1920,
                     uint32 swapchainHeight = 1080, bool enableMSAA = false,
                     uint64 upfrontMemory = GIGABYTES(4),
                     bool enableValidation = true, Args&& ... args )
  {
    static_assert(std::is_base_of<Backend, _Backend>());

    Prototype p = InternalInit(upfrontMemory);

    _Backend* b = HNY_NEW(_Backend, std::forward<Args>(args) ...);

    return Engine {
        p.mMemory,
        Unique<AssetManager>(p.mAssetManager),
        Unique<Backend>(static_cast<Backend*>(b)),
        enableMSAA
    };
  }

  [[nodiscard]]
  bool ShouldRun() const;
  void PreFrame() const;
  void EndFrame() const;
  void Shutdown();

  ~Engine() { Shutdown(); }


};
} // namespace harmony
