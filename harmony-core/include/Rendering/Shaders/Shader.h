#pragma once

#include "Assets/Asset.h"
#include "Assets/AssetManager.h"
#include "Assets/TextureAsset.h"
#include "Core/Memory.h"
#include "STL/HashMap.h"
#include "ShaderUniform.h"
#include "bgfx/bgfx.h"
#include "bgfx/embedded_shader.h"
#include "bx/file.h"
#include "bx/readerwriter.h"

namespace harmony {
    class ShaderStage : public Asset {
    public:
        enum Type : unsigned char {
            Vertex,
            Fragment,
            Compute,
            Unknown = 255
        };

        NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
            { Vertex, "vert" },
            { Fragment, "frag" },
            { Compute, "compute" },
            { Unknown, "unknown" }
        })

        ShaderStage(const String &name, const Type &shaderType);

        ShaderStage();

        ~ShaderStage();

        virtual void LoadShaderBinary();

        static String GetShaderStageNameFromEnum(Type type);

        static String GetShaderRendererDirectory();

        static String GetShaderRendererName();

        Type m_Type;
        String m_Name;
        String m_BinaryPath;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderStage, m_Name, m_Type, m_Handle)

        Vector<bgfx::UniformInfo> m_UniformInfos;
        bgfx::ShaderHandle m_ProgramHandle;

    private:
        bx::FileReader _reader;
    };

    class BuiltInShaderStage : public ShaderStage {
    public:
        BuiltInShaderStage(const String &name, const Type &shaderType,
                           bgfx::EmbeddedShader embeddedShader);

        virtual void LoadShaderBinary() override;

    protected:
        bgfx::EmbeddedShader p_EmbeddedShader;
    };

    class ShaderProgram {
    public:
        ShaderProgram(const String &name);

        ShaderProgram();

        bool AddStage(ShaderStage::Type stageType, WeakPtr<ShaderStage> shader);

        bool RemoveStage(ShaderStage::Type stageType);

        void Build();

        void Destroy();

        void GetUniforms();

        void SetUniforms();

        void UpdateUniforms(AssetManager &am);

        void AddUniformOverride(ShaderUniform &uniform);

        void RemoveUniformOverride(ShaderUniform &uniform);

        bgfx::ProgramHandle m_Handle;
        String m_Name;
        Vector<ShaderUniform> m_Uniforms;
        Vector<ShaderUniform> m_ActiveUniformOverrides;
        Map<ShaderUniform, glm::vec4> m_Vec4Values;
        Map<ShaderUniform, glm::mat3> m_Mat3Values;
        Map<ShaderUniform, glm::mat4> m_Mat4Values;
        Map<ShaderUniform, BGFXTextureHandle> m_TextureValues;
        HashMap<ShaderStage::Type, WeakPtr<ShaderStage>> m_Stages;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderProgram, m_Name, m_Stages)

    protected:
        void Clear();

        void UpdateUniform(ShaderUniform &uniform);

        bool IsOverridenUniform(const ShaderUniform &uniform);
    };
}; // namespace harmony