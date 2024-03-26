#pragma once

#include "ThirdParty/entt.hpp"
#include "Core/Memory.h"
#include "Assets/Asset.h"
#include "STL/Vector.h"

namespace harmony {

    struct AssetFactoryCapabilities {
        Vector<HashString> AssetTypeHashes;

        bool Contains(HashString typeHash) {
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
        AssetFactory() {
        }

        virtual void LoadAssetData(const String &path, entt::registry &registry) = 0;

        virtual void UnloadAssetData(const String &path, entt::registry &registry) = 0;

        virtual void ClearLoadedData();

        AssetFactoryCapabilities m_Capabilities;
    protected:
        Vector<RefCntPtr<Asset>> p_Assets;
    };
}
