#pragma once

#include "Assets/AssetFactory.h"
#include "bx/readerwriter.h"

namespace harmony
{
    class TextureAssetFactory : public AssetFactory
    {
    public:
        TextureAssetFactory();

        // Inherited via AssetFactory
        virtual std::vector<Ref<Asset>> LoadAssetData(const std::string& path) override;

    private:
        bx::DefaultAllocator p_Allocator;
    };
};