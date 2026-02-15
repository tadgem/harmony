#pragma once
#include "Macros.h"
#include "Primitives.h"
#undef MI_DEBUG
#include "mimalloc.h"

/// <summary>
/// Macro to globally override new
/// Used to track non-allocator'd code
/// while still use the upfront page we create for the engine
/// </summary>
#define HARMONY_OVERRIDE_GLOBAL_NEW(ENABLE_PRINT)                              \
  void *__cdecl operator new[](size_t size, const char *name, int flags,       \
                               unsigned debugFlags, const char *file,          \
                               int line) {                                     \
    ENABLE_PRINT ? printf("Unassigned Allocation!\n") : 0;                     \
    HNY_ASSERT_NOT_REACHED();                                                  \
    return mi_malloc(size);                                                    \
  }                                                                            \
                                                                               \
  void *__cdecl operator new[](size_t size, unsigned __int64,                  \
                               unsigned __int64, char const *, int,            \
                               unsigned int, char const *, int) {              \
    ENABLE_PRINT ? printf("Unassigned Allocation!\n") : 0;                     \
    HNY_ASSERT_NOT_REACHED();                                                  \
    return mi_malloc(size);                                                    \
  }

#define HNY_NEW(Type, ...) new (mi_malloc(sizeof(Type))) Type(__VA_ARGS__)
#define HNY_DELETE(Obj) mi_free(Obj)

namespace harmony {

template <class T> struct STLMimallocAllocator {
  typedef T value_type;

  STLMimallocAllocator() {} // default ctor not required by C++ Standard Library

  // A converting copy constructor:
  template <class U> STLMimallocAllocator(const STLMimallocAllocator<U> &o) {}
  template <class U> bool operator==(const STLMimallocAllocator<U> &) const {
    return true;
  }
  template <class U> bool operator!=(const STLMimallocAllocator<U> &) const {
    return false;
  }
  T *allocate(const size_t n) const {
    return static_cast<T *>(mi_malloc(sizeof(T)));
  }
  void deallocate(T *const p, size_t) const { mi_free((void *)p); }
};

template <typename T> class mimalloc_default_delete {
public:
  void operator()(T *p) const { mi_free((void *)p); }
};

/// <summary>
/// Global struct creating memory and
/// allowing creation of sub allocators for specific use cases
/// </summary>
struct Memory {
  inline static uint64 g_allocated_bytes = 0;
  inline static void *g_memory = nullptr;
  mi_arena_id_t arena_id;
  mi_heap_t *heap;
  mi_heap_t *prev_heap;

  void free() {
    if (heap == nullptr)
    {
      return;
    }
    mi_heap_set_default(prev_heap);
    mi_collect(true);
    _aligned_free(g_memory);
    g_memory = nullptr;
  }

  static void init_global(uint64 upfrontMemory) {
    g_memory = _aligned_malloc(upfrontMemory, KILOBYTES(64));
    g_allocated_bytes = upfrontMemory;
    memset(g_memory, 0, g_allocated_bytes);
    mi_option_set(mi_option_show_errors, 1);
    mi_option_set(mi_option_verbose, 0);
    mi_option_set(mi_option_arena_eager_commit, 1);
    mi_option_set(mi_option_purge_delay, 0);
    mi_option_set(mi_option_purge_decommits, 0);
    mi_option_set(mi_option_allow_large_os_pages, 1);
  }

  static Memory create_contiguous(uint64 upfrontMemory) {

    if (g_memory == nullptr) {
      init_global(upfrontMemory);
    }

    mi_arena_id_t arenaId;
    constexpr bool is_committed = true;
    constexpr bool is_large = true;
    constexpr bool is_exclusive = true;
    constexpr bool is_zeroed = true;
    constexpr int numa_mode = -1;
    mi_manage_os_memory_ex(g_memory, upfrontMemory, is_committed, is_large,
                           is_zeroed, numa_mode, is_exclusive, &arenaId);

    mi_heap_t *engineHeap = mi_heap_new_in_arena(arenaId);
    mi_heap_t *previousHeap = mi_heap_get_default();
    mi_heap_set_default(engineHeap);

    return Memory{arenaId, engineHeap, previousHeap};
  }

  static Memory create()
  {
    mi_arena_id_t arenaId = {};

    return Memory {arenaId, nullptr, nullptr};
  }
};
} // namespace harmony
