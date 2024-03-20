#ifndef HARMONY_CORE_STL_ARRAY_H
#define HARMONY_CORE_STL_ARRAY_H
#include <array>
namespace harmony
{
    template<typename T, size_t N>
    using Array = std::array<T, N>;
}

#endif