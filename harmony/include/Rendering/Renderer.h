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

    class Renderer
    {   
    public:
        bgfx::ProgramHandle CreateShader(const std::string& vert, const std::string& frag);
        bgfx::ProgramHandle CreateShader(const std::string& compute);

        BGFXMeshHandle SubmitMeshToGPU(const Mesh& mesh);

    private:
        bgfx::VertexLayout BuildVertexLayout(const Mesh& mesh);
        // definitely need to improve this, need to support other vertex attribs other than floats.
        std::vector<float> BuildVertexBufferData(const Mesh& mesh);

    };
};