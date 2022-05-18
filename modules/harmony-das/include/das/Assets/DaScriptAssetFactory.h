#pragma once

#include "Assets/AssetFactory.h"
#include "das/Assets/DaScriptAsset.h"
#include "Core/Utils.h"
namespace harmony {
    class DaScriptAssetFactory : public AssetFactory
    {
    public:
        DaScriptAssetFactory() : AssetFactory(typeid(DaScriptAsset).hash_code()) {}

    protected:
        virtual std::unordered_map<size_t, std::vector<Ref<Asset>>> CreateAssetData(const std::string& path) override
        {
            size_t typeHash = typeid(DaScriptAsset).hash_code();
            std::unordered_map<size_t, std::vector<Ref<Asset>>> assets = std::unordered_map<size_t, std::vector<Ref<Asset>>>();
            std::vector<Ref<Asset>> scripts;

            Ref<DaScriptAsset> asset = CreateRef<DaScriptAsset>();
            std::string scriptContent = Utils::LoadStringFromPath(path);

            asset->m_ScriptContent = scriptContent;
            asset->m_AssetPath = path;
            asset->m_TypeHash = typeid(DaScriptAsset).hash_code();

            scripts.push_back(asset);
            assets.emplace(typeHash, scripts);

            return assets;
        }
    };
};