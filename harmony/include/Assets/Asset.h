#pragma once
#include "json.hpp"

namespace harmony
{
    template <typename T>
    static size_t GetTypeHash()
    {
        return typeid(T).hash_code();
    }

    template<typename T>
    struct AssetComponent
    {
        Ref<T> Asset;
    };

    struct AssetHandle
    {
        std::string Path;
        uint32_t Index;
        size_t TypeHash;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(AssetHandle, Path, Index, TypeHash)
    };

    class Asset
    {
    public:
        AssetHandle m_Handle;
        Asset(size_t typeHash);
        virtual ~Asset() {}

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Asset, m_Handle)
    };
};