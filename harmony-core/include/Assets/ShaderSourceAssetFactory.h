#pragma once

#include "Assets/ShaderSourceAsset.h"
#include "Assets/AssetFactory.h"

namespace harmony {
    class ShaderSourceAssetFactory : public AssetFactory {
    public:
        ShaderSourceAssetFactory();

        virtual void LoadAssetData(const String &path, entt::registry &registry) override;

        virtual void UnloadAssetData(const String &path, entt::registry &registry) override;

        virtual void ClearLoadedData() override;

    protected:
    };
} 