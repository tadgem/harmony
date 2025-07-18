#pragma once
#include <string>
#include <sstream>

namespace harmony
{
    using String = std::string;

    using StringView = std::string_view;

    using StringStream = std::stringstream;

    inline String ToString(int _Val) {
        return std::to_string(_Val);
    }

    inline String ToString(unsigned int _Val) {
        return std::to_string(_Val);
    }

    inline String ToString(long _Val) {
        return std::to_string(_Val);
    }

    inline String ToString(unsigned long _Val) {
        return std::to_string(_Val);
    }

    inline String ToString(long long _Val) {
        return std::to_string(_Val);
    }

    inline String ToString(unsigned long long _Val) {
        return std::to_string(_Val);
    }

    template <typename... Args>
    inline auto stoi(Args&&... args) -> decltype(f(std::forward<Args>(args)...)) {
        return std::stoi(std::forward<Args>(args)...);
    }

    template <typename... Args>
    inline auto stoul(Args&&... args) -> decltype(f(std::forward<Args>(args)...)) {
        return std::stoul(std::forward<Args>(args)...);
    }
}
