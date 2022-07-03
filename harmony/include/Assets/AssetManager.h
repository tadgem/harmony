#pragma once
#include "Core/Memory.h"
#include "Assets/Asset.h"
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
            size_t typeHash = typeid(T).hash_code();

            Ref<AssetFactory> factory = GetAssetFactory(typeHash);

            factory->LoadAssetData(path, p_AssetRegistry);
            // Cleanup any shared pointers in factory
            // manager has ownership of all assets.
            factory->ClearLoadedData();

            return GetAssetsAtPath(path);
        }

        bool IsPathLoaded(const std::string path);

        std::vector<AssetHandle>LoadAsset(const std::string& path, size_t typeHash);

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

        std::vector<AssetHandle> GetAssetsAtPath(const std::string& path);
        
        template<typename T>
        WeakRef<T> GetAsset(const AssetHandle& assetHandle)
        {
            auto view = p_AssetRegistry.view<AssetComponent<T>>();
            for (auto& [entity, asset] : view.each())
            {
                if (asset.Handle == assetHandle)
                {
                    return asset.Asset;
                }
            }
            return WeakRef<T>();

        }

        void Clear();

        nlohmann::json Serialize();
        void Deserialize(nlohmann::json& json);

        template <typename T>
        AssetHandle AddBuiltInAsset(const std::string& path, Ref<T> asset)
        {
            static_assert(std::is_base_of<Asset, T>());
            AssetHandle handle;
            handle.Path = path;
            handle.Index = 0;
            handle.TypeHash = GetTypeHash<T>();

            AssetComponent<T> ac;
            ac.Asset = asset;
            ac.Handle = handle;

            entt::entity e = p_AssetRegistry.create();
            p_AssetRegistry.emplace<AssetComponent<T>>(e, ac);
            p_AssetRegistry.emplace<AssetHandle>(e, handle);

            return handle;
        }
    protected:
        Ref<AssetFactory> GetAssetFactory(size_t typeHash);
        std::vector<Ref<AssetFactory>>                      p_AssetFactories;
        std::unordered_map<size_t, std::string>             p_AssetTypeNames;
        std::vector<std::string>                            p_LoadedPaths;

        entt::registry p_AssetRegistry;
    };
}
