#pragma once

#include "Core/Memory.h"
#include "Assets/TextureAsset.h"

namespace harmony {
    struct TileMapCell {
        float UVX;
        float UVY;
    };

    struct TileMapComponent {
        int TileWidth;
        int TileHeight;

        int PaddingWidth;
        int PaddingHeight;

        int TileMapWidth;
        int TileMapHeight;

        std::vector<TileMapCell> Cells;

        WeakRef<TextureAsset> TileMapTexture;

    };
};