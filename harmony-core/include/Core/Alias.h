#pragma once

#include <map>
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <future>
#include <utility>
#include <sstream>
#include <ostream>
#include <functional>
#include <mutex>
#include <optional>
#include <stack>
#include <thread>
#include "ThirdParty/json.hpp"
#include <regex>
#include <stdio.h>
#include <ctype.h>
#include <string>
namespace harmony { 
    using String = std::string;

    template <typename... Args>
    auto stoi(Args&&... args) -> decltype(f(std::forward<Args>(args)...)) {
        return std::stoi(std::forward<Args>(args)...);
    }

    template <typename A, typename B>
    auto SmartPointerCast(const std::shared_ptr<B>& ptr)
    {
        return std::static_pointer_cast<A>(ptr);
    }


    using StringStream = std::stringstream;

    using OStream = std::ostream;

    template<typename T>
    using Optional  = std::optional<T>;

    template<typename T1, typename T2>
    using Map = std::map<T1, T2>;

    template<typename T1, typename T2>
    using HashMap = std::unordered_map<T1, T2>;

    template<typename T>
    using Vector = std::vector<T>;

    template<typename T>
    using Stack = std::stack<T>;

    template<typename T>
    using Lambda = std::function<T>;

    template<typename T>
    using Future = std::future<T>;

    template<typename A, typename B>
    using IsBaseOf = std::is_base_of<A, B>;


    template< class T >
    constexpr T&& Forward(std::remove_reference_t<T>& t) noexcept
    {
        return std::forward<T>(t);
    }

    template< class T >
    constexpr T&& Forward(std::remove_reference_t<T>&& t) noexcept
    {
        return std::forward<T>(t);
    }

    using Procedure = std::function<void()>;

    using Mutex = std::mutex;

    using MutexLock = std::lock_guard<Mutex>;

    using Json = nlohmann::json;
}