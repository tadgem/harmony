#pragma once

#include "Core/BS_thread_pool.hpp"
#include "STL/Thread.h"

namespace harmony {
    static BS::thread_pool ThreadPool;

    template<typename R>
    bool is_ready(Future<R> const &f) {
        return f.wait_for(Chrono::seconds(0)) == FutureStatus::ready;
    }
}