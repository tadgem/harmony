#pragma once
#include <string>
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Rendering/Mesh.h"
#include "Rendering/Shader.h"

namespace harmony
{
    struct BGFXMeshHandle
    {
        bgfx::VertexBufferHandle m_VBH;
        bgfx::IndexBufferHandle m_IBH;
        bgfx::VertexLayout m_Layout;
    };

    struct RenderState
    {
        uint64_t m_State = BGFX_STATE_PT_TRISTRIP;
    };

    class Renderer
    {   
    public:
        Renderer();

        WeakRef<ShaderProgram> LoadShader(const std::string& name, const std::string& vertName, const std::string& fragName);
        WeakRef<ShaderProgram> LoadShader(const std::string& name, const std::string& computeName);
#if HARMONY_DEBUG
        WeakRef<ShaderProgram> CreateShader(const std::string vertSourcePath, const std::string fragSourcePath);
        WeakRef<ShaderProgram> CreateShader(const std::string computePath);
#endif
        BGFXMeshHandle SubmitMeshToGPU(Mesh& mesh);
        void RenderMesh(const BGFXMeshHandle& meshHandle, const RenderState& renderState);

    private:
        bgfx::VertexLayout BuildVertexLayout(const Mesh& mesh);
        // definitely need to improve this, need to support other vertex attribs other than floats.
        std::vector<float> BuildVertexBufferData(const Mesh& mesh);

        std::vector<Ref<ShaderProgram>> p_Shaders;
        std::vector<Ref<ShaderStage>> p_ShaderStages;
    };
};