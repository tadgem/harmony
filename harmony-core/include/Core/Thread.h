#pragma once

#include "Core/BS_thread_pool.hpp"

namespace harmony {
    static BS::thread_pool ThreadPool;

    template<typename R>
    bool is_ready(std::future<R> const &f) {
        return f.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
    }
}