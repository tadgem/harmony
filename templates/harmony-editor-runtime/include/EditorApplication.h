#pragma once

#include "RuntimeProgram.h"
#include "Core/FSM.h"
#include "EditorPanel.h"
#include "EditorMenu.h"
#include "Core/Alias.h"
#include "ImGui/Logger.h"
#include "MiniGuiApp.h"
#include "STL/Functional.h"
#include "STL/Stack.h"

namespace harmony {
    class CameraSystem;

    class EditorView;

    class Editor : public RuntimeProgram {
    public:

        enum Mode {
            Edit,
            Debug,
            MiniGuis
        };

        enum Trigger {
            Play,
            Stop,
            MiniGuisFinished,
        };

        Editor();

        virtual void AddAssetTypeNames() override;

        virtual void AddAssetFactories() override;

        virtual void AddProgramComponents() override;

        virtual void AddSystems() override;

        virtual void AddPipelineStageRenderers() override;

        virtual void InitializePipelines() override;

        virtual void InitializeViews() override;

        virtual void SaveProject() override;

        virtual void LoadProject(const String &path) override;

        void AddEditorPanels();

        void AddMiniGuiApp(RefCntPtr<MiniGuiApp> app);

        int OnMiniGuisUpdate();

        void OnMiniGuisExit();

        int OnEditUpdate();

        void OnEditExit();

        virtual int OnRuntimeUpdate() override;

        void OnRuntimeEntry();

        void OnRuntimeExit();

        virtual void Init() override;

        void Run(const String &projectPath, harmony::Procedure proc = NULL);

        virtual void LoadScene(const String &path) override;

        virtual void OpenScene(uint32_t index) override;

        void UpdateEditor();

        void GlobalDockspace();

        void SetRunningStyle();

        virtual void LoadBuiltInAssets() override;

        FSM m_EditorFSM;

        harmony::ImGuiLogger m_Logger;

    protected:
        Vector<RefCntPtr<Panel>> p_Panels;
        RefCntPtr<ScenePanel> p_ScenePanel;
        RefCntPtr<EditorView> p_EditorView;
        EditorMainMenuBar p_MainMenuBar;

        RefCntPtr<PipelineV2> p_EditorPipeline;
        Stack<RefCntPtr<MiniGuiApp>> p_MiniGuiApps;
    private:
        String p_LoadedScenePath;
    };

};
