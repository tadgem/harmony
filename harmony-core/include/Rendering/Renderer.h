#pragma once

#include <string>
#include <Rendering/Pipelines/PipelineStages/PostProcessStage.h>
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/Pipelines/PipelineV2.h"
#include "Rendering/Pipelines/PipelineStageRenderer.h"
#include "Rendering/Mesh.h"
#include "Assets/TextureAsset.h"
#include "Rendering/Shaders/Shader.h"
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
            p_Views.emplace(view, CreateRef<PipelineV2>());
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

        void AddPipelineStage(Ref<PipelineStage> pipelineStage);

        WeakRef<PipelineStage> GetPipelineStage(const std::string& name);

        template<typename T>
        WeakRef<T> GetPiplineStage(const std::string& name)
        {
            static_assert(std::is_base_of<View, T>(), "Renderer : Provided type is not a view!");
            WeakRef<PipelineStage> stage = GetPipelineStage(name);
            if(stage.expired())
            {
                return WeakRef<T>();
            }
            Ref<T> derivedStage = std::static_pointer_cast<T>(stage);
            if(derivedStage)
            {
                return derivedStage;
            }
            return WeakRef<T>();
        }

        void AddPipelineStageRenderer(Ref<PipelineStageRenderer> renderer);

        WeakRef<PipelineStageRenderer> GetPipelineStageRenderer(const std::string &name);

        void AddShaderDataSource(Ref<ShaderDataSource> dataSource);

        WeakRef<ShaderDataSource> GetShaderDataSource(const std::string &name);

        BGFXMeshHandle SubmitMeshToGPU(WeakRef<Mesh> mesh);

        BGFXTextureHandle SubmitTextureToGPU(WeakRef<TextureAsset> textureWeakRef);

        void RemoveView(WeakRef<View> view);

        WeakRef<View> GetView(const std::string &name);

        WeakRef<PipelineV2> GetViewPipeline(WeakRef<View> view);

        void SetViewActive(WeakRef<View> viewWeakRef, bool active);

        void RefreshViews();

        void Init();

        void OnPreUpdate(entt::registry &registry);

        void OnPostUpdate(entt::registry &registry);

        WeakRef<PipelineV2> GetViewPipeline(const std::string &viewName);

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

        nlohmann::json SerializePipelineDrawStages();

        nlohmann::json SerializePostProcessStages();

        nlohmann::json SerializePipelineStageRenderers();

        nlohmann::json SerializeShaderDataSources();

        nlohmann::json SerializeViews();

        nlohmann::json SerializeActiveViews();

        void DeserializeShaders(nlohmann::json &json, AssetManager &am);

        void DeserializePipelineDrawStages(nlohmann::json &json, AssetManager &am);

        void DeserializePostProcessStages(nlohmann::json &json, AssetManager &am);

        void DeserializePipelineStageRenderers(nlohmann::json &json, AssetManager &am);

        void DeserializeShaderDataSources(nlohmann::json &json, AssetManager &am);

        void DeserializeViews(nlohmann::json &json, AssetManager &am);

        void DeserializeActiveViews(nlohmann::json &json, AssetManager &am);

        static uint32_t p_PresentViewHandleCounter;
        static uint32_t p_ViewHandleCounter;
        static const uint32_t p_MaxViews = 255;
        AssetManager &p_AssetManager;
        int s_PresentShaderIndex;

        std::map<Ref<View>, Ref<PipelineV2>> p_Views;
        std::vector<Ref<ShaderProgram>> p_Shaders;
        std::vector<Ref<PipelineStage>> p_PipelineStages;
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