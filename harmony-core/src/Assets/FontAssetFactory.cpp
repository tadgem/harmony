#include <optick.h>
#include "Assets/FontAssetFactory.h"
#include "Assets/FontAsset.h"
#include "Core/Memory.h"
#include "Core/Utils.h"
#include "Rendering/VectorGraphics/VectorGraphics.h"
#include "Core/TypeDef.h"

harmony::FontAssetFactory::FontAssetFactory() {
    OPTICK_EVENT();
    HashString fontTypeHash = GetTypeHash<FontAsset>();
    m_Capabilities.AssetTypeHashes.push_back(fontTypeHash);
}

void harmony::FontAssetFactory::LoadAssetData(const String &path, entt::registry &registry) {
    OPTICK_EVENT();
    String cleanPath = Utils::GetCleanPlatformPath(path);
    AssetHandle assetHandle(cleanPath, 0, GetTypeHash<FontAsset>());
    RefCntPtr<FontAsset> font = CreateRef<FontAsset>(assetHandle);
    Vector<uint8_t> fontData = Utils::LoadBinaryFromPath(cleanPath);
    String cleanFontName = GetFontNameFromPath(cleanPath);
    font->m_CleanName = cleanFontName;
    // make available to vg renderer
    VectorGraphics::AddFont(cleanFontName, fontData);

    AssetComponent<FontAsset> fontComponent{font, assetHandle};
    entt::entity e = registry.create();
    registry.emplace<AssetComponent<FontAsset>>(e, fontComponent);
    registry.emplace<AssetHandle>(e, assetHandle);
}

void harmony::FontAssetFactory::UnloadAssetData(const String &path, entt::registry &registry) {
    OPTICK_EVENT();
    auto view = registry.view<AssetComponent<FontAsset>, AssetHandle>();
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

harmony::String harmony::FontAssetFactory::GetFontNameFromPath(const String &path) {
    OPTICK_EVENT();
    String::size_type fsPos = path.find_last_of('/');
    String::size_type bsPos = path.find_last_of('\\');
    String temp;

    if (fsPos != String::npos) {
        temp = path.substr(fsPos + 1);
    } else if (bsPos != String::npos) {
        temp = path.substr(bsPos + 1);
    }

    String::size_type dotPos = temp.find('.');

    if (dotPos != String::npos) {
        return temp.substr(0, dotPos);
    } else {
        return temp;
    }
}
