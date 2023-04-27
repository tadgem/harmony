#pragma once

#include "Assets/AssetFactory.h"

namespace harmony {
    class LuaScriptAssetFactory : public AssetFactory {
    public:

        LuaScriptAssetFactory();

        virtual void LoadAssetData(const std::string &path, entt::registry &registry) override;

        virtual void UnloadAssetData(const std::string &path, entt::registry &registry) override;

        virtual void ClearLoadedData() override;
    };
}