#include <optick.h>
#include "Assets/TextureAssetFactory.h"
#include "ThirdParty/stb_image.h"
#include "Rendering/Texture.h"
#include "Core/Utils.h"
#include "Core/Log.hpp"

harmony::TextureAssetFactory::TextureAssetFactory(Renderer &renderer) : p_Renderer(renderer) {
    OPTICK_EVENT();
    std::string textureTypeHash = GetTypeHash<TextureAsset>();

    m_Capabilities.AssetTypeHashes.push_back(textureTypeHash);
}

void harmony::TextureAssetFactory::LoadAssetData(const std::string &path, entt::registry &registry) {
    OPTICK_EVENT();
    auto data = Utils::LoadBinaryFromPath(path);
    uint32_t dataSize = static_cast<uint32_t>(data.size());

    if (data.size() == 0) {
        harmony::log::error("TextureAssetFactory : Failed to load texture data at path : {}", path);
        return;
    }

    bimg::ImageContainer *imageContainer = bimg::imageParse(&p_Allocator, data.data(), dataSize);

    if (imageContainer == NULL) {
        harmony::log::error("TextureAssetFactory : Failed to create image container for texture data at path : {}",
                            path);
    }

    Ref<TextureAsset> textureAsset = CreateRef<TextureAsset>(path, imageContainer);
    AssetHandle handle{path, 0, GetTypeHash<TextureAsset>()};
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
