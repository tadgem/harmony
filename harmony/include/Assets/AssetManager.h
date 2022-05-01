#ifndef pragma once
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

        template<typename T>
        std::vector<WeakRef<T>> LoadAssetFromPath(std::string path)
        {
            HARMONY_PROFILE_FUNCTION()
            static_assert(std::is_base_of<Asset, T>());

            size_t typeHash = typeid(T).hash_code();
            auto factoryIt = p_AssetFactories.find(typeHash);
            if (factoryIt == p_AssetFactories.end())
            {
                std::string typeName = HarmonyUtils::GetCleanTypeName(typeid(T).name());
                p_AssetTypeNames.emplace(typeHash, typeName);
                p_AssetFactories.emplace(typeHash, CreateRef<AssetFactory>(typeid(T).hash_code()));
            }
            auto assets = p_AssetFactories[typeHash]->CreateFromFile<T>(path);

            for (auto const& [key, val] : assets)
            {
                auto assetCollectionIt = p_Assets.find(key);
                if (assetCollectionIt == p_Assets.end())
                {
                    p_Assets.emplace(key, std::vector<Asset*>());
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
                        p_LoadedPaths.emplace(pathToUse, std::vector<Asset*>());
                    }
                    p_LoadedPaths[pathToUse].push_back(val[i]);
                }

            }

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
#endif
