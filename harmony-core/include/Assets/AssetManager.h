#pragma once

#include "STL/TypeTraits.h"
#include "Core/Memory.h"
#include "Assets/Asset.h"
#include "Assets/AssetFactory.h"
#include "STL/HashMap.h"
#include "STL/Vector.h"
#include "STL/Memory.h"
#include "STL/String.h"
#include "Core/Utils.h"
#include "Core/Memory.h"
#include "Core/Log.hpp"

#include "ThirdParty/entt.hpp"
#include  "ImGui/imgui.h"

namespace harmony {

    class AssetManager {
    public:
        AssetManager();

        bool AddAssetFactory(RefCntPtr<AssetFactory> assetFactory);

        void UnloadAllAssets();

        template<typename T>
        bool AddAssetTypeName() {
            HashString typeHash = GetTypeHash<T>();

            if (p_AssetTypeNames.find(typeHash) == p_AssetTypeNames.end()) {
                String typeName = typeid(T).name();
                p_AssetTypeNames.emplace(typeHash.m_Value, typeName);
                return true;
            }
            return false;
        }

        Vector<AssetHandle> LoadAsset(const String &path, HashString typeHash);

        template<typename T>
        Vector<AssetHandle> LoadAsset(const String &path) {
            HashString typeHash = GetTypeHash<T>();

            return LoadAsset(path, typeHash);
        }

        void UnloadAsset(AssetHandle &handle, HashString typeHash);

        template<typename T>
        void UnloadAsset(AssetHandle &handle) {
            HashString typeHash = GetTypeHash<T>();
            UnloadAsset(handle, typeHash);
        }

        bool IsPathLoaded(const String path);

        template <typename T>
        void ReloadAllAssetsOfType()
        {
            Vector<AssetHandle> assets;
            {
                auto view = p_AssetRegistry.view<AssetComponent<T>>();
                for (auto [entity, asset]: view.each()) {
                    assets.emplace_back(asset.Handle);
                }
            }
            for(AssetHandle handle : assets)
            {
                UnloadAsset<T>(handle);
            }

            for(AssetHandle handle : assets)
            {
                LoadAsset<T>(handle.Path);
            }

        }

        template<typename T>
        Vector<AssetHandle> GetLoadedAssets() {
            Vector<AssetHandle> assets;
            auto view = p_AssetRegistry.view<AssetComponent<T>>();
            for (auto [entity, asset]: view.each()) {
                assets.emplace_back(asset.Handle);
            }
            return assets;
        }

        Vector<AssetHandle> GetAssetsAtPath(const String &path);

        template<typename T>
        WeakPtr<T> GetAsset(const AssetHandle &assetHandle) {
            String cleanAssetPath = Utils::GetCleanPlatformPath(assetHandle.Path);
            AssetHandle temp{cleanAssetPath, assetHandle.Index, assetHandle.TypeHash};
            if (!assetHandle.Path.find("builtin")) {
                temp.Path = assetHandle.Path;
            }
            auto view = p_AssetRegistry.view<AssetComponent<T>>();
            for (auto [entity, asset]: view.each()) {
                if (!temp.Path.find(asset.Handle.Path)) {
                    return asset.Asset;
                } else if (!assetHandle.Path.find(asset.Handle.Path)) {
                    return asset.Asset;
                }
            }
            return WeakPtr<T>();

        }

        template<typename T>
        WeakPtr<T> GetAsset(const String &assetHandle) {
            AssetHandle h = {assetHandle, 0, GetTypeHash<T>()};
            return GetAsset<T>(h);
        }

        void Clear();

        Json Serialize();

        void Deserialize(Json &json);

        template<typename T>
        AssetHandle AddBuiltInAsset(const String &path, RefCntPtr<T> asset) {
            static_assert(IsBaseOf<Asset, T>());
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
        bool AssetTypeSelector(const String &selectorName, harmony::AssetHandle &handle,
                               const String &preview = "") {
            static_assert(IsBaseOf<Asset, T>());
            bool selectedAsset = false;
            Vector<harmony::AssetHandle> assets = GetLoadedAssets<T>();
            if (ImGui::BeginCombo(selectorName.c_str(), preview.c_str())) {
                for (int i = 0; i < assets.size(); i++) {
                    if (ImGui::Selectable(assets[i].Path.c_str())) {
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
        RefCntPtr<AssetFactory> GetAssetFactory(HashString typeHash);

        Vector<RefCntPtr<AssetFactory>> p_AssetFactories;
        HashMap<uint64_t, String> p_AssetTypeNames;
        Vector<String> p_LoadedPaths;
        entt::registry p_AssetRegistry;
    };
}
