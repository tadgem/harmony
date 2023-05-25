#pragma once

#include <string>
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/Pipelines/Pipeline.h"
#include "Rendering/Pipelines/PipelineStack.h"
#include "Rendering/Pipelines/PipelineStageRenderer.h"
#include "Rendering/Mesh.h"
#include "Rendering/Texture.h"
#include "Rendering/Shader.h"
#include "Assets/AssetManager.h"
#include "Assets/Asset.h"
#include "glm/glm.hpp"
#include "ThirdParty/json.hpp"

namespace harmony {
    class Viewport;

    class ShaderDataSource;

    class Renderer {
    public:
        Renderer(AssetManager &assetManager);

        template<typename T, typename ... Args>
        WeakRef<T> CreateView(Args &&... args) {
            static_assert(std::is_base_of<View, T>(), "Renderer : Provided type is not a view!");
            Ref<T> view = CreateRef<T>(std::forward<Args>(args)...);
            p_Views.emplace(view, PipelineStack());
            return GetWeakRef<T>(view);
        }

        WeakRef<ShaderProgram>
        AddBuiltInShader(const std::string &progName, const std::string &vsName, const std::string &fsName,
                         uint32_t vsIndex, uint32_t fsIndex);

        WeakRef<ShaderProgram>
        AddBuiltInShader(const std::string &progName, const std::string &vsName, uint32_t csIndex);

        void AddBuiltInShaders();

        WeakRef<ShaderProgram>
        BuildShader(const std::string name, WeakRef<ShaderStage> vertStage, WeakRef<ShaderStage> fragStage);

        WeakRef<ShaderProgram> BuildShader(const std::string name, WeakRef<ShaderStage> computeStage);

        void ReloadShader(WeakRef<ShaderProgram> shader);

        void ReloadAllShaders();

        bool IsShaderLoaded(const std::string &name);

        WeakRef<ShaderProgram> GetShader(const std::string &name);

        std::vector<std::string> GetShaderNames();

        void AddPipelineDrawStage(Ref<PipelineDrawStage> drawStage);

        WeakRef<PipelineDrawStage> GetPipelineDrawStage(const std::string &name);

        void AddPostProcessStage(Ref<PostProcessStage> postProcessStage);

        WeakRef<PostProcessStage> GetPostProcessStage(const std::string &name);

        void AddPipeline(Ref<Pipeline> pipeline);

        WeakRef<Pipeline> GetPipeline(const PipelineHandle &handle);

        void AddPipelineStageRenderer(Ref<PipelineStageRenderer> renderer);

        WeakRef<PipelineStageRenderer> GetPipelineStageRenderer(const std::string &name);

        void AddShaderDataSource(Ref<ShaderDataSource> dataSource);

        WeakRef<ShaderDataSource> GetShaderDataSource(const std::string &name);

        BGFXMeshHandle SubmitMeshToGPU(WeakRef<Mesh> mesh);

        BGFXTextureHandle SubmitTextureToGPU(WeakRef<TextureAsset> textureWeakRef);

        void RemoveView(WeakRef<View> view);

        WeakRef<View> GetView(const std::string &name);

        void SetViewActive(WeakRef<View> viewWeakRef, bool active);

        void AddViewPipeline(WeakRef<View> viewWeakRef, WeakRef<Pipeline> pipeline);

        void AddViewPostProcessStage(WeakRef<View> viewWeakRef, WeakRef<PostProcessStage> stage);

        void RefreshViews();

        void Init();

        void OnPreUpdate(entt::registry &registry);

        void OnPostUpdate(entt::registry &registry);

        PipelineStack &GetViewPipelineStack(const std::string &viewName);

        static bgfx::ViewId GetViewID();

        static bgfx::ViewId GetPresentViewID();

        nlohmann::json Serialize();

        void Deserialize(AssetManager &am, nlohmann::json &json);

