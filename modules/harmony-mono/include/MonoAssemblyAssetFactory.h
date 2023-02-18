#pragma once

#include "Assets/AssetFactory.h"

namespace harmony
{
    class MonoAssemblyAssetFactory : public AssetFactory
    {
    public:
        MonoAssemblyAssetFactory();

        virtual void LoadAssetData(const std::string& path, entt::registry& registry) override;
        virtual void UnloadAssetData(const std::string& path, entt::registry& registry) override;

    };
}