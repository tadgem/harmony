#ifndef HARMONY_CORE_ALIAS_H
#define HARMONY_CORE_ALIAS_H

#include <map>
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <future>
#include <utility>
#include <fstream>
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
#include <filesystem>
namespace harmony { 
    using String = std::string;

    template <typename... Args>
    inline auto stoi(Args&&... args) -> decltype(f(std::forward<Args>(args)...)) {
        return std::stoi(std::forward<Args>(args)...);
    }

    template <typename... Args>
    inline auto stoul(Args&&... args) -> decltype(f(std::forward<Args>(args)...)) {
        return std::stoul(std::forward<Args>(args)...);
    }

    inline static float FAbs(float f) {
        return std::abs(f);
    }


    template <typename A, typename B>
    inline auto SmartPointerCast(const std::shared_ptr<B>& ptr)
    {
        return std::static_pointer_cast<A>(ptr);
    }


    using StringStream = std::stringstream;
    
    using OStream = std::ostream;
    using IStream = std::istream;
    using OfStream = std::ofstream;
    using IfStream = std::ifstream;
    
    template<typename T>
    using IStreamBufIterator = std::istreambuf_iterator<T>;

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
    using FutureStatus = std::future_status;

    template<typename A, typename B>
    using IsBaseOf = std::is_base_of<A, B>;

    namespace FileSystem = std::filesystem;

    namespace Chrono = std::chrono;

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

    template <class _InIt, class _Ty>
    _InIt Find(_InIt _First, const _InIt _Last, const _Ty& _Val) {
        return std::find(_First, _Last, _Val);
    }

    template <class _InIt, class _Pr>
    _InIt FindIf(_InIt _First, const _InIt _Last, _Pr _Pred)
    {
        return std::find_if(_First, _Last, _Pred);
    }

    using Procedure = std::function<void()>;

    using Mutex = std::mutex;

    using MutexLock = std::lock_guard<Mutex>;

    using Json = nlohmann::json;
}

#endif