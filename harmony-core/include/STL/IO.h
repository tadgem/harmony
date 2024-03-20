#ifndef HARMONY_CORE_STL_IO_H
#define HARMONY_CORE_STL_IO_H
#include <fstream>
#include <ostream>
namespace harmony
{
    using OStream = std::ostream;
    using IStream = std::istream;
    using OfStream = std::ofstream;
    using IfStream = std::ifstream;

    template<typename T>
    using IStreamBufIterator = std::istreambuf_iterator<T>;

    using Ios = std::ios;
}

#endif