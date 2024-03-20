#ifndef HARMONY_CORE_STL_HASHMAP_H
#define HARMONY_CORE_STL_HASHMAP_H
#include <unordered_map>
namespace harmony
{
    template<typename T1, typename T2>
    using HashMap = std::unordered_map<T1, T2>;
}

#endif