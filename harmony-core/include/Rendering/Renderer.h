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
            static_assert(IsBaseOf<View, T>(),
                          "Renderer : Provided type is not a view!");
            RefCntPtr<T> view = CreateRef<T>(Forward<Args>(args)...);
            p_Views.emplace(view, CreateRef<PipelineV2>(view->m_Name));
            return GetWeakRef<T>(view);
        }

        WeakPtr<ShaderProgram> AddBuiltInShader(const String &progName,
                                                const String &vsName,
                                                const String &fsName,
                                                uint32_t vsIndex, uint32_t fsIndex);

        WeakPtr<ShaderProgram> AddBuiltInShader(const String &progName,
                                                const String &vsName,
                                                uint32_t csIndex);

        void AddBuiltInShaders();

        WeakPtr<ShaderProgram> BuildShader(const String name,
                                           WeakPtr<ShaderStage> vertStage,
                                           WeakPtr<ShaderStage> fragStage);

        WeakPtr<ShaderProgram> BuildShader(const String name,
                                           WeakPtr<ShaderStage> computeStage);

        void ReloadShader(WeakPtr<ShaderProgram> shader);

        void ReloadAllShaders();

        bool IsShaderLoaded(const String &name);

        WeakPtr<ShaderProgram> GetShader(const String &name);

        Vector<String> GetShaderNames();

        void AddPipelineStage(RefCntPtr<PipelineStage> pipelineStage);

        WeakPtr<PipelineStage> GetPipelineStage(const String &name);

        template<typename T>
        WeakPtr<T> GetPiplineStage(const String &name) {
            static_assert(IsBaseOf<View, T>(),
                          "Renderer : Provided type is not a view!");
            WeakPtr<PipelineStage> stage = GetPipelineStage(name);
            if (stage.expired()) {
                return WeakPtr<T>();
            }
            RefCntPtr<T> derivedStage = SmartPointerCast<T, PipelineStage>(stage);
            if (derivedStage) {
                return derivedStage;
            }
            return WeakPtr<T>();
        }

        void AddPipelineStageRenderer(RefCntPtr<PipelineStageRenderer> renderer);

        WeakPtr<PipelineStageRenderer>
        GetPipelineStageRenderer(const String &name);

        void AddShaderDataSource(RefCntPtr<ShaderDataSource> dataSource);

        WeakPtr<ShaderDataSource> GetShaderDataSource(const String &name);

        BGFXMeshHandle SubmitMeshToGPU(WeakPtr<Mesh> mesh);

        BGFXTextureHandle SubmitTextureToGPU(WeakPtr<TextureAsset> textureWeakRef);

        void RemoveView(WeakPtr<View> view);

        WeakPtr<View> GetView(const String &name);

        WeakPtr<PipelineV2> GetViewPipeline(WeakPtr<View> view);

        void SetViewActive(WeakPtr<View> viewWeakRef, bool active);

        void RefreshViews();

        void Init();

        void OnPreUpdate(entt::registry &registry);

        void OnPostUpdate(entt::registry &registry);

        WeakPtr<PipelineV2> GetViewPipelineFromName(const String &viewName);

        static bgfx::ViewId GetViewID();

        static bgfx::ViewId GetPresentViewID();

        Json Serialize();

        void Deserialize(AssetManager &am, Json &json);

        Vector<WeakPtr<View>> m_ActiveViews;

        WeakPtr<ShaderProgram> p_PresentProgram;
        bgfx::UniformHandle p_PresentProgramTextureHandle;
#if HARMONY_DEBUG

        void OnImGui();

        bool ShaderSelector(const String &selectorName,
                            harmony::WeakPtr<harmony::ShaderProgram> &prog);

        bool PipelineStageRendererSelector(
                const String &selectorName,
                harmony::WeakPtr<harmony::PipelineStageRenderer> renderer);

        bool IsBuiltInShaderName(const String &name);
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

        Json SerializeShaders();

        Json SerializePipelineDrawStages();

        Json SerializePostProcessStages();

        Json SerializePipelineStageRenderers();

        Json SerializeShaderDataSources();

        Json SerializeViews();

        Json SerializeActiveViews();

        void DeserializeShaders(Json &json, AssetManager &am);

        void DeserializePipelineDrawStages(Json &json, AssetManager &am);

        void DeserializePostProcessStages(Json &json, AssetManager &am);

        void DeserializePipelineStageRenderers(Json &json,
                                               AssetManager &am);

        void DeserializeShaderDataSources(Json &json, AssetManager &am);

        void DeserializeViews(Json &json, AssetManager &am);

        void DeserializeActiveViews(Json &json, AssetManager &am);

        static uint32_t p_PresentViewHandleCounter;
        static uint32_t p_ViewHandleCounter;
        static const uint32_t p_MaxViews = 255;
        AssetManager &p_AssetManager;
        int s_PresentShaderIndex;
        Map<RefCntPtr<View>, RefCntPtr<PipelineV2>> p_Views;
        Vector<RefCntPtr<ShaderProgram>> p_Shaders;
        Vector<RefCntPtr<PipelineStage>> p_PipelineStages;
        Vector<RefCntPtr<PipelineStageRenderer>> p_PipelineStageRenderers;
        Vector<RefCntPtr<ShaderDataSource>> p_ShaderDataSources;
        Vector<WeakPtr<ShaderProgram>> p_BuiltInShaders;

        friend class Program;

        friend class RuntimeProgram;
    };
}; // namespace harmony