#include "Assets/AssetManager.h"
#include "Core/Profile.hpp"
#include "Core/Log.hpp"
#include "ImGui/imgui.h"

harmony::AssetManager::AssetManager()
{
}

std::vector<harmony::WeakRef<harmony::Asset>> harmony::AssetManager::LoadAssetFromPath(std::string path, size_t typeHash)
{
    HARMONY_PROFILE_FUNCTION()
    std::vector<WeakRef<Asset>> returnedAssets = std::vector<WeakRef<Asset>>();
    if (p_AssetFactories.find(typeHash) == p_AssetFactories.end())
    {
        harmony::log::error("Asset Manager : Failed to load asset with type hash {}", typeHash);
        return std::vector<WeakRef<Asset>>();
    }

    auto assets = p_AssetFactories[typeHash]->CreateFromFileUnsafe(path);

    for (auto const& [key, val] : assets)
    {
        auto assetCollectionIt = p_Assets.find(key);
        if (assetCollectionIt == p_Assets.end())
        {
            p_Assets.emplace(key, std::vector<Ref<Asset>>());
        }

        for (int i = 0; i < val.size(); i++)
        {
            p_Assets[key].push_back(val[i]);
        }

        auto typePathLookupIt = p_AssetLoadedPathsByType.find(key);
        if (typePathLookupIt == p_AssetLoadedPathsByType.end())
        {
            p_AssetLoadedPathsByType.emplace(key, std::vector<std::string>());
        }

        for (int i = 0; i < val.size(); i++)
        {
            std::string pathToUse;
            if (val[i]->m_AssetPath.size() == 0)
            {
                pathToUse = path;
            }
            else
            {
                pathToUse = val[i]->m_AssetPath;
            }
            p_AssetLoadedPathsByType[key].push_back(pathToUse);

            auto pathLookupIt = p_LoadedPaths.find(pathToUse);
            if (pathLookupIt == p_LoadedPaths.end())
            {
                p_LoadedPaths.emplace(pathToUse, std::vector<WeakRef<Asset>>());
            }
            p_LoadedPaths[pathToUse].push_back(val[i]);

            returnedAssets.push_back(GetWeakRef<Asset>(val[i]));
        }
    }

    return returnedAssets;
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
    HARMONY_PROFILE_FUNCTION()
    if (ImGui::Begin("Asset Manager"))
    {
        for (auto& assetsAtPath : p_LoadedPaths)
        {
            ImGui::Text(assetsAtPath.first.c_str());
            ImGui::Indent();
            for (WeakRef<Asset> asset : assetsAtPath.second)
            {
                auto a = asset.lock();
                ImGui::Text(" - %d : %s", a->m_TypeHash, a->m_AssetPath);
            }
            ImGui::Unindent();
            ImGui::Separator();
        }
    }

    ImGui::End();
}

size_t harmony::AssetManager::GetAssetTypeHash(WeakRef<Asset> asset)
{
    HARMONY_PROFILE_FUNCTION()
    for (auto& [key, val] : p_Assets)
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
