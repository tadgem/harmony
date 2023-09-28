#pragma once

#include "Assets/AssetFactory.h"

namespace harmony
{
    class MonoProgramComponent;
    class MonoAssemblyAssetFactory : public AssetFactory
    {
    public:
        MonoAssemblyAssetFactory(WeakPtr<MonoProgramComponent> mono);

        virtual void LoadAssetData(const std::string& path, entt::registry& registry) override;
        virtual void UnloadAssetData(const std::string& path, entt::registry& registry) override;

    protected:
        WeakPtr<MonoProgramComponent> p_Mono;
        const HashString p_AssemblyTypeHash;
    };
}