#pragma once

#include "Assets/Asset.h"
#include "Assets/AssetFactory.h"
#include "Core/Alias.h"
#include "Core/Utils.h"

namespace harmony
{
    template<typename T> 
    class SerializedTextAsset : public Asset
    {
    public:

        SerializedTextAsset(T serializedType) : m_Data(serializedType)
        {

        }

        T m_Data;
    };

    class JSONAsset : public SerializedTextAsset<nlohmann::json>{};

    template<typename T> 
    class SerializedTextAssetFactory : public AssetFactory
    {
    public:

        SerializedTextAssetFactory()
        {
            HashString templateTypeHash = GetTypeHash<T>();
            m_Capabilities.AssetTypeHashes.push_back(templateTypeHash);
        }

        static_assert(std::is_base_of<SerializedTextAsset, T>());

        virtual void LoadAssetData(const std::string& path, entt::registry& registry) override
        {
            String inputText = Utils::LoadStringFromPath(path);
            T serializedType = inputText;
            
            RefCntPtr<SerializedTextAsset<T>> serializedTextAsset = CreateRef<SerializedTextAsset<T>>(serializedType);
            AssetHandle handle{ path, 0, GetTypeHash<SerializedTextAsset<T>>() };
            AssetComponent<SerializedTextAsset<T>> assetComponent{ serializedTextAsset, handle };
            
            entt::entity e = registry.create();
            registry.emplace<AssetComponent<SerializedTextAsset<T>>>(e, assetComponent);
            registry.emplace<AssetHandle>(e, handle);
        }

        virtual void UnloadAssetData(const std::string& path, entt::registry& registry) override
        {
            auto view = registry.view<AssetComponent<SerializedTextAsset<T>>, AssetHandle>();
            entt::entity e;
            bool found = false;
            for (auto [entity, component, handle] : view.each()) {
                if (handle.Path == path) {
                    found = true;
                    e = entity;
                }
            }

            if (found) {
                registry.destroy(e);
            }
        }
    };
}