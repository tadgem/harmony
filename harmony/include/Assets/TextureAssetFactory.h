#pragma once

#include "Assets/AssetFactory.h"
#include "bx/readerwriter.h"

namespace harmony
{
    class TextureAssetFactory : public AssetFactory
    {
    public:
        TextureAssetFactory();

        // virtual std::vector<Ref<Asset>> LoadAssetData(const std::string& path) override;
        virtual void LoadAssetData(const std::string& path, entt::registry& registry) override;

    private:
        bx::DefaultAllocator p_Allocator;
    };
};