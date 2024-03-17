#pragma once

#include "ThirdParty/json.hpp"
#include "Core/Memory.h"
#include "Core/TypeDef.h"

namespace harmony {
    struct AssetHandle {
        AssetHandle();

        AssetHandle(String path, uint32_t index, HashString typeHash);

        String Path;
        uint32_t Index;
        HashString TypeHash;

        bool operator==(AssetHandle other);

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(AssetHandle, Path, Index, TypeHash)
    };

    template<typename T>
    struct AssetComponent {
        RefCntPtr<T> Asset;
        AssetHandle Handle;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(AssetComponent<T>, Handle)
    };

    class Asset {
    public:
        Asset(AssetHandle handle);

        Asset() {
        }

        AssetHandle m_Handle;

        virtual ~Asset() {
        }
    };
};