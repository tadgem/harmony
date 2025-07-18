#pragma once
#include <utility>
#include <cmath>

namespace harmony
{
    inline static float FAbs(float f) {
        return std::abs(f);
    }

    inline static float FMin(float a, float b) {
        return std::min(a, b);
    }
}