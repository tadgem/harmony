#include "Assets/AssetManager.h"
#include "Core/Profile.hpp"
#include "Core/Log.hpp"
harmony::AssetManager::AssetManager()
{
}

void harmony::AssetManager::UnloadAsset(WeakRef<Asset> asset)
{
    HARMONY_PROFILE_FUNCTION()
    size_t typeHash = GetAssetTypeHash(asset);
    int index = -1;

    for (int i = 0; i < p_Assets[typeHash].size(); i++)
    {
        if (p_Assets[typeHash][i] == asset.lock())
        {
            index = i;
        }
    }

    std::string loadedPath = "";
    int indexToRemove = -1;
    for (auto& [key, val] : p_LoadedPaths)
    {
        for (int i = 0; i < val.size(); i++)
        {
            if (val[i].lock() == asset.lock())
            {
                loadedPath = key;
                indexToRemove = i;
            }
        }
    }
    if (loadedPath.size() > 0 && indexToRemove > -1)
    {
        p_LoadedPaths[loadedPath].erase(p_LoadedPaths[loadedPath].begin() + indexToRemove);
        if (p_LoadedPaths[loadedPath].size() <= 0)
        {
            p_LoadedPaths.erase(loadedPath);
        }

        int assetLoadedPathByTypeIndex = -1;
        for (int i = 0; i < p_AssetLoadedPathsByType[typeHash].size(); i++)
        {
            if (p_AssetLoadedPathsByType[typeHash][i] == loadedPath)
            {
                assetLoadedPathByTypeIndex = i;
            }
        }

        if (assetLoadedPathByTypeIndex > -1)
        {
            p_AssetLoadedPathsByType[typeHash].erase(p_AssetLoadedPathsByType[typeHash].begin() + assetLoadedPathByTypeIndex);
        }
    }

    if (index >= 0)
    {
        p_Assets[typeHash].erase(p_Assets[typeHash].begin() + index);
    }
}

void harmony::AssetManager::UnloadAllAssetsAtPath(std::string path)
{
    HARMONY_PROFILE_FUNCTION()
    auto it = p_LoadedPaths.find(path);
    if (it == p_LoadedPaths.end())
    {
        harmony::log::warn("No assets loaded at path: {}" ,path );
    }
    while (p_LoadedPaths[path].size() > 0)
    {
        UnloadAsset(p_LoadedPaths[path][0]);
    }
}

void harmony::AssetManager::UnloadAllAssets()
{
    HARMONY_PROFILE_FUNCTION()
    while (p_LoadedPaths.size() > 0)
    {
        std::string keyToRemove = p_LoadedPaths.begin()->first;
        UnloadAllAssetsAtPath(keyToRemove);
        p_LoadedPaths.erase(keyToRemove);
    }
    for (auto const& [key, val] : p_LoadedPaths)
    {
        UnloadAllAssetsAtPath(key);
    }
    p_AssetLoadedPathsByType.clear();
    p_LoadedPaths.clear();
    p_Assets.clear();
}

bool harmony::AssetManager::IsAssetLoaded(std::string path)
{
    HARMONY_PROFILE_FUNCTION()
    bool loaded = true;
    auto it = p_LoadedPaths.find(path);
    if (it == p_LoadedPaths.end())
    {
        loaded = false;
    }
    return loaded;
}

void harmony::AssetManager::OnImGui()
{
}

size_t harmony::AssetManager::GetAssetTypeHash(WeakRef<Asset> asset)
{
    HARMONY_PROFILE_FUNCTION()
    for (auto const& [key, val] : p_Assets)
    {
        for (int i = 0; i < val.size(); i++)
        {
            if (val[i] == asset.lock())
            {
                return key;
            }
        }
    }
    return -1;
}
