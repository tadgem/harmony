#include "Assets/TextureAssetFactory.h"
#include "ThirdParty/stb_image.h"
#include "Rendering/Texture.h"
#include "Core/Utils.h"
#include "Core/Log.hpp"

harmony::TextureAssetFactory::TextureAssetFactory(Renderer &renderer) : p_Renderer(renderer) {
    std::string textureTypeHash = GetTypeHash<Texture>();

    m_Capabilities.AssetTypeHashes.push_back(textureTypeHash);
}

void harmony::TextureAssetFactory::LoadAssetData(const std::string &path, entt::registry &registry) {
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

    Ref<Texture> textureAsset = CreateRef<Texture>(path, imageContainer);
    AssetHandle handle{path, 0, GetTypeHash<Texture>()};
    AssetComponent<Texture> textureComponent{textureAsset, handle};

    entt::entity e = registry.create();
    registry.emplace<AssetComponent<Texture>>(e, textureComponent);
    registry.emplace<AssetHandle>(e, handle);
    // is this correct?
    p_Renderer.SubmitTextureToGPU(textureAsset);
    data.clear();
}

void harmony::TextureAssetFactory::UnloadAssetData(const std::string &path, entt::registry &registry) {
    auto view = registry.view<AssetComponent<Texture>, AssetHandle>();
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
