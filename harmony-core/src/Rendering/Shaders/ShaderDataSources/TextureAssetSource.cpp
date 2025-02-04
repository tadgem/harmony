//
// Created by liam_ on 7/15/2023.
//
#include "Rendering/Shaders/ShaderDataSources/TextureAssetSource.h"
#include "Assets/TextureAsset.h"

void harmony::TextureAssetSource::OnPreUpdate(entt::registry &registry, harmony::RefCntPtr<harmony::ShaderProgram> shader) {
    if (!shader) {
        return;
    }
    ShaderDataSource::OnPreUpdate(registry, shader);
    if (!p_UniformsCollected) {
        CollectUniforms(shader);
    }

    auto t = p_Texture.lock();

    if (!t) {
        harmony::log::warn("TextureAssetSource : {} : Texture is expired", m_Name);
        return;
    }

    if (p_Uniform.BgfxHandle.idx != UINT16_MAX) {
        bgfx::setTexture(static_cast<uint8_t>(p_SamplerIndex), p_Uniform.BgfxHandle, t->m_TextureHandle.BgfxHandle);
    }
}

void harmony::TextureAssetSource::OnPostUpdate(entt::registry &registry, harmony::RefCntPtr<harmony::ShaderProgram> shader) {
    ShaderDataSource::OnPostUpdate(registry, shader);
}

harmony::TextureAssetSource::TextureAssetSource(const uint16_t samplerIndex, const String &uniformName,
                                                harmony::WeakPtr<harmony::TextureAsset> texture) : ShaderDataSource(
        "TextureAssetSource"), p_Texture(texture), p_UniformName(uniformName), p_SamplerIndex(samplerIndex) {
    p_UniformsCollected = false;
}

void harmony::TextureAssetSource::CollectUniforms(harmony::RefCntPtr<harmony::ShaderProgram> prog) {
    for (ShaderUniform &uniform: prog->m_Uniforms) {
        if (uniform.Name == p_UniformName) {
            p_Uniform = uniform;
            return;
        }
    }

}
