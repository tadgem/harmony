#pragma once
#include <string>
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Rendering/ViewManager.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/Mesh.h"
#include "Rendering/Texture.h"
#include "Rendering/Shader.h"
#include "Assets/AssetManager.h"
namespace harmony
{
    struct RenderState
    {
        bgfx::ViewId m_View = 0;
        uint64_t m_State = BGFX_STATE_DEFAULT;
        bgfx::ProgramHandle m_Program;
    };

    class Renderer
    {   
    public:
        Renderer(AssetManager& assetManager);

        WeakRef<ShaderProgram> LoadShader(const std::string& name, const std::string& vertName, const std::string& fragName);
        WeakRef<ShaderProgram> LoadShader(const std::string& name, const std::string& computeName);

        void AddUniform(const std::string name, WeakRef<float> value);
        void AddUniform(const std::string name, WeakRef<glm::vec2> value);
        void AddUniform(const std::string name, WeakRef<glm::vec3> value);
        void AddUniform(const std::string name, WeakRef<glm::mat3> value);
        void AddUniform(const std::string name, WeakRef<glm::mat4> value);

#if HARMONY_DEBUG
        WeakRef<ShaderProgram> CreateShader(const std::string vertSourcePath, const std::string fragSourcePath);
        WeakRef<ShaderProgram> CreateShader(const std::string computePath);
#endif
        BGFXMeshHandle      SubmitMeshToGPU(WeakRef<Mesh> mesh);
        BGFXTextureHandle   SubmitTextureToGPU(WeakRef<Texture> textureWeakRef);

        void RenderMesh(const BGFXMeshHandle& meshHandle, const RenderState& renderState);
        void RenderScene(WeakRef<Scene> sceneWeakRef);
        // TODO: Rename me
        void GlobalProcessRender(WeakRef<Scene> activeScene);
        ViewManager m_ViewManager;

    private:
        bgfx::VertexLayout BuildVertexLayout(WeakRef<Mesh> meshWeakRef);
        AssetManager& p_AssetManager;

        std::unordered_map<bgfx::UniformHandle, WeakRef<float>>     p_FloatValues;
        std::unordered_map<bgfx::UniformHandle, WeakRef<glm::vec2>> p_Vec2Values;
        std::unordered_map<bgfx::UniformHandle, WeakRef<glm::vec3>> p_Vec3Values;
        std::unordered_map<bgfx::UniformHandle, WeakRef<glm::mat3>> p_Mat3Values;
        std::unordered_map<bgfx::UniformHandle, WeakRef<glm::mat4>> p_Mat4Values;
        
        std::vector<std::string> p_FloatNames;
        std::vector<std::string> p_Vec2Names;
        std::vector<std::string> p_Vec3Names;
        std::vector<std::string> p_Mat3Names;
        std::vector<std::string> p_Mat4Names;

        std::vector<Ref<ShaderProgram>> p_Shaders;
        


        bgfx::ViewId p_CurrentView;
    };
};