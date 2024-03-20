#ifndef HARMONY_CORE_STL_OPTIONAL_H
#define HARMONY_CORE_STL_OPTIONAL_H
#include <optional>
namespace harmony
{
    template<typename T>
    using Optional = std::optional<T>;
}
#endif