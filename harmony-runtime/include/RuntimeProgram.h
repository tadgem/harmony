#pragma once

#include "MainIncludes.h"
#include "Core/Program.h"
#include "Core/Memory.h"


namespace harmony {
    class JoltMonoContactListenerCallback;
    class RuntimeView;

    class EntityDataSystem;

    class LuaProgramComponent;

    class LuaSystem;

    class GraphScriptProgramComponent;

    class GraphScriptSystem;

    class JoltPhysicsSystem;

    class MonoProgramComponent;

    class MonoSystem;

    class RuntimeProgram : public Program {
    public:
        RuntimeProgram(const std::string &name = "Runtime App");

        virtual void Run(const std::string &projectPath);

        virtual void AddAssetTypeNames();

        virtual void AddAssetFactories();

        virtual void AddProgramComponents();

        virtual void AddSystems();

        virtual void AddPipelineStageRenderers();

        virtual void AddPipelineDrawStages();

        virtual void AddPostProcessStages();

        virtual void AddShaderDataSources();

        virtual void InitializePipelines();

        virtual void InitializeViews();

        virtual void LoadScene(const std::string &path) override;

        virtual void OpenScene(uint32_t index) override;

        virtual int OnRuntimeUpdate();

        virtual void LoadBuiltInAssets();

        virtual void ResizeApplicationWindow(int w, int h) override;

        void PresentRuntimeImage();

        RefCntPtr<PipelineV2> p_RuntimePipeline;
        RefCntPtr<RuntimeView> p_RuntimeView;

        RefCntPtr<EntityDataSystem> p_EntityDataSystem;
        RefCntPtr<LuaProgramComponent> p_LuaProgramComponent;
        RefCntPtr<LuaSystem> p_LuaSystem;
        RefCntPtr<GraphScriptProgramComponent> p_GraphScriptComponent;
        RefCntPtr<GraphScriptSystem> p_GraphScriptSystem;
        RefCntPtr<JoltPhysicsSystem> p_JoltPhysicsSystem;
        RefCntPtr<MonoProgramComponent> p_MonoProgramComponent;

        RefCntPtr<MeshSystem> p_MeshSystem;
        RefCntPtr<LightSystem> p_LightSystem;
        RefCntPtr<TransformSystem> p_TransformSystem;
        RefCntPtr<CameraSystem> p_CameraSystem;
        RefCntPtr<MonoSystem> p_MonoSystem;
        RefCntPtr<JoltMonoContactListenerCallback> p_JoltMonoCallback;

        bgfx::ViewId p_PresentViewId;
    };
}