#pragma once
#include "Core/Program.h"
#include "Core/FSM.h"
#include "EditorPanel.h"
#include "EditorMenu.h"
#include "MainIncludes.h"
#include "LuaProgramComponent.h"
namespace harmony
{

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
		void UpdateEditor();
		void GlobalDockspace();

		virtual void LoadBuiltInAssets() override;
	protected:

		FSM m_EditorFSM;

		std::vector<Ref<Panel>> p_Panels;
		Ref<ScenePanel> p_ScenePanel;
		Ref<EditorView> p_EditorView;
		Ref<Pipeline> p_DebugPipeline;
		Ref<Pipeline> p_TexturedMeshPipeline;
		Ref<Pipeline> p_NormalPipeline;
		Ref<Pipeline> p_VectorGraphicsPipeline;
		Ref<LuaProgramComponent> p_LuaComponent;
		Ref<TransformSystem> p_TransformSystem;
		EditorMainMenuBar p_MainMenuBar;
	};

};
