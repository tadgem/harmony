#include "Assets/TextureAssetFactory.h"
#include "stb_image.h"
#include "Rendering/Texture.h"
#include "Core/Utils.h"
#include "Core/Log.hpp"
harmony::TextureAssetFactory::TextureAssetFactory(Renderer& renderer) : p_Renderer(renderer)
{
    size_t textureTypeHash = GetTypeHash<Texture>();

    m_Capabilities.AssetTypeHashes.push_back(textureTypeHash);
}

void harmony::TextureAssetFactory::LoadAssetData(const std::string& path, entt::registry& registry)
{
    auto data = Utils::LoadBinaryFromPath(path);
    uint32_t dataSize = static_cast<uint32_t>(data.size());
        
    if (data.size() == 0)
    {
        harmony::log::error("TextureAssetFactory : Failed to load texture data at path : ", path);
        return;
    }
    
    bimg::ImageContainer* imageContainer = bimg::imageParse(&p_Allocator, data.data(), dataSize);
    
    if (imageContainer == NULL)
    {
        harmony::log::error("TextureAssetFactory : Failed to create image container for texture data at path : ", path);
    }
    
    Ref<Texture> textureAsset = CreateRef<Texture>(path, imageContainer);
    AssetHandle handle{ path, 0, GetTypeHash<Texture>() };
    AssetComponent<Texture> textureComponent{ textureAsset, handle };

    entt::entity e = registry.create();
    registry.emplace<AssetComponent<Texture>>(e, textureComponent);
    registry.emplace<AssetHandle>(e, handle);
    // is this correct?
    p_Renderer.SubmitTextureToGPU(textureAsset);
    data.clear();
}

//std::vector<harmony::Ref<harmony::Asset>> harmony::TextureAssetFactory::LoadAssetData(const std::string& path)
//{
//    std::vector<Ref<Asset>> assets =  std::vector<Ref<Asset>>();
//
//    auto data = Utils::LoadBinaryFromPath(path);
//    uint32_t dataSize = static_cast<uint32_t>(data.size());
//    
//    if (data.size() == 0)
//    {
//        harmony::log::error("TextureAssetFactory : Failed to load texture data at path : ", path);
//        return assets;
//    }
//
//    bimg::ImageContainer* imageContainer = bimg::imageParse(&p_Allocator, data.data(), dataSize);
//
//    if (imageContainer == NULL)
//    {
//        harmony::log::error("TextureAssetFactory : Failed to create image container for texture data at path : ", path);
//    }
//
//    Ref<Texture> textureAsset = CreateRef<Texture>(imageContainer);
//    textureAsset->m_Handle.Path = path;
//    // is this correct?
//    data.clear();
//
//    assets.emplace_back(textureAsset);
//
//    return assets; 
//}
