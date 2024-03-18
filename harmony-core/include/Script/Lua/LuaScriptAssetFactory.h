#pragma once

#include "Assets/AssetFactory.h"

namespace harmony {
    class LuaScriptAssetFactory : public AssetFactory {
    public:
        LuaScriptAssetFactory();

        virtual void LoadAssetData(const String &path,
                                   entt::registry &registry) override;

        virtual void UnloadAssetData(const String &path,
                                     entt::registry &registry) override;

        virtual void ClearLoadedData() override;
    };
} // namespace harmony