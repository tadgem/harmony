#pragma once
#include "Rendering/Model.h"
#include "Assets/AssetFactory.h"
namespace harmony
{
    class GLTFModelAssetFactory : public AssetFactory
    {
        GLTFModelAssetFactory();

        virtual std::unordered_map<size_t, std::vector<Ref<Asset>>> CreateAssetData(const std::string& path) override;
    };
};