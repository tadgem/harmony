#pragma once
#include <string>
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/Pipeline.h"
#include "Rendering/PipelineStack.h"
#include "Rendering/PipelineStageRenderer.h"
#include "Rendering/Mesh.h"
#include "Rendering/Texture.h"
#include "Rendering/Shader.h"
#include "Rendering/ShaderDataContainer.h"
#include "Assets/AssetManager.h"
#include "Assets/Asset.h"
#include "glm/glm.hpp"
#include "ThirdParty/json.hpp"
namespace harmony
{
    class Viewport;
    class ShaderDataSource;
    class Renderer
    {   
    public:
        Renderer(AssetManager& assetManager);

        template<typename T, typename ... Args>
        WeakRef<T> CreateView(Args&& ... args)
        {
            static_assert(std::is_base_of<View, T>(), "Provided type is not a view!");
            Ref<T> view = CreateRef<T>(std::forward<Args>(args)...);
            p_Views.emplace(view, PipelineStack());
            return GetWeakRef<T>(view);
        }

        WeakRef<ShaderProgram>          AddBuiltInShader(const std::string& progName, const std::string& vsName, const std::string& fsName, uint32_t vsIndex, uint32_t fsIndex);
        WeakRef<ShaderProgram>          AddBuiltInShader(const std::string& progName, const std::string& vsName, uint32_t csIndex);
        void                            AddBuiltInShaders();
        WeakRef<ShaderProgram>          BuildShader(const std::string name, WeakRef<ShaderStage> vertStage, WeakRef<ShaderStage> fragStage);
        WeakRef<ShaderProgram>          BuildShader(const std::string name, WeakRef<ShaderStage> computeStage);

        void                            ReloadShader(WeakRef<ShaderProgram> shader);
        void                            ReloadAllShaders();
        void                            RefreshShaderDataContainers();

        bool                            IsShaderLoaded(const std::string& name);
        WeakRef<ShaderProgram>          GetShader(const std::string& name);
        std::vector<std::string>        GetShaderNames();

        void                            AddPipeline(Ref<Pipeline> pipeline);
        WeakRef<Pipeline>               GetPipeline(const PipelineHandle& handle);

        void                            AddPipelineStageRenderer(Ref<PipelineStageRenderer> renderer);
        WeakRef<PipelineStageRenderer>  GetPipelineStageRenderer(const std::string& name);

        void                            AddShaderDataSource(Ref<ShaderDataSource> dataSource);
        WeakRef<ShaderDataSource>       GetShaderDataSource(const std::string& name);

        BGFXMeshHandle                  SubmitMeshToGPU(WeakRef<Mesh> mesh);
        BGFXTextureHandle               SubmitTextureToGPU(WeakRef<Texture> textureWeakRef);

        void                            RemoveView(WeakRef<View> view);
        void                            SetViewActive(WeakRef<View> viewWeakRef, bool active);
        void                            AddViewPipeline(WeakRef<View> viewWeakRef, WeakRef<Pipeline> pipeline);
        void                            RefreshViews();

        void                            Init();
        void                            OnPreUpdate(entt::registry& registry);
        void                            OnPostUpdate(entt::registry& registry);
                
        PipelineStack&                  GetViewPipelineStack(const std::string& viewName);
        static bgfx::ViewId             GetViewID();
            
        nlohmann::json                  Serialize();
        void                            Deserialize(AssetManager& am, nlohmann::json& json);

#if HARMONY_DEBUG
        void                OnImGui();
        bool                ShaderSelector(const std::string& selectorName, harmony::WeakRef<harmony::ShaderProgram>& prog);
        Pipeline::Type      GetPipelineTypeFromName(const std::string& type);
        bool                IsBuiltInShaderName(const std::string& name);
    protected:
        AssetHandle p_SelectedVertexAsset;
        AssetHandle p_SelectedFragmentAsset;

        WeakRef<ShaderProgram>  p_SelectedShaderProgram;
        PipelineHandle          p_SelectedPipelineHandle;

        bool p_CreateShaderProgramWindow;
        bool p_CreatePipelineWindow;

        char p_ShaderNameInput[64]{ "" };
        char p_PipelineNameInput[64]{ "" };

        int p_SelectedPipelineType;
#endif
        std::vector<WeakRef<View>> m_ActiveViews;
    protected:
        bgfx::VertexLayout  BuildVertexLayout(WeakRef<Mesh> meshWeakRef);
            
        nlohmann::json      SerializeShaders();
        nlohmann::json      SerializePipelines();
        nlohmann::json      SerializeViews();
        nlohmann::json      SerializeActiveViews();

        void                DeserializeShaders(nlohmann::json& json, AssetManager& am);
        void                DeserializePipelines(nlohmann::json& json, AssetManager& am);
        void                DeserializeViews(nlohmann::json& json, AssetManager& am);
        void                DeserializeActiveViews(nlohmann::json& json, AssetManager& am);

        static uint32_t p_ViewHandleCounter;
        AssetManager&   p_AssetManager;
        int             s_PresentShaderIndex;

        std::map<Ref<View>, PipelineStack>                  p_Views;
        std::vector<Ref<ShaderProgram>>                     p_Shaders;
        std::vector<Ref<Pipeline>>                          p_Pipelines;
        std::vector<Ref<PipelineStageRenderer>>             p_PipelineStageRenderers;
        std::vector<Ref<ShaderDataSource>>                  p_ShaderDataSources;
        std::vector<WeakRef<ShaderProgram>>                 p_BuiltInShaders;

        // Misc & Helpers
        WeakRef<ShaderProgram>                              p_PresentProgram;
        bgfx::UniformHandle                                 p_PresentProgramTextureHandle;

        friend class Program;
        friend class RuntimeProgram;
    };
};