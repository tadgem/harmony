#pragma once
#include "json.hpp"

namespace harmony
{
    template <typename T>
    static size_t GetTypeHash()
    {
        return typeid(T).hash_code();
    }

    class Asset
    {
    public:
        std::string m_AssetPath;
        size_t m_TypeHash;
        Asset(size_t typeHash);
        virtual ~Asset() {}
    };
};