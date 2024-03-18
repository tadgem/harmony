#include <optick.h>
#include "Rendering/Shaders/ShaderDataOverride.h"

harmony::ShaderDataOverride::ShaderDataOverride() {
}

void harmony::ShaderDataOverride::AddVec4Override(ShaderUniform uniform, glm::vec4 value) {
    OPTICK_EVENT();
    if (m_Vec4Overrides.find(uniform) != m_Vec4Overrides.end()) {
        harmony::log::warn("ShaderDataOverride : {} : Already contains uniform : {}", m_ShaderName, uniform.Name);
        return;
    }

    m_Vec4Overrides.emplace(uniform, value);
}

void harmony::ShaderDataOverride::AddMat3Override(ShaderUniform uniform, glm::mat3 value) {
    OPTICK_EVENT();
    if (m_Mat3Overrides.find(uniform) != m_Mat3Overrides.end()) {
        harmony::log::warn("ShaderDataOverride : {} : Already contains uniform : {}", m_ShaderName, uniform.Name);
        return;
    }

    m_Mat3Overrides.emplace(uniform, value);
}

void harmony::ShaderDataOverride::AddMat4Override(ShaderUniform uniform, glm::mat4 value) {
    OPTICK_EVENT();
    if (m_Mat4Overrides.find(uniform) != m_Mat4Overrides.end()) {
        harmony::log::warn("ShaderDataOverride : {} : Already contains uniform : {}", m_ShaderName, uniform.Name);
        return;
    }

    m_Mat4Overrides.emplace(uniform, value);
}

void harmony::ShaderDataOverride::AddTextureOverride(ShaderUniform uniform, BGFXTextureHandle value) {
    OPTICK_EVENT();
    if (m_TextureOverrides.find(uniform) != m_TextureOverrides.end()) {
        harmony::log::warn("ShaderDataOverride : {} : Already contains uniform : {}", m_ShaderName, uniform.Name);
        return;
    }

    m_TextureOverrides.emplace(uniform, value);
}

void harmony::ShaderDataOverride::UpdateOverrides(WeakPtr<ShaderProgram> shaderWr, AssetManager &am) {
    OPTICK_EVENT();
    Map<String, glm::vec4> vec4s;
    Map<String, glm::mat3> mat3s;
    Map<String, glm::mat4> mat4s;
    Map<String, BGFXTextureHandle> textures;
    RefCntPtr<ShaderProgram> shader = shaderWr.lock();

    m_ShaderName = shader->m_Name;

    m_AvailableOverrides.clear();
    for (int i = 0; i < shader->m_Uniforms.size(); i++) {
        m_AvailableOverrides.emplace_back(shader->m_Uniforms[i]);
    }

    if (m_Vec4Overrides.size() > 0) {
        for (auto &[handle, value]: m_Vec4Overrides) {
            vec4s.emplace(handle.Name, value);
        }
    }

    if (m_Mat3Overrides.size() > 0) {
        for (auto &[handle, value]: m_Mat3Overrides) {
            mat3s.emplace(handle.Name, value);
        }
    }

    if (m_Mat4Overrides.size() > 0) {
        for (auto &[handle, value]: m_Mat4Overrides) {
            mat4s.emplace(handle.Name, value);
        }
    }

    if (m_TextureOverrides.size() > 0) {
        for (auto &[handle, value]: m_TextureOverrides) {
            textures.emplace(handle.Name, value);
        }
    }

    Clear();

    for (auto &[uniformName, val]: vec4s) {
        for (int i = 0; i < m_AvailableOverrides.size(); i++) {
            if (m_AvailableOverrides[i].Name == uniformName) {
                m_Vec4Overrides.emplace(m_AvailableOverrides[i], val);
                shader->AddUniformOverride(m_AvailableOverrides[i]);
                break;
            }
        }
    }

    for (auto &[uniformName, val]: mat3s) {
        for (int i = 0; i < m_AvailableOverrides.size(); i++) {
            if (m_AvailableOverrides[i].Name == uniformName) {
                m_Mat3Overrides.emplace(m_AvailableOverrides[i], val);
                shader->AddUniformOverride(m_AvailableOverrides[i]);
                break;
            }
        }
    }

    for (auto &[uniformName, val]: mat4s) {
        for (int i = 0; i < m_AvailableOverrides.size(); i++) {
            if (m_AvailableOverrides[i].Name == uniformName) {
                m_Mat4Overrides.emplace(m_AvailableOverrides[i], val);
                shader->AddUniformOverride(m_AvailableOverrides[i]);
                break;
            }
        }
    }

    for (auto &[uniformName, val]: textures) {
        for (int i = 0; i < m_AvailableOverrides.size(); i++) {
            if (m_AvailableOverrides[i].Name == uniformName) {
                WeakPtr<TextureAsset> texWr = am.GetAsset<TextureAsset>(val.Handle);

                if (texWr.expired()) {
                    continue;
                }
                RefCntPtr<TextureAsset> tex = texWr.lock();
                val.BgfxHandle = tex->m_TextureHandle.BgfxHandle;
                val.Handle = tex->m_TextureHandle.Handle;
                val.Info = tex->m_TextureHandle.Info;
                m_TextureOverrides.emplace(m_AvailableOverrides[i], val);
                shader->AddUniformOverride(m_AvailableOverrides[i]);
                break;
            }
        }
    }
}

void harmony::ShaderDataOverride::SetOverrides() {
    OPTICK_EVENT();
    if (m_Vec4Overrides.size() > 0) {
        for (auto &[handle, value]: m_Vec4Overrides) {
            bgfx::setUniform(handle.BgfxHandle, &value[0]);
        }
    }

    if (m_Mat3Overrides.size() > 0) {
        for (auto &[handle, value]: m_Mat3Overrides) {
            bgfx::setUniform(handle.BgfxHandle, &value[0]);
        }
    }

    if (m_Mat4Overrides.size() > 0) {
        for (auto &[handle, value]: m_Mat4Overrides) {
            bgfx::setUniform(handle.BgfxHandle, &value[0]);
        }
    }

    if (m_TextureOverrides.size() > 0) {
        for (auto &[handle, value]: m_TextureOverrides) {
            uint64_t flags = BGFX_SAMPLER_MIP_POINT | BGFX_SAMPLER_UVW_CLAMP;
            bgfx::setTexture(value.SamplerSlot, handle.BgfxHandle, value.BgfxHandle, flags);
        }
    }
}

void harmony::ShaderDataOverride::Clear() {
    OPTICK_EVENT();
    m_Vec4Overrides.clear();
    m_Mat3Overrides.clear();
    m_Mat4Overrides.clear();
    m_TextureOverrides.clear();
}

void harmony::ShaderDataOverride::UpdateUniform(ShaderUniform &uniform) {
    OPTICK_EVENT();
    bool exists = false;
    switch (uniform.Type) {
        case bgfx::UniformType::Vec4:
            m_Vec4Overrides.emplace(uniform, glm::vec4(0.0));;
            break;
        case bgfx::UniformType::Mat3:
            m_Mat3Overrides.emplace(uniform, glm::mat3(1.0));;
            break;
        case bgfx::UniformType::Mat4:
            m_Mat4Overrides.emplace(uniform, glm::mat4(1.0));;
            break;
        case bgfx::UniformType::Sampler:
            m_TextureOverrides.emplace(uniform, BGFXTextureHandle());;
            break;
    }
}
