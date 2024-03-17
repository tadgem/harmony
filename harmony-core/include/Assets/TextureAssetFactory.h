#pragma once

#include "Assets/AssetFactory.h"
#include "bx/readerwriter.h"
#include "Rendering/Renderer.h"

namespace harmony {
    class TextureAssetFactory : public AssetFactory {
    public:
        TextureAssetFactory(Renderer &renderer);

        virtual void LoadAssetData(const String &path, entt::registry &registry) override;

        virtual void UnloadAssetData(const String &path, entt::registry &registry) override;

    private:
        bx::DefaultAllocator p_Allocator;
        Renderer &p_Renderer;

    };
};