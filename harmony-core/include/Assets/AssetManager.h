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
#include "ThirdParty/entt.hpp"
#include  "ImGui/imgui.h"

namespace harmony {

    class AssetManager
    {
    public:
        AssetManager();

        bool AddAssetFactory(Ref<AssetFactory> assetFactory);
        void UnloadAllAssets();


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

        std::vector<AssetHandle>LoadAsset(const std::string& path, std::string typeHash);
        template<typename T>
        std::vector<AssetHandle>LoadAsset(const std::string& path)
        {
            std::string typeHash = GetTypeHash<T>();

            return LoadAsset(path, typeHash);
        }
        void UnloadAsset(AssetHandle& handle, std::string typeHash);
        template<typename T>
        void UnloadAsset(AssetHandle& handle)
        {
            std::string typeHash = GetTypeHash<T>();
            UnloadAsset(handle, typeHash);
        }
        bool IsPathLoaded(const std::string path);


        template<typename T>
        std::vector<AssetHandle> GetLoadedAssets()
        {
            std::vector<AssetHandle> assets;
            auto view = p_AssetRegistry.view<AssetComponent<T>>();
            for (auto [entity, asset] : view.each())
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
            for (auto [entity, asset] : view.each())
            {
                if (asset.Handle == assetHandle)
                {
                    return asset.Asset;
                }
            }
            return WeakRef<T>();

        }

        void Clear();

        nlohmann::json  Serialize();
        void            Deserialize(nlohmann::json& json);

        template <typename T>
        AssetHandle     AddBuiltInAsset(const std::string& path, Ref<T> asset)
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
    
#if HARMONY_DEBUG
        void OnImGui();


        template<typename T>
        bool AssetTypeSelector(const std::string& selectorName, harmony::AssetHandle& handle)
        {
            static_assert(std::is_base_of<Asset, T>());
            bool selectedAsset = false;
            std::vector<harmony::AssetHandle> assets = GetLoadedAssets<T>();
            if (ImGui::BeginCombo(selectorName.c_str(), ""))
            {
                for (int i = 0; i < assets.size(); i++)
                {
                    if (ImGui::Selectable(assets[i].Path.c_str()))
                    {
                        handle = assets[i];
                        selectedAsset = true;
                    }
                }
                ImGui::EndCombo();
            }

            return selectedAsset;
        }
    

#endif
    protected:
        Ref<AssetFactory> GetAssetFactory(std::string typeHash);
        std::vector<Ref<AssetFactory>>                      p_AssetFactories;
        std::unordered_map<size_t, std::string>             p_AssetTypeNames;
        std::vector<std::string>                            p_LoadedPaths;
        entt::registry p_AssetRegistry;
    };
}
