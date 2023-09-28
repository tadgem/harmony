#pragma once

#include "Assets/Asset.h"
#include "Assets/AssetManager.h"
#include "Assets/TextureAsset.h"
#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/Mesh.h"
#include "Rendering/Pipelines/PipelineStageRenderer.h"
#include "Rendering/Pipelines/PipelineV2.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/View.h"
#include "ThirdParty/json.hpp"
#include "bgfx/bgfx.h"
#include "glm/glm.hpp"
#include <Rendering/Pipelines/PipelineStages/PostProcessStage.h>
#include <string>

namespace harmony {

    class ShaderDataSource;

    class Renderer {
    public:
        Renderer(AssetManager &assetManager);

        template<typename T, typename... Args>
        WeakPtr<T> CreateView(Args &&...args) {
            static_assert(std::is_base_of<View, T>(),
                          "Renderer : Provided type is not a view!");
            RefCntPtr<T> view = CreateRef<T>(std::forward<Args>(args)...);
            p_Views.emplace(view, CreateRef<PipelineV2>(view->m_Name));
            return GetWeakRef<T>(view);
        }

        WeakPtr<ShaderProgram> AddBuiltInShader(const std::string &progName,
                                                const std::string &vsName,
                                                const std::string &fsName,
                                                uint32_t vsIndex, uint32_t fsIndex);

        WeakPtr<ShaderProgram> AddBuiltInShader(const std::string &progName,
                                                const std::string &vsName,
                                                uint32_t csIndex);

        void AddBuiltInShaders();

        WeakPtr<ShaderProgram> BuildShader(const std::string name,
                                           WeakPtr<ShaderStage> vertStage,
                                           WeakPtr<ShaderStage> fragStage);

        WeakPtr<ShaderProgram> BuildShader(const std::string name,
                                           WeakPtr<ShaderStage> computeStage);

        void ReloadShader(WeakPtr<ShaderProgram> shader);

        void ReloadAllShaders();

        bool IsShaderLoaded(const std::string &name);

        WeakPtr<ShaderProgram> GetShader(const std::string &name);

        std::vector<std::string> GetShaderNames();

        void AddPipelineStage(RefCntPtr<PipelineStage> pipelineStage);

        WeakPtr<PipelineStage> GetPipelineStage(const std::string &name);

        template<typename T>
        WeakPtr<T> GetPiplineStage(const std::string &name) {
            static_assert(std::is_base_of<View, T>(),
                          "Renderer : Provided type is not a view!");
            WeakPtr<PipelineStage> stage = GetPipelineStage(name);
            if (stage.expired()) {
                return WeakPtr<T>();
            }
            RefCntPtr<T> derivedStage = std::static_pointer_cast<T>(stage);
            if (derivedStage) {
                return derivedStage;
            }
            return WeakPtr<T>();
        }

        void AddPipelineStageRenderer(RefCntPtr<PipelineStageRenderer> renderer);

        WeakPtr<PipelineStageRenderer>
        GetPipelineStageRenderer(const std::string &name);

        void AddShaderDataSource(RefCntPtr<ShaderDataSource> dataSource);

        WeakPtr<ShaderDataSource> GetShaderDataSource(const std::string &name);

        BGFXMeshHandle SubmitMeshToGPU(WeakPtr<Mesh> mesh);

        BGFXTextureHandle SubmitTextureToGPU(WeakPtr<TextureAsset> textureWeakRef);

        void RemoveView(WeakPtr<View> view);

        WeakPtr<View> GetView(const std::string &name);

        WeakPtr<PipelineV2> GetViewPipeline(WeakPtr<View> view);

        void SetViewActive(WeakPtr<View> viewWeakRef, bool active);

        void RefreshViews();

        void Init();

        void OnPreUpdate(entt::registry &registry);

        void OnPostUpdate(entt::registry &registry);

        WeakPtr<PipelineV2> GetViewPipelineFromName(const std::string &viewName);

        static bgfx::ViewId GetViewID();

        static bgfx::ViewId GetPresentViewID();

        nlohmann::json Serialize();

        void Deserialize(AssetManager &am, nlohmann::json &json);

        std::vector<WeakPtr<View>> m_ActiveViews;

        WeakPtr<ShaderProgram> p_PresentProgram;
        bgfx::UniformHandle p_PresentProgramTextureHandle;
#if HARMONY_DEBUG

        void OnImGui();

        bool ShaderSelector(const std::string &selectorName,
                            harmony::WeakPtr<harmony::ShaderProgram> &prog);

        bool PipelineStageRendererSelector(
                const std::string &selectorName,
                harmony::WeakPtr<harmony::PipelineStageRenderer> renderer);

        bool IsBuiltInShaderName(const std::string &name);
        // Misc & Helpers

    protected:
        AssetHandle p_SelectedVertexAsset;
        AssetHandle p_SelectedFragmentAsset;
        WeakPtr<ShaderProgram> p_SelectedShaderProgram;
        WeakPtr<PipelineStageRenderer> p_SelectedRenderer;
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
        bgfx::VertexLayout BuildVertexLayout(WeakPtr<Mesh> meshWeakRef);

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

        void DeserializePipelineStageRenderers(nlohmann::json &json,
                                               AssetManager &am);

        void DeserializeShaderDataSources(nlohmann::json &json, AssetManager &am);

        void DeserializeViews(nlohmann::json &json, AssetManager &am);

        void DeserializeActiveViews(nlohmann::json &json, AssetManager &am);

        static uint32_t p_PresentViewHandleCounter;
        static uint32_t p_ViewHandleCounter;
        static const uint32_t p_MaxViews = 255;
        AssetManager &p_AssetManager;
        int s_PresentShaderIndex;
        std::map<RefCntPtr<View>, RefCntPtr<PipelineV2>> p_Views;
        std::vector<RefCntPtr<ShaderProgram>> p_Shaders;
        std::vector<RefCntPtr<PipelineStage>> p_PipelineStages;
        std::vector<RefCntPtr<PipelineStageRenderer>> p_PipelineStageRenderers;
        std::vector<RefCntPtr<ShaderDataSource>> p_ShaderDataSources;
        std::vector<WeakPtr<ShaderProgram>> p_BuiltInShaders;

        friend class Program;

        friend class RuntimeProgram;
    };
}; // namespace harmony