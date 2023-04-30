#include <optick.h>
#include "Script/Lua/LuaScriptAssetFactory.h"
#include "Script/Lua/LuaScriptAsset.h"
#include "Core/Utils.h"
#include "Core/Log.hpp"

harmony::LuaScriptAssetFactory::LuaScriptAssetFactory() {
    OPTICK_EVENT();
    auto luaScriptTypeHash = GetTypeHash<LuaScriptAsset>();

    m_Capabilities.AssetTypeHashes.push_back(luaScriptTypeHash);
}

void harmony::LuaScriptAssetFactory::LoadAssetData(const std::string &path, entt::registry &registry) {
    OPTICK_EVENT();
    std::string source = Utils::LoadStringFromPath(path);

    if (source.empty()) {
        harmony::log::error("Unable to load Lua Script at path {}", path);
        return;
    }
    Ref<LuaScriptAsset> script = CreateRef<LuaScriptAsset>(path, source);

    AssetHandle scriptHandle{path, 0, GetTypeHash<LuaScriptAsset>()};
    AssetComponent<LuaScriptAsset> scriptComponent{script, scriptHandle};

    entt::entity e = registry.create();
    registry.emplace<AssetComponent<LuaScriptAsset>>(e, scriptComponent);
    registry.emplace<AssetHandle>(e, scriptHandle);
}

void harmony::LuaScriptAssetFactory::UnloadAssetData(const std::string &path, entt::registry &registry) {
    OPTICK_EVENT();
    std::vector<entt::entity> entitiesToDestroy;

    auto scriptView = registry.view<AssetComponent<LuaScriptAsset>, AssetHandle>();

    for (auto [e, script, handle]: scriptView.each()) {
        if (handle.Path == path) {
            entitiesToDestroy.push_back(e);
        }
    }
    for (int i = 0; i < entitiesToDestroy.size(); i++) {
        registry.destroy(entitiesToDestroy[i]);
    }
}

void harmony::LuaScriptAssetFactory::ClearLoadedData() {
    OPTICK_EVENT();

}
