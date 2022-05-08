#pragma once

#include "Assets/AssetFactory.h"
#include "Assets/ScriptAsset.h"
#include "Core/Utils.h"
namespace harmony {
    class ScriptAssetFactory : public AssetFactory
    {
    public:
        ScriptAssetFactory() : AssetFactory(typeid(ScriptAsset).hash_code()) {}

    protected:
        virtual std::map<size_t, std::vector<Ref<Asset>>> CreateAssetData(const std::string& path) override
        {
            size_t typeHash = typeid(ScriptAsset).hash_code();
            std::map<size_t, std::vector<Ref<Asset>>> assets = std::map<size_t, std::vector<Ref<Asset>>>();
            std::vector<Ref<Asset>> scripts;

            Ref<ScriptAsset> asset = CreateRef<ScriptAsset>();
            std::string scriptContent = Utils::LoadStringFromPath(path);

            asset->m_ScriptContent = scriptContent;
            asset->m_AssetPath = path;
            asset->m_TypeHash = typeid(ScriptAsset).hash_code();

            scripts.push_back(asset);
            assets.emplace(typeHash, scripts);

            return assets;
        }
    };
};