#include "Assets/ShaderStageBinaryAssetFactory.h"

harmony::ShaderStageBinaryAssetFactory::ShaderStageBinaryAssetFactory(Renderer &renderer) : p_Renderer(renderer) {
    m_Capabilities.AssetTypeHashes.push_back(GetTypeHash<ShaderStage>());
}

void harmony::ShaderStageBinaryAssetFactory::LoadAssetData(const std::string &path, entt::registry &registry) {
    auto view = registry.view<AssetComponent<ShaderStage>, AssetHandle>();

    for (auto [e, shader, handle]: view.each()) {
        if (handle.Path == path) {
            // shader already exists
            shader.Asset->LoadShaderBinary();

            return;
        }
    }

    ShaderStage::Type type = ShaderStage::Type::Unknown;

    auto foundVs = path.find("vs");
    auto foundFs = path.find("fs");
    auto foundCs = path.find("cs");
    if (foundVs >= 0 && foundVs < path.size()) {
        type = ShaderStage::Type::Vertex;
    }
    if (foundFs >= 0 && foundFs < path.size()) {
        type = ShaderStage::Type::Fragment;
    }
    if (foundCs >= 0 && foundCs < path.size()) {
        type = ShaderStage::Type::Compute;
    }

    Ref<ShaderStage> shaderStage = CreateRef<ShaderStage>(path, type);
    shaderStage->LoadShaderBinary();

    AssetHandle handle(path, 0, GetTypeHash<ShaderStage>());
    AssetComponent<ShaderStage> stageComponent{shaderStage, handle};

    entt::entity e = registry.create();
    registry.emplace<AssetComponent<ShaderStage>>(e, stageComponent);
    registry.emplace<AssetHandle>(e, handle);
}

void harmony::ShaderStageBinaryAssetFactory::UnloadAssetData(const std::string &path, entt::registry &registry) {
}

void harmony::ShaderStageBinaryAssetFactory::ClearLoadedData() {
}
