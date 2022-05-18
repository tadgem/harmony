#pragma once
#include <string>
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Rendering/Mesh.h"

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
        bgfx::ProgramHandle LoadShader(const std::string& vertName, const std::string& fragName);
        bgfx::ProgramHandle LoadShader(const std::string& computeName);
#if HARMONY_DEBUG
        bgfx::ProgramHandle CreateShader(const std::string vertSourcePath, const std::string fragSourcePath);
        bgfx::ProgramHandle CreateShader(const std::string computePath);
#endif
        BGFXMeshHandle SubmitMeshToGPU(const Mesh& mesh);
        void RenderMesh(const BGFXMeshHandle& meshHandle, const RenderState& renderState);

    private:
        std::string GetShaderExtension();
        bgfx::VertexLayout BuildVertexLayout(const Mesh& mesh);
        // definitely need to improve this, need to support other vertex attribs other than floats.
        std::vector<float> BuildVertexBufferData(const Mesh& mesh);

    };
};