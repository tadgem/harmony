#pragma once
#include <string>
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/Pipeline.h"
#include "Rendering/PipelineStack.h"
#include "Rendering/Mesh.h"
#include "Rendering/Texture.h"
#include "Rendering/Shader.h"
#include "Rendering/ShaderDataContainer.h"
#include "Assets/AssetManager.h"
#include "Assets/Asset.h"
#include "glm/glm.hpp"
#include "json.hpp"
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
 
        WeakRef<ShaderProgram> CreateShader(const std::string& name, WeakRef<ShaderStage> vertStage, WeakRef<ShaderStage> fragStage);
        WeakRef<ShaderProgram> CreateShader(const std::string& name, WeakRef<ShaderStage> compStage);

        WeakRef<ShaderProgram> BuildShader(const std::string name, WeakRef<ShaderStage> vertStage, WeakRef<ShaderStage> fragStage);

        template<typename T, typename ... Args>
        WeakRef<T> CreatePipeline(Args&& ... args)
        {
            static_assert(std::is_base_of<Pipeline, T>());
            Ref<T> derivedPipeline = CreateRef<T>(std::forward<Args>(args)...);
            Ref<Pipeline> pipeline = std::static_pointer_cast<T, Pipeline>(derivedPipeline);
            

            if (pipeline)
            {
                PipelineHandle handle = pipeline->m_Handle;
                if (p_Pipelines.find(handle) != p_Pipelines.end())
                {
                    harmony::log::error("Already have a pipeline with handle {} ", handle.Index);
                    Ref<T> derivedExistingPipeline = std::static_pointer_cast<T, Pipeline>(p_Pipelines[handle.Index]);
                    if (derivedExistingPipeline)
                    {
                        return GetWeakRef<T>(derivedExistingPipeline);
                    }
                    return WeakRef<T>();
                }
                p_Pipelines.emplace(handle, pipeline);
                return GetWeakRef<T>(derivedPipeline);
            }
            else
            {
                harmony::log::error("Failed to cast {} to a pipeline.", typeid(T).name());
                return derivedPipeline;
            }
        }

        void                AddPipeline(Ref<Pipeline> pipeline, bool makeClone = false);
        WeakRef<Pipeline>   GetPipeline(const PipelineHandle& handle);

        void ReloadShader(WeakRef<ShaderProgram> shader);
        void ReloadAllShaders();

        WeakRef<ShaderProgram>      GetShader(const std::string& name);
        std::vector<std::string>    GetShaderNames();

        void RefreshShaderDataContainers();

        void AddUniform(const std::string name, WeakRef<float> value);
        void AddUniform(const std::string name, WeakRef<glm::vec2> value);
        void AddUniform(const std::string name, WeakRef<glm::vec3> value);
        void AddUniform(const std::string name, WeakRef<glm::mat3> value);
        void AddUniform(const std::string name, WeakRef<glm::mat4> value);


#if HARMONY_DEBUG
        void                OnImGui();
        bool ShaderSelector(const std::string& selectorName, harmony::WeakRef<harmony::ShaderProgram>& prog);

        PipelineHandle      p_SelectedPipelineHandle;

        AssetHandle p_SelectedVertexAsset;
        AssetHandle p_SelectedFragmentAsset;

        WeakRef<ShaderProgram> p_SelectedShaderProgram;

        bool p_CreateShaderProgramWindow;
        bool p_CreatePipelineWindow;

        char p_ShaderNameInput[64]{ "" };
        char p_PipelineNameInput[64]{ "" };
#endif

        BGFXMeshHandle      SubmitMeshToGPU(WeakRef<Mesh> mesh);
        BGFXTextureHandle   SubmitTextureToGPU(WeakRef<Texture> textureWeakRef);

        // Create and add a view
        template<typename T, typename ... Args>
        WeakRef<T> CreateView(Args&& ... args)
        {
            static_assert(std::is_base_of<View, T>(), "Provided type is not a view!");
            Ref<T> view = CreateRef<T>(std::forward<Args>(args)...);
            p_Views.emplace(view, PipelineStack());
            
            entt::registry reg;

            p_Views[view].Init(reg, view);
            return GetWeakRef<T>(view);
        }

        void                RemoveView(WeakRef<View> view);
        void                SetViewActive(WeakRef<View> viewWeakRef, bool active);
        void                AddViewPipeline(WeakRef<View> viewWeakRef, WeakRef<Pipeline> pipeline);
        void                RefreshViews();

        void                Init();
        void                OnPreUpdate(entt::registry& registry);
        void                OnPostUpdate(entt::registry& registry);
                
        PipelineStack&      GetViewPipelineStack(const std::string& viewName);
        static bgfx::ViewId GetViewID();
    
        std::vector<WeakRef<View>> m_ActiveViews;
        
        nlohmann::json      Serialize();
        void                Deserialize(nlohmann::json& json);
    protected:
#if HARMONY_DEBUG
#endif
        static uint32_t p_ViewHandleCounter;

        bgfx::VertexLayout BuildVertexLayout(WeakRef<Mesh> meshWeakRef);
        AssetManager& p_AssetManager;

        std::map<Ref<View>, PipelineStack>                  p_Views;
        std::map<Ref<ShaderProgram>, ShaderDataContainer>   p_Shaders;
        std::map<PipelineHandle, Ref<Pipeline>>             p_Pipelines;
        std::vector<WeakRef<ShaderProgram>>                 p_BuiltInShaders;

        bgfx::ViewId p_CurrentView;
    };
};