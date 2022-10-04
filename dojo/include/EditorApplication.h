#pragma once
#include "Core/Program.h"
#include "Core/FSM.h"
#include "EditorPanel.h"
#include "EditorMenu.h"
#include "MainIncludes.h"
namespace harmony
{
	class CameraSystem;
	class Editor : public Program
	{
	public:

		enum Mode
		{
			Edit,
			Debug
		};

		enum Trigger
		{
			Play,
			Stop
		};

		Editor();
		void AddAssetTypeNames();
		void AddAssetFactories();
		void AddProgramComponents();
		void AddSystems();

		void AddEditorPanels();

		void InitializePipelines();
		void InitializeViews();

		int OnEditUpdate();
		void OnEditExit();

		int OnDebugUpdate();
		void OnDebugExit();

		virtual void Run() override;

		virtual void LoadScene(const std::string& path) override;
		virtual void OpenScene(uint32_t index) override;
		void UpdateEditor();
		void GlobalDockspace();

		virtual void LoadBuiltInAssets() override;

		FSM m_EditorFSM;
	protected:		
		std::vector<Ref<Panel>> p_Panels;
		Ref<ScenePanel> p_ScenePanel;
		Ref<EditorView> p_EditorView;

		Ref<Pipeline> p_DebugPipeline;
		Ref<Pipeline> p_TexturedMeshPipeline;
		Ref<Pipeline> p_NormalPipeline;
		Ref<Pipeline> p_VectorGraphicsPipeline;

		Ref<TransformSystem> p_TransformSystem;
		Ref<CameraSystem> p_CameraSystem;
		EditorMainMenuBar p_MainMenuBar;
	private:
		std::string p_LoadedScenePath;
	};

};
