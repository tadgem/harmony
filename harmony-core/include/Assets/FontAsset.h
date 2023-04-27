#pragma once

#include "Assets/Asset.h"

namespace harmony {
    class FontAsset : public Asset {
    public:
        FontAsset(AssetHandle &handle);

        FontAsset();

        std::string m_CleanName;
    };
}