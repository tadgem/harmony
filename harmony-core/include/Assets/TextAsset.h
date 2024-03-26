#pragma once

#include "Assets/Asset.h"
#include "Assets/AssetFactory.h"
#include "Core/Alias.h"
#include "Core/Utils.h"
#include "STL/TypeTraits.h"
namespace harmony
{
    template<typename T>
    class SerializedTextAsset : public Asset
    {
    public:
        String m_Data;

        virtual String ToString() = 0;
        virtual T FromString(const String& input) = 0;
    };

    class JSONAsset : public SerializedTextAsset<Json>
    {
    public:

        virtual Json ToJSON() = 0;
        virtual void FromJSON(const Json& input) = 0;

        virtual String ToString() override
        {
            return ToJSON().dump();
        };

        virtual Json FromString(const String& input) override
        {
            Json json = input;
            FromJSON(json);
            return json;
        }
    };


    template<typename T> 
    class JSONTextAssetFactory : public AssetFactory
    {
    public:

        JSONTextAssetFactory()
        {
            static_assert(IsBaseOf<JSONAsset, T>());
            HashString templateTypeHash = GetTypeHash<T>();
            m_Capabilities.AssetTypeHashes.push_back(templateTypeHash);
        }


        virtual void LoadAssetData(const String& path, entt::registry& registry) override
        {
            static_assert(IsBaseOf<JSONAsset, T>());
            Json inputJson = Utils::LoadJsonFromPath(path);
            RefCntPtr<T> serializedTextAsset = CreateRef<T>();

            serializedTextAsset->FromJSON(inputJson);

            AssetHandle handle{ path, 0, GetTypeHash<T>() };
            AssetComponent<T> assetComponent{ serializedTextAsset, handle };
            
            entt::entity e = registry.create();
            registry.emplace<AssetComponent<T>>(e, assetComponent);
            registry.emplace<AssetHandle>(e, handle);
        }

        virtual void UnloadAssetData(const String& path, entt::registry& registry) override
        {
            static_assert(IsBaseOf<JSONAsset, T>());
            auto view = registry.view<AssetComponent<T>, AssetHandle>();
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