#pragma once
#include "RuntimeProgram.h"
#include "Core/FSM.h"
#include "EditorPanel.h"
#include "EditorMenu.h"

namespace harmony
{
	class CameraSystem;
	class EditorView;
	class Editor : public RuntimeProgram
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

		virtual void	AddAssetTypeNames() override;
		virtual void	AddAssetFactories() override;
		virtual void	AddProgramComponents() override;
		virtual void	AddSystems() override;
		virtual void	AddPipelineStageRenderers() override;
		virtual void	InitializePipelines() override;
		virtual void	InitializeViews() override;
		
		void 			AddEditorPanels();


		int 			OnEditUpdate();
		void 			OnEditExit();

		int 			OnDebugUpdate();
		void 			OnDebugExit();

		virtual void 	Run() override;

		virtual void 	LoadScene(const std::string& path) override;
		virtual void 	OpenScene(uint32_t index) override;
		void 			UpdateEditor();
		void 			GlobalDockspace();

		virtual void LoadBuiltInAssets() override;

		FSM m_EditorFSM;

	protected:		
		std::vector<Ref<Panel>> p_Panels;

		Ref<ScenePanel> 		p_ScenePanel;
		Ref<EditorView> 		p_EditorView;
		EditorMainMenuBar 		p_MainMenuBar;

	private:
		std::string p_LoadedScenePath;
	};

};