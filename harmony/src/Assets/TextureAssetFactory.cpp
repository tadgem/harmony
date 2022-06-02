#include "Assets/TextureAssetFactory.h"
#include "stb_image.h"
#include "Rendering/Texture.h"
#include "Core/Utils.h"
#include "Core/Log.hpp"
harmony::TextureAssetFactory::TextureAssetFactory()
{
    size_t textureTypeHash = GetTypeHash<Texture>();

    m_Capabilities.AssetTypeHashes.push_back(textureTypeHash);
}

std::vector<harmony::Ref<harmony::Asset>> harmony::TextureAssetFactory::LoadAssetData(const std::string& path)
{
    std::vector<Ref<Asset>> assets =  std::vector<Ref<Asset>>();

    auto data = Utils::LoadBinaryFromPath(path);
    uint32_t dataSize = static_cast<uint32_t>(data.size());
    
    if (data.size() == 0)
    {
        harmony::log::error("TextureAssetFactory : Failed to load texture data at path : ", path);
        return assets;
    }

    bimg::ImageContainer* imageContainer = bimg::imageParse(&p_Allocator, data.data(), dataSize);

    if (imageContainer == NULL)
    {
        harmony::log::error("TextureAssetFactory : Failed to create image container for texture data at path : ", path);
    }

    Ref<Texture> textureAsset = CreateRef<Texture>(imageContainer);
    textureAsset->m_AssetPath = path;
    // is this correct?
    data.clear();

    assets.emplace_back(textureAsset);

    return assets; 
}
