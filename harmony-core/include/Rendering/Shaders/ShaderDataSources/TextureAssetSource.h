//
// Created by liam_ on 7/15/2023.
//

#pragma once

#include "Rendering/Shaders/ShaderDataSource.h"
#include "Core/Memory.h"
#include "Core/Alias.h"
#include "Rendering/Shaders/Shader.h"

namespace harmony {
    class TextureAsset;

    class TextureAssetSource : public ShaderDataSource {
    public:

        TextureAssetSource(const uint16_t samplerIndex, const String &uniformName, WeakRef<TextureAsset> texture);

        void OnPreUpdate(entt::registry &registry, Ref<ShaderProgram> shader) override;

        void OnPostUpdate(entt::registry &registry, Ref<ShaderProgram> shader) override;

    protected:
        const uint16_t p_SamplerIndex;
        const String p_UniformName;
        ShaderUniform p_Uniform;

        WeakRef<TextureAsset> p_Texture;

        bool p_UniformsCollected;

        void CollectUniforms(Ref<ShaderProgram> prog);

    };
}