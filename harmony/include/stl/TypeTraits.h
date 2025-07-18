#pragma once

#include <type_traits>

namespace harmony
{
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

}