#pragma once
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <functional>

namespace harmony
{
    using String = std::string;

    template<typename T1, typename T2>
    using Map = std::map<T1, T2>;

    template<typename T1, typename T2>
    using HashMap = std::unordered_map<T1, T2>;

    template<typename T>
    using Vector = std::vector<T>;

    template<typename T>
    using Lambda = std::function<T>;
}