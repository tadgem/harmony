#include "Core/Alias.h"

#define GET_TYPE_HASH(x) harmony::HashString(#x)

namespace harmony
{
    struct HashString
    {
        HashString(const String& input);
        const uint64_t m_Value;

        bool operator==(HashString const& rhs) const { return m_Value == rhs.m_Value; }

    protected:
        static uint64_t Hash(const String& input);
    };


    HashString::HashString(const String& input) : m_Value(Hash(input))
    {
    }

    uint64_t HashString::Hash(const String& input)
    {
        uint64_t r;
        for (int i = 0; i < input.size(); i++)
        {
            char c = input[i];
            r ^= 397 * c;
        }
        return r;
    }
}