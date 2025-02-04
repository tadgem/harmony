#pragma once

#include "Assets/AssetFactory.h"
#include "Rendering/Renderer.h"
#include "Rendering/Shaders/Shader.h"

namespace harmony {
    class ShaderStageBinaryAssetFactory : public AssetFactory {
    public:
        ShaderStageBinaryAssetFactory(Renderer &renderer);

        virtual void LoadAssetData(const String &path,
                                   entt::registry &registry) override;

        virtual void UnloadAssetData(const String &path,
                                     entt::registry &registry) override;

        virtual void ClearLoadedData() override;

    protected:
        Renderer &p_Renderer;
    };
} // namespace harmony