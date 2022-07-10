#pragma once
#include <string>
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/Pipeline.h"
#include "Rendering/Mesh.h"
#include "Rendering/Texture.h"
#include "Rendering/Shader.h"
#include "Rendering/ShaderDataContainer.h"
#include "Assets/AssetManager.h"
#include "glm/glm.hpp"

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

        void AddBuiltInShader(const std::string& progName, const std::string& vsName, const std::string& fsName, uint32_t vsIndex, uint32_t fsIndex);
        void AddBuiltInShader(const std::string& progName, const std::string& vsName, uint32_t csIndex);
        void AddBuiltInShaders();

        template<typename T, typename ... Args>
        WeakRef<T> CreatePipeline(Args&& ... args)
        {
            static_assert(std::is_base_of<Pipeline, T>());
            Ref<T> derivedPipeline = CreateRef<T>(std::forward<Args>(args)...);
            Ref<Pipeline> pipeline = std::static_pointer_cast<T, Pipeline>(derivedPipeline);

            if (pipeline)
            {
                PipelineHandle handle = pipeline->m_Handle;
                if (p_Pipelines.find(handle.Index) != p_Pipelines.end())
                {
                    harmony::log::error("Already have a pipeline with handle {} ", handle.Index);
                    Ref<T> derivedExistingPipeline = std::static_pointer_cast<T, Pipeline>(p_Pipelines[handle.Index]);
                    if (derivedExistingPipeline)
                    {
                        return GetWeakRef<T>(derivedExistingPipeline);
                    }
                    return WeakRef<T>();
                }
                p_Pipelines.emplace(handle.Index, pipeline);
                return GetWeakRef<T>(derivedPipeline);
            }
            else
            {
                harmony::log::error("Failed to cast {} to a pipeline.", typeid(T).name());
                return derivedPipeline;
            }
        }

        WeakRef<ShaderProgram> LoadShader(const std::string& name, const std::string& vertName, const std::string& fragName);
        WeakRef<ShaderProgram> LoadShader(const std::string& name, const std::string& computeName);

        WeakRef<ShaderProgram> GetShader(const std::string& name);
        std::vector<std::string> GetShaderNames();

        void AddUniform(const std::string name, WeakRef<float> value);
        void AddUniform(const std::string name, WeakRef<glm::vec2> value);
        void AddUniform(const std::string name, WeakRef<glm::vec3> value);
        void AddUniform(const std::string name, WeakRef<glm::mat3> value);
        void AddUniform(const std::string name, WeakRef<glm::mat4> value);

#if HARMONY_DEBUG
        WeakRef<ShaderProgram> CreateShader(const std::string vertSourcePath, const std::string fragSourcePath);
        WeakRef<ShaderProgram> CreateShader(const std::string computePath);

        std::map<size_t, Ref<Pipeline>> p_PipelinePrototypes;

        void                OnImGui();
        PipelineHandle      p_SelectedPipelineHandle;
#endif

        BGFXMeshHandle      SubmitMeshToGPU(WeakRef<Mesh> mesh);
        BGFXTextureHandle   SubmitTextureToGPU(WeakRef<Texture> textureWeakRef);

        // Create and add a view
        template<typename T, typename ... Args>
        WeakRef<T> CreateView(Args&& ... args)
        {
            static_assert(std::is_base_of<View, T>(), "Provided type is not a view!");
            Ref<T> view = CreateRef<T>(std::forward<Args>(args)...);
            p_Views.emplace(view, std::vector<Ref<Pipeline>>());

            return GetWeakRef<T>(view);
        }

        void                RemoveView(WeakRef<View> view);
        void                SetViewActive(WeakRef<View> viewWeakRef, bool active);
        void                AddViewPipeline(WeakRef<View> viewWeakRef, WeakRef<Pipeline> pipeline);
        void                RefreshViews();

        void                Init();
        void                OnPreUpdate(entt::registry& registry);
        void                OnPostUpdate(entt::registry& registry);
        static bgfx::ViewId GetViewID();
    
        std::vector<WeakRef<View>> m_ActiveViews;
        
    protected:
        
        static uint32_t p_ViewHandleCounter;
        std::map<Ref<View>, std::vector<Ref<Pipeline>>> p_Views;

        bgfx::VertexLayout BuildVertexLayout(WeakRef<Mesh> meshWeakRef);
        AssetManager& p_AssetManager;

        std::map<std::string, WeakRef<float>>     p_FloatValues;
        std::map<std::string, WeakRef<glm::vec2>> p_Vec2Values;
        std::map<std::string, WeakRef<glm::vec3>> p_Vec3Values;
        std::map<std::string, WeakRef<glm::mat3>> p_Mat3Values;
        std::map<std::string, WeakRef<glm::mat4>> p_Mat4Values;

        std::map<Ref<ShaderProgram>, ShaderDataContainer> p_Shaders;
        std::map<uint16_t, Ref<Pipeline>> p_Pipelines;


        bgfx::ViewId p_CurrentView;
    };
};