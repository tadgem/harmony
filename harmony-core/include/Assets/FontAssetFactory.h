#pragma once

#include "Assets/AssetFactory.h"

namespace harmony {
    class FontAssetFactory : public AssetFactory {
    public:
        FontAssetFactory();

        virtual void LoadAssetData(const String &path, entt::registry &registry) override;

        virtual void UnloadAssetData(const String &path, entt::registry &registry) override;

    protected:
        String GetFontNameFromPath(const String &path);
    };
}