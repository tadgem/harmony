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
namespace harmony {
    class AssetManager
    {
    public:
        AssetManager();

        // not working properly atm
        /// <summary>
        /// Add a factory to create a type of asset T, using factory type F
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <typeparam name="F"></typeparam>
        /// <typeparam name="...Args"></typeparam>
        /// <param name="...args"></param>
        /// <returns></returns>
        /*template<typename T, typename F, typename ... Args>
        WeakRef<F> AddAssetFactory(Args&& ... args)
        {
            static_assert(std::is_base_of<AssetFactory, F>());
            size_t typeHash = typeid(T).hash_code();
            Ref<F> assetFactory = CreateRef<F>(std::forward(args)...);
            WeakRef<AssetFactory> afWr = AddAssetFactory(typeHash, assetFactory);
            return GetWeakRef<F>(assetFactory);

        }*/

        WeakRef<AssetFactory> AddAssetFactory(size_t typeHash, Ref<AssetFactory> assetFactory)
        {
            if (p_AssetFactories.find(typeHash) != p_AssetFactories.end())
            {
                harmony::log::error("AssetManager already contains an asset factory for type with hash : {1}", typeHash);
                return WeakRef<AssetFactory>();
            }

            p_AssetFactories.emplace(typeHash, assetFactory);

            return GetWeakRef<AssetFactory>(assetFactory);
        }

        std::vector<WeakRef<Asset>> LoadAssetFromPath(std::string path, size_t typeHash);

        template<typename T>
        std::vector<WeakRef<T>> LoadAssetFromPath(std::string path)
        {
            HARMONY_PROFILE_FUNCTION()
            static_assert(std::is_base_of<Asset, T>(), "Provided type is not an asset");

            size_t typeHash = typeid(T).hash_code();
            
            auto assets = LoadAssetFromPath(path, typeHash);

            std::vector<WeakRef<T>> derivedAssets;

            if (assets.size() == 0) return derivedAssets;

            for (auto asset : p_Assets[typeHash])
            {
                if (asset->m_TypeHash != typeHash) continue;

                if (asset->m_AssetPath.size() == 0)
                {
                    asset->m_AssetPath = path;
                }
                Ref<T> derived_asset = std::static_pointer_cast<T>(asset);
                derivedAssets.emplace_back(GetWeakRef<T>(derived_asset));
            }

            return derivedAssets;
        }

        template<typename T>
        std::vector<WeakRef<T>> GetAllAssetsOfType()
        {
            HARMONY_PROFILE_FUNCTION()
            static_assert(std::is_base_of<Asset, T>());

            size_t typeHash = typeid(T).hash_code();

            std::vector<WeakRef<T>> derivedAssets;

            if (p_Assets.find(typeHash) != p_Assets.end())
            {
                for (Ref<Asset> asset : p_Assets[typeHash])
                {
                    Ref<T> derived_asset = std::static_pointer_cast<T>(asset);
                    derivedAssets.emplace_back(GetWeakRef<T>(derived_asset));
                }
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
