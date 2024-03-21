#ifndef HARMONY_CORE_STL_THREAD_H
#define HARMONY_CORE_STL_THREAD_H

#include <future>

namespace harmony
{
    template<typename T>
    using Future = std::future<T>;
    using FutureStatus = std::future_status;

    using Mutex = std::mutex;
    using MutexLock = std::lock_guard<Mutex>;

    namespace ThisThread = std::this_thread;
}
#endif