#pragma once
#include "Core/Profile.hpp"
#include "Core/Memory.h"
#include "Assets/AssetFactory.h"
#include <map>
#include <vector>
#include <memory>
#include <string>
#include "Core/Utils.h"
#include "Core/Memory.h"
#include "Core/Log.hpp"
#include "Core/Profile.hpp"
namespace harmony {
    class AssetManager
    {
    public:
        AssetManager();

        bool AddAssetFactory(Ref<AssetFactory> assetFactory);

        // more of a type hint than a concrete type to load
        // will be used to determine the best asset factory to load the 
        // asset at the given path
        template<typename T>
        std::vector<WeakRef<Asset>>LoadAsset(const std::string& path)
        {
            std::vector<WeakRef<Asset>> assets;
            size_t typeHash = typeid(T).hash_code();

            Ref<AssetFactory> factory = nullptr;
            for (int i = 0; i < p_AssetFactories.size(); i++)
            {                
                if (!p_AssetFactories[i]->m_Capabilities.Contains(typeHash))
                {
                    continue;
                }

                int currentCapabilities = 0;
                
                if (factory != nullptr)
                {
                    currentCapabilities = factory->m_Capabilities.AssetTypeHashes.size();
                }
                
                int newCapabilities = p_AssetFactories[i]->m_Capabilities.AssetTypeHashes.size();

                if (newCapabilities > currentCapabilities)
                {
                    factory = p_AssetFactories[i];
                }
            }

            std::vector<Ref<Asset>> loadedAssets = factory->LoadAssetData(path);
            // Cleanup any shared pointers in factory
            // manager has ownership of all assets.
            factory->ClearLoadedData();

            for (int i = 0; i < loadedAssets.size(); i++)
            {
                Ref<Asset> asset = loadedAssets[i];
                if (p_Assets.find(asset->m_TypeHash) == p_Assets.end())
                {
                    p_Assets.emplace(asset->m_TypeHash, std::vector<Ref<Asset>>());
                }
                p_Assets[asset->m_TypeHash].emplace_back(asset);

                if (asset->m_TypeHash == typeHash)
                {
                    assets.emplace_back(asset);
                }
                // if the assets path is not in the managers list of loaded paths
                if (std::find(p_LoadedPaths.begin(), p_LoadedPaths.end(), asset->m_AssetPath) == p_LoadedPaths.end()) {
                    p_LoadedPaths.emplace_back(asset->m_AssetPath);
                }
            }

            return assets;
        }

        void UnloadAllAssets();
    protected:
        std::vector<Ref<AssetFactory>> p_AssetFactories;
        std::unordered_map<size_t, std::vector<Ref<Asset>>> p_Assets;
        std::unordered_map<size_t, std::string> p_AssetTypeNames;
        std::vector<std::string> p_LoadedPaths;
    };
}
