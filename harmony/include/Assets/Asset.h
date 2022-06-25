#pragma once
#include "json.hpp"
#include "Core/Memory.h"
namespace harmony
{
    template <typename T>
    static size_t GetTypeHash()
    {
        return typeid(T).hash_code();
    }

    struct AssetHandle
    {
        std::string Path;
        uint32_t Index;
        size_t TypeHash;

        bool operator==(AssetHandle other);

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(AssetHandle, Path, Index, TypeHash)
    };

    template<typename T>
    struct AssetComponent
    {
        Ref<T> Asset;
        AssetHandle Handle;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(AssetComponent<T>, Handle)
    };


    class Asset
    {
    public:
        Asset(AssetHandle handle);
        const AssetHandle m_Handle;
        virtual ~Asset() {}
    };
};