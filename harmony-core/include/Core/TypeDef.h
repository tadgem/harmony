#ifndef HARMONY_CORE_TYPEDEF_H
#define HARMONY_CORE_TYPEDEF_H

#include "Core/Alias.h"
#include "ThirdParty/json.hpp"

#define GET_TYPE_HASH(x) harmony::HashString(#x)

namespace harmony {
    struct HashString {
        HashString() { m_Value = 0; }

        HashString(const String &input);

        uint64_t m_Value;

        bool operator==(HashString const &rhs) const { return m_Value == rhs.m_Value; }

        operator uint64_t() const { return m_Value; }

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(HashString, m_Value)

    protected:
        static uint64_t Hash(const String &input);
    };
}
#endif