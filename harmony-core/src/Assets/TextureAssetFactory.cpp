#include <optick.h>
#include "Assets/TextureAssetFactory.h"
#include "ThirdParty/stb_image.h"
#include "Assets/TextureAsset.h"
#include "Core/Utils.h"
#include "Core/Log.hpp"
#include "bimg/encode.h"

harmony::TextureAssetFactory::TextureAssetFactory(Renderer &renderer) : p_Renderer(renderer) {
    OPTICK_EVENT();
    HashString textureTypeHash = GET_TYPE_HASH(TextureAsset);

    m_Capabilities.AssetTypeHashes.push_back(textureTypeHash);
}

void harmony::TextureAssetFactory::LoadAssetData(const std::string &path, entt::registry &registry) {
    OPTICK_EVENT();
    std::string cleanPath = Utils::GetCleanPlatformPath(path);
    auto data = Utils::LoadBinaryFromPath(cleanPath);
    uint32_t dataSize = static_cast<uint32_t>(data.size());

    if (data.size() == 0) {
        harmony::log::error("TextureAssetFactory : Failed to load texture data at path : {}", cleanPath);
        return;
    }

    bimg::ImageContainer *rawImageContainer = bimg::imageParse(&p_Allocator, data.data(), dataSize);
    bimg::ImageContainer *rgbaImageContainer = bimg::imageConvert(&p_Allocator, bimg::TextureFormat::RGBA8,
                                                                  *rawImageContainer);
    bimg::ImageContainer *imageContainer = bimg::imageGenerateMips(&p_Allocator, *rgbaImageContainer);
    if (imageContainer == NULL) {
        harmony::log::error("TextureAssetFactory : Failed to create image container for texture data at path : {}",
                            cleanPath);
    }

    Ref<TextureAsset> textureAsset = CreateRef<TextureAsset>(cleanPath, imageContainer);
    AssetHandle handle{path, 0, GET_TYPE_HASH(TextureAsset)};
    AssetComponent<TextureAsset> textureComponent{textureAsset, handle};
    entt::entity e = registry.create();
    registry.emplace<AssetComponent<TextureAsset>>(e, textureComponent);
    registry.emplace<AssetHandle>(e, handle);
    // is this correct?
    p_Renderer.SubmitTextureToGPU(textureAsset);
    data.clear();
}

void harmony::TextureAssetFactory::UnloadAssetData(const std::string &path, entt::registry &registry) {
    OPTICK_EVENT();
    auto view = registry.view<AssetComponent<TextureAsset>, AssetHandle>();
    entt::entity e;
    bool found = false;
    for (auto [entity, tex, handle]: view.each()) {
        if (handle.Path == path) {
            found = true;
            e = entity;
        }
    }

    if (found) {
        registry.destroy(e);
    }
}
