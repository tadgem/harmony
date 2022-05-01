#pragma once
#include "Core/Profile.hpp"
#include "Core/Memory.h"
#include "Assets/AssetFactory.h"
#include <map>
#include <vector>
#include <string>
#include "Core/Utils.h"
namespace harmony {
    class AssetManager
    {
    public:
        AssetManager();

        std::vector<WeakRef<Asset>> LoadAssetFromPath(std::string path, size_t typeHash);

        template<typename T>
        std::vector<WeakRef<T>> LoadAssetFromPath(std::string path)
        {
            HARMONY_PROFILE_FUNCTION()
            static_assert(std::is_base_of<Asset, T>());

            size_t typeHash = typeid(T).hash_code();
            
            auto assets = LoadAssetFromPath(path, typeHash);

            std::vector<WeakRef<T>> derivedAssets;

            for (Ref<Asset> asset : assets[typeHash])
            {
                if (asset->m_TypeHash != typeHash) continue;

                if (asset->m_AssetPath.size() == 0)
                {
                    asset->m_AssetPath = path;
                }
                Ref<T> derived_asset = static_cast<Ref<T>>(asset)
                derivedAssets.emplace_back(GetWeakRef<T>(derived_asset));
            }

            return derivedAssets;
        }

        virtual void UnloadAsset(WeakRef<Asset> asset);
        void UnloadAllAssetsAtPath(std::string path);
        void UnloadAllAssets();
        bool IsAssetLoaded(std::string path);

        std::vector<char> p_ImGuiPathInput;
        void OnImGui();
    protected:
        std::map<size_t, Ref<AssetFactory>> p_AssetFactories;
        std::map<size_t, std::vector<Ref<Asset>>> p_Assets;
        std::map<size_t, std::string> p_AssetTypeNames;
        std::map<size_t, std::vector<std::string>> p_AssetLoadedPathsByType;
        std::map<std::string, std::vector<WeakRef<Asset>>> p_LoadedPaths;

        size_t GetAssetTypeHash(WeakRef<Asset> asset);
    };
}
