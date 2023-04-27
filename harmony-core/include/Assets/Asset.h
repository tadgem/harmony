#pragma once

#include "ThirdParty/json.hpp"
#include "Core/Memory.h"

namespace harmony {
    struct AssetHandle {
        AssetHandle();

        AssetHandle(std::string path, uint32_t index, std::string typeHash);

        std::string Path;
        uint32_t Index;
        std::string TypeHash;

        bool operator==(AssetHandle other);

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(AssetHandle, Path, Index, TypeHash)
    };

    template<typename T>
    struct AssetComponent {
        Ref<T> Asset;
        AssetHandle Handle;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(AssetComponent<T>, Handle)
    };


    class Asset {
    public:
        Asset(AssetHandle handle);

        Asset() {}

        AssetHandle m_Handle;

        virtual ~Asset() {}
    };
};