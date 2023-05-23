#pragma once

#include <map>
#include "ThirdParty/entt.hpp"
#include "Core/Memory.h"
#include "Assets/Asset.h"

namespace harmony {

    struct AssetFactoryCapabilities {
        std::vector<std::string> AssetTypeHashes;

        bool Contains(std::string typeHash) {
            bool found = false;
            for (int i = 0; i < AssetTypeHashes.size(); i++) {
                if (typeHash == AssetTypeHashes[i]) {
                    found = true;
                }
            }
            return found;
        }
    };

    class AssetFactory {
    public:
        AssetFactory() {}

        virtual void LoadAssetData(const std::string &path, entt::registry &registry) = 0;

        virtual void UnloadAssetData(const std::string &path, entt::registry &registry) = 0;

        virtual void ClearLoadedData();

        AssetFactoryCapabilities m_Capabilities;
    protected:
        std::vector<Ref<Asset>> p_Assets;
    };
}
