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
        String m_Data;

        virtual String ToString() = 0;
        virtual T FromString(const String& input) = 0;
    };

    class JSONAsset : public SerializedTextAsset<nlohmann::json>
    {
    public:

        virtual nlohmann::json ToJSON() = 0;
        virtual void FromJSON(const nlohmann::json& input) = 0;

        virtual String ToString() override
        {
            return ToJSON().dump();
        };

        virtual nlohmann::json FromString(const String& input) override
        {
            nlohmann::json json = input;
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
            static_assert(std::is_base_of<JSONAsset, T>());
            HashString templateTypeHash = GetTypeHash<T>();
            m_Capabilities.AssetTypeHashes.push_back(templateTypeHash);
        }


        virtual void LoadAssetData(const std::string& path, entt::registry& registry) override
        {
            static_assert(std::is_base_of<JSONAsset, T>());
            nlohmann::json inputJson = Utils::LoadJsonFromPath(path);
            RefCntPtr<T> serializedTextAsset = CreateRef<T>();

            serializedTextAsset->FromJSON(inputJson);

            AssetHandle handle{ path, 0, GetTypeHash<T>() };
            AssetComponent<T> assetComponent{ serializedTextAsset, handle };
            
            entt::entity e = registry.create();
            registry.emplace<AssetComponent<T>>(e, assetComponent);
            registry.emplace<AssetHandle>(e, handle);
        }

        virtual void UnloadAssetData(const std::string& path, entt::registry& registry) override
        {
            static_assert(std::is_base_of<JSONAsset, T>());
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