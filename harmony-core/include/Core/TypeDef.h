#ifndef HARMONY_CORE_TYPEDEF_H
#define HARMONY_CORE_TYPEDEF_H

#include "Core/Alias.h"
#include "ThirdParty/json.hpp"

namespace typehash_internal
{
    static const unsigned int FRONT_SIZE = sizeof("typehash_internal::GetTypeNameHelper<") - 1u;
    static const unsigned int BACK_SIZE = sizeof(">::GetTypeName") - 1u;

    template <typename T>
    struct GetTypeNameHelper {
        static std::string GetTypeName(void) {
            static const size_t size = sizeof(__FUNCTION__) - FRONT_SIZE - BACK_SIZE;
            std::string typeString = std::string(__FUNCTION__ + FRONT_SIZE, size - 1u);
            return typeString;
        }
    };
}


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

    template <typename T>
    const std::string GetTypeName(void) {
        return typehash_internal::GetTypeNameHelper<T>::GetTypeName();
    }

    template<typename T>
    HashString GetTypeHash() {
        return HashString(GetTypeName<T>());
    }

}
#endif