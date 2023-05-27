#pragma once

#include "bx/readerwriter.h"
#include "bx/file.h"
#include "bgfx/bgfx.h"
#include "bgfx/embedded_shader.h"
#include "Core/Memory.h"
#include "Assets/Asset.h"
#include "Assets/AssetManager.h"
#include "Assets/TextureAsset.h"
#include "ShaderUniform.h"

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

        ShaderStage(const std::string &name, const Type &shaderType);

        ShaderStage();

        ~ShaderStage();

        virtual void LoadShaderBinary();

        static std::string GetShaderStageNameFromEnum(Type type);

        static std::string GetShaderRendererDirectory();

        static std::string GetShaderRendererName();

        Type m_Type;
        std::string m_Name;
        std::string m_BinaryPath;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderStage, m_Name, m_Type, m_Handle)

        std::vector<bgfx::UniformInfo> m_UniformInfos;
        bgfx::ShaderHandle m_ProgramHandle;

    private:
        bx::FileReader _reader;
    };

    class BuiltInShaderStage : public ShaderStage {
    public:
        BuiltInShaderStage(const std::string &name, const Type &shaderType, bgfx::EmbeddedShader embeddedShader);

        virtual void LoadShaderBinary() override;

    protected:
        bgfx::EmbeddedShader p_EmbeddedShader;
    };

    class ShaderProgram {
    public:
        ShaderProgram(const std::string &name);

        ShaderProgram();

        bool AddStage(ShaderStage::Type stageType, WeakRef<ShaderStage> shader);

        bool RemoveStage(ShaderStage::Type stageType);

        void Build();

        void Destroy();

        void GetUniforms();

        void SetUniforms();

        void UpdateUniforms(AssetManager &am);

        void AddUniformOverride(ShaderUniform &uniform);

        void RemoveUniformOverride(ShaderUniform &uniform);


        bgfx::ProgramHandle m_Handle;

        std::string m_Name;
        std::vector<ShaderUniform> m_Uniforms;
        std::vector<ShaderUniform> m_ActiveUniformOverrides;

        std::map<ShaderUniform, glm::vec4> m_Vec4Values;
        std::map<ShaderUniform, glm::mat3> m_Mat3Values;
        std::map<ShaderUniform, glm::mat4> m_Mat4Values;
        std::map<ShaderUniform, BGFXTextureHandle> m_TextureValues;

        std::unordered_map<ShaderStage::Type, WeakRef<ShaderStage>> m_Stages;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderProgram, m_Name, m_Stages)

    protected:
        void Clear();

        void UpdateUniform(ShaderUniform &uniform);

        bool IsOverridenUniform(const ShaderUniform &uniform);
    };
};