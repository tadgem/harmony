#pragma once

#include "Core/BS_thread_pool.hpp"
#include "Core/Alias.h"

namespace harmony {
    static BS::thread_pool ThreadPool;

    template<typename R>
    bool is_ready(Future<R> const &f) {
        return f.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
    }
}