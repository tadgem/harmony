#pragma once

#include "Rendering/Shaders/Shader.h"
#include "Rendering/Renderer.h"
#include "Assets/AssetFactory.h"

namespace harmony {
    class ShaderStageBinaryAssetFactory : public AssetFactory {
    public:
        ShaderStageBinaryAssetFactory(Renderer &renderer);

        virtual void LoadAssetData(const std::string &path, entt::registry &registry) override;

        virtual void UnloadAssetData(const std::string &path, entt::registry &registry) override;

        virtual void ClearLoadedData() override;

    protected:
        Renderer &p_Renderer;
    };
} 