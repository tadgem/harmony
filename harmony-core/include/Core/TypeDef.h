#pragma once

#include "STL/Json.hpp"
#include "STL/String.h"

namespace typehash_internal
{
    static const unsigned int FRONT_SIZE = sizeof("typehash_internal::GetTypeNameHelper<") - 1u;
    static const unsigned int BACK_SIZE = sizeof(">::GetTypeName") - 1u;

    template <typename T>
    struct GetTypeNameHelper {
        static harmony::String GetTypeName(void) {
            static const size_t size = sizeof(__FUNCTION__) - FRONT_SIZE - BACK_SIZE;
            harmony::String typeString = harmony::String(__FUNCTION__ + FRONT_SIZE, size - 1u);
            return typeString;
        }
    };
}


namespace harmony {
    struct HashString {
        HashString() { m_Value = 0; }

        HashString(const String &input);
        HashString(uint64_t value);

        uint64_t m_Value;

        bool operator==(HashString const &rhs) const { return m_Value == rhs.m_Value; }

        operator uint64_t() const { return m_Value; }

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(HashString, m_Value)

    protected:
        static uint64_t Hash(const String &input);
    };

    template <typename T>
    const String GetTypeName(void) {
        return typehash_internal::GetTypeNameHelper<T>::GetTypeName();
    }

    template<typename T>
    HashString GetTypeHash() {
        return HashString(GetTypeName<T>());
    }

}