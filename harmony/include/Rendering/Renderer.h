#pragma once
#include <string>
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Rendering/Mesh.h"
#include "Rendering/Shader.h"

namespace harmony
{
    struct RenderState
    {
        bgfx::ViewId m_View;
        uint64_t m_State = BGFX_STATE_PT_TRISTRIP;
        bgfx::ProgramHandle m_Program;
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
        BGFXMeshHandle SubmitMeshToGPU(WeakRef<Mesh> mesh);
        void RenderMesh(const BGFXMeshHandle& meshHandle, const RenderState& renderState);
        void RenderScene(Ref<Scene> scene);

    private:
        bgfx::VertexLayout BuildVertexLayout(WeakRef<Mesh> meshWeakRef);

        std::vector<Ref<ShaderProgram>> p_Shaders;
        std::vector<Ref<ShaderStage>> p_ShaderStages;
    };
};