        std::vector<WeakRef<View>> m_ActiveViews;

#if HARMONY_DEBUG

        void OnImGui();

        bool ShaderSelector(const std::string &selectorName, harmony::WeakRef<harmony::ShaderProgram> &prog);

        bool PipelineStageRendererSelector(const std::string &selectorName,
                                           harmony::WeakRef<harmony::PipelineStageRenderer> renderer);

        Pipeline::Type GetPipelineTypeFromName(const std::string &type);

        bool IsBuiltInShaderName(const std::string &name);

    protected:
        AssetHandle p_SelectedVertexAsset;
        AssetHandle p_SelectedFragmentAsset;

        WeakRef<ShaderProgram> p_SelectedShaderProgram;
        WeakRef<PipelineStageRenderer> p_SelectedRenderer;
        PipelineHandle p_SelectedPipelineHandle;

        bool p_CreateShaderProgramWindow;
        bool p_CreatePipelineWindow;
        bool p_CreateDrawStageWindow;
        bool p_CreatePostProcessStageWindow;

        char p_ShaderNameInput[64]{""};
        char p_PipelineNameInput[64]{""};
        char p_PipelineDrawStageNameInput[64]{""};
        char p_PipelinePostProcessStageNameInput[64]{""};

        int p_SelectedPipelineType;
        int p_SelectedPipelineDrawStageType;
#endif
    protected:
        bgfx::VertexLayout BuildVertexLayout(WeakRef<Mesh> meshWeakRef);

        nlohmann::json SerializeShaders();

        nlohmann::json SerializePipelines();

        nlohmann::json SerializePipelineDrawStages();

        nlohmann::json SerializePostProcessStages();

        nlohmann::json SerializePipelineStageRenderers();

        nlohmann::json SerializeShaderDataSources();

        nlohmann::json SerializeViews();

        nlohmann::json SerializeActiveViews();

        void DeserializeShaders(nlohmann::json &json, AssetManager &am);

        void DeserializePipelines(nlohmann::json &json, AssetManager &am);

        void DeserializePipelineDrawStages(nlohmann::json &json, AssetManager &am);

        void DeserializePostProcessStages(nlohmann::json &json, AssetManager &am);

        void DeserializePipelineStageRenderers(nlohmann::json &json, AssetManager &am);

        void DeserializeShaderDataSources(nlohmann::json &json, AssetManager &am);

        void DeserializeViews(nlohmann::json &json, AssetManager &am);

        void DeserializeActiveViews(nlohmann::json &json, AssetManager &am);

        void HandleStackPipelineAccumulation(Ref<View> view, PipelineStack &stack, Ref<ShaderProgram> textureProg,
                                             entt::registry &registry);

        void HandleStackPostProcess(Ref<View> view, PipelineStack &stack, Ref<ShaderProgram> textureProg,
                                    entt::registry &registry);

        static uint32_t p_PresentViewHandleCounter;
        static uint32_t p_ViewHandleCounter;
        static const uint32_t p_MaxViews = 255;
        AssetManager &p_AssetManager;
        int s_PresentShaderIndex;

        std::map<Ref<View>, PipelineStack> p_Views;
        std::vector<Ref<ShaderProgram>> p_Shaders;
        std::vector<Ref<Pipeline>> p_Pipelines;
        std::vector<Ref<PipelineDrawStage>> p_PipelineDrawStages;
        std::vector<Ref<PostProcessStage>> p_PostProcessStages;
        std::vector<Ref<PipelineStageRenderer>> p_PipelineStageRenderers;
        std::vector<Ref<ShaderDataSource>> p_ShaderDataSources;
        std::vector<WeakRef<ShaderProgram>> p_BuiltInShaders;

        // Misc & Helpers
        WeakRef<ShaderProgram> p_PresentProgram;
        bgfx::UniformHandle p_PresentProgramTextureHandle;

        friend class Program;

        friend class RuntimeProgram;
    };
};