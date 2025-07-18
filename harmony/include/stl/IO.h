#pragma once
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