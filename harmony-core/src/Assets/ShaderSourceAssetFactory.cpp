#include <optick.h>
#include "Assets/ShaderSourceAssetFactory.h"
#include "Core/TypeDef.h"

harmony::ShaderSourceAssetFactory::ShaderSourceAssetFactory() : AssetFactory() {
    OPTICK_EVENT();
    m_Capabilities.AssetTypeHashes.push_back(GetTypeHash<ShaderSourceAsset>());
}

void harmony::ShaderSourceAssetFactory::LoadAssetData(const String &path, entt::registry &registry) {
    OPTICK_EVENT();
    String shaderName = path.substr(path.find_last_of("\\") + 1);
    ShaderStage::Type type = ShaderStage::Type::Unknown;
    auto foundVs = shaderName.find("vs");
    auto foundFs = shaderName.find("fs");
    auto foundCs = shaderName.find("cs");
    if (foundVs >= 0 && foundVs < shaderName.size()) {
        type = ShaderStage::Type::Vertex;
    }
    if (foundFs >= 0 && foundFs < shaderName.size()) {
        type = ShaderStage::Type::Fragment;
    }
    if (foundCs >= 0 && foundCs < shaderName.size()) {
        type = ShaderStage::Type::Compute;
    }
    auto cleanIndex1 = path.find_last_of("\\");
    auto cleanIndex2 = path.find_last_of("/");
    String cleanPath;
    if (cleanIndex1 <= path.size()) {
        auto size = path.size() - cleanIndex1;
        cleanPath = path.substr(cleanIndex1 + 1, size);
    } else if (cleanIndex2 <= path.size()) {
        auto size = path.size() - cleanIndex2;
        cleanPath = path.substr(cleanIndex2 + 1, size);
    } else {
        cleanPath = path;
    }
    RefCntPtr<ShaderSourceAsset> sourceAsset = CreateRef<ShaderSourceAsset>(cleanPath, type);
    AssetHandle handle{cleanPath, 0, GetTypeHash<ShaderSourceAsset>()};
    AssetComponent<ShaderSourceAsset> sourceComponent{sourceAsset, handle};
    entt::entity e = registry.create();
    registry.emplace<AssetComponent<ShaderSourceAsset>>(e, sourceComponent);
    registry.emplace<AssetHandle>(e, handle);

    harmony::log::info("ShaderSourceAssetFactory : Loaded shader source asset from path : {}", path);
}

void harmony::ShaderSourceAssetFactory::UnloadAssetData(const String &path, entt::registry &registry) {
    OPTICK_EVENT();
}

void harmony::ShaderSourceAssetFactory::ClearLoadedData() {
    OPTICK_EVENT();
}
