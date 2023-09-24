#pragma once

#include "MainIncludes.h"
#include "Core/Program.h"
#include "Core/Memory.h"

namespace harmony {
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

        Ref<PipelineV2> p_RuntimePipeline;
        Ref<RuntimeView> p_RuntimeView;

        Ref<EntityDataSystem> p_EntityDataSystem;
        Ref<LuaProgramComponent> p_LuaProgramComponent;
        Ref<LuaSystem> p_LuaSystem;
        Ref<GraphScriptProgramComponent> p_GraphScriptComponent;
        Ref<GraphScriptSystem> p_GraphScriptSystem;
        Ref<JoltPhysicsSystem> p_JoltPhysicsSystem;
        Ref<MonoProgramComponent> p_MonoProgramComponent;

        Ref<MeshSystem> p_MeshSystem;
        Ref<LightSystem> p_LightSystem;
        Ref<TransformSystem> p_TransformSystem;
        Ref<CameraSystem> p_CameraSystem;
        Ref<MonoSystem> p_MonoSystem;

        bgfx::ViewId p_PresentViewId;
    };
}