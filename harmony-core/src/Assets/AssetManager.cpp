#include <optick.h>
#include "Assets/AssetManager.h"

#include "Core/Log.hpp"

#if HARMONY_DEBUG

#include "ImGui/imgui.h"
#include "ImGui/imgui_bgfx.h"
#include "Core/Program.h"
#include "Assets/TextureAsset.h"
#include "STL/Algorithm.h"
#endif

harmony::AssetManager::AssetManager() {
    OPTICK_EVENT();
}

void harmony::AssetManager::UnloadAllAssets() {
    OPTICK_EVENT();
}

#if HARMONY_DEBUG

void harmony::AssetManager::OnImGui() {
    OPTICK_EVENT();
}

#endif

bool harmony::AssetManager::IsPathLoaded(const String path) {
    OPTICK_EVENT();
    auto it = Find(p_LoadedPaths.begin(), p_LoadedPaths.end(), path);
    if (it != p_LoadedPaths.end()) {
        return true;
    }

    return false;
}

harmony::Vector<harmony::AssetHandle> harmony::AssetManager::LoadAsset(const String &path, HashString typeHash) {
    OPTICK_EVENT();
    String cleanPath = path;
    auto project = Program::Get()->m_Project;
    if (project) {
        String projectDir = project->m_ProjectDirectory;
        size_t pos = cleanPath.find(projectDir);
        if (pos != String::npos) {
            cleanPath.erase(pos, projectDir.length() + 1);
        }
    }

    auto builtin = cleanPath.find("builtin");
    if (builtin >= 0 && builtin < cleanPath.size()) {
        return GetAssetsAtPath(cleanPath);
    }
    RefCntPtr<AssetFactory> factory = GetAssetFactory(typeHash);
    if (!factory) {
        harmony::log::error("AssetManager : No factory for asset with type hash {}, skipping.", typeHash);
        return Vector<AssetHandle>();
    }
    factory->LoadAssetData(cleanPath, p_AssetRegistry);
    p_LoadedPaths.emplace_back(cleanPath);

    return GetAssetsAtPath(cleanPath);
}

void harmony::AssetManager::UnloadAsset(AssetHandle &handle, HashString typeHash) {
    OPTICK_EVENT();
    auto builtin = handle.Path.find("builtin");
    if (builtin >= 0 && builtin < handle.Path.size()) {
        return;
    }

    RefCntPtr<AssetFactory> factory = GetAssetFactory(typeHash);
    factory->UnloadAssetData(handle.Path, p_AssetRegistry);
}

harmony::Vector<harmony::AssetHandle> harmony::AssetManager::GetAssetsAtPath(const String &path) {
    OPTICK_EVENT();
    auto handles = Vector<AssetHandle>();
    auto view = p_AssetRegistry.view<AssetHandle>();

    for (auto [e, handle]: view.each()) {
        if (handle.Path != path) {
            continue;
        }
        handles.emplace_back(handle);
    }
    return handles;
}

void harmony::AssetManager::Clear() {
    OPTICK_EVENT();
    p_LoadedPaths.clear();
    p_AssetRegistry.clear();
}

harmony::Json harmony::AssetManager::Serialize() {
    OPTICK_EVENT();
    Json json;
    auto view = p_AssetRegistry.view<AssetHandle>();

    json["assets"] = Json::array();

    for (auto [entity, handle]: view.each()) {
        json["assets"].emplace_back(handle);
    }

    return json;
}

void harmony::AssetManager::Deserialize(Json &json) {
    OPTICK_EVENT();
    for (auto j: json["assets"]) {
        AssetHandle handle = j;

        if (IsPathLoaded(handle.Path)) {
            continue;
        }

        LoadAsset(handle.Path, handle.TypeHash);
    }
}

harmony::RefCntPtr<harmony::AssetFactory> harmony::AssetManager::GetAssetFactory(HashString typeHash) {
    OPTICK_EVENT();
    RefCntPtr<AssetFactory> factory = nullptr;
    for (int i = 0; i < p_AssetFactories.size(); i++) {
        if (!p_AssetFactories[i]->m_Capabilities.Contains(typeHash)) {
            continue;
        }

        int currentCapabilities = 0;

        if (factory != nullptr) {
            currentCapabilities = static_cast<int>(factory->m_Capabilities.AssetTypeHashes.size());
        }

        int newCapabilities = static_cast<int>(p_AssetFactories[i]->m_Capabilities.AssetTypeHashes.size());

        if (newCapabilities > currentCapabilities) {
            factory = p_AssetFactories[i];
        }
    }
    return factory;
}

bool harmony::AssetManager::AddAssetFactory(RefCntPtr<AssetFactory> assetFactory) {
    OPTICK_EVENT();
    if (Find(p_AssetFactories.begin(), p_AssetFactories.end(), assetFactory) == p_AssetFactories.end()) {
        p_AssetFactories.emplace_back(assetFactory);
        return true;
    }
    return false;
}
