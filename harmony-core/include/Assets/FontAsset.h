#pragma once

#include "Assets/Asset.h"

namespace harmony {
    class FontAsset : public Asset {
    public:
        FontAsset(AssetHandle &handle);

        FontAsset();

        String m_CleanName;
    };
}