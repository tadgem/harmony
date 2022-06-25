#pragma once
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
#include "entt.hpp"

namespace harmony {

    class AssetManager
    {
    public:
        AssetManager();

        bool AddAssetFactory(Ref<AssetFactory> assetFactory);
        void UnloadAllAssets();
#if HARMONY_DEBUG
        void OnImGui();
#endif
        template<typename T>
        bool AddAssetTypeName()
        {
            size_t typeHash = typeid(T).hash_code();

            if (p_AssetTypeNames.find(typeHash) == p_AssetTypeNames.end())
            {
                std::string typeName = typeid(T).name();
                p_AssetTypeNames.emplace(typeHash, typeName);
                return true;
            }
            return false;
        }

        template<typename T>
        std::vector<AssetHandle>LoadAsset(const std::string& path)
        {
            std::vector<AssetHandle> assets;
            size_t typeHash = typeid(T).hash_code();

            Ref<AssetFactory> factory = GetAssetFactory(typeHash);

            factory->LoadAssetData(path, registry);
            // Cleanup any shared pointers in factory
            // manager has ownership of all assets.
            factory->ClearLoadedData();

            return assets;
        }

        template<typename T>
        std::vector<AssetHandle> GetLoadedAssets()
        {
            std::vector<AssetHandle> assets;
            auto view = p_AssetRegistry.view<AssetComponent<T>>();
            for (auto& [entity, asset] : view.each())
            {
                assets.emplace_back(asset.Handle);
            }
            return assets;
        }

        template<typename T>
        std::vector<AssetHandle> GetAssetsAtPath(const std::string& path)
        {
            std::vector<WeakRef<AssetHandle>> assets;
            auto view = p_AssetRegistry.view<AssetComponent<T>>();
            for (auto& [entity, asset] : view.each())
            {
                if (!asset.Handle.Path == path)
                {
                    continue;
                }
                assets.emplace_back(asset.Handle);
            }
            return assets;
        }

        template<typename T>
        WeakRef<Asset> GetAsset(const AssetHandle& assetHandle)
        {
            auto view = p_AssetRegistry.view<AssetComponent<T>>();
            for (auto& [entity, asset] : view.each())
            {
                if (!asset.Handle == assetHandle)
                {
                    continue;
                }
                return asset;
            }
            return WeakRef<Asset>();

        }

    protected:

        Ref<AssetFactory> GetAssetFactory(size_t typeHash);
        std::vector<Ref<AssetFactory>>                      p_AssetFactories;
        std::unordered_map<size_t, std::vector<Ref<Asset>>> p_Assets;
        std::unordered_map<size_t, std::string>             p_AssetTypeNames;
        std::vector<std::string>                            p_LoadedPaths;

        entt::registry p_AssetRegistry;
    };
}
