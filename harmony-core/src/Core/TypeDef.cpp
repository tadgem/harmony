#include "Core/TypeDef.h"
#include "Core/Log.hpp"

harmony::HashString::HashString(const String &input) : m_Value(Hash(input)) {
}

harmony::HashString::HashString(uint64_t value) : m_Value(value)
{
}
uint64_t harmony::HashString::Hash(const String &input) {
    // write down typehashes for project and update via find & replace
    uint64_t r = 0;
    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        r ^= 397 * c;
    }
    return r;
}
