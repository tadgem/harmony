#pragma once
#include "RuntimeProgram.h"
#include "Core/FSM.h"
#include "EditorPanel.h"
#include "EditorMenu.h"
#include "Core/Alias.h"
#include "ImGui/GraphScript/GraphScriptImGui.h"
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
		
		virtual void	SaveProject() override;
		virtual void	LoadProject(const std::string& path) override;

		void 			AddEditorPanels();


		int 			OnEditUpdate();
		void 			OnEditExit();

		virtual int		OnRuntimeUpdate() override;
		void 			OnRuntimeEntry();
		void 			OnRuntimeExit();

		virtual void 	Run() override;
		virtual void	Init() override;
		void			Run(const std::string& projectPath, harmony::Procedure proc = NULL);

		virtual void 	LoadScene(const std::string& path) override;
		virtual void 	OpenScene(uint32_t index) override;
		void 			UpdateEditor();
		void 			GlobalDockspace();
		void			SetRunningStyle();
		virtual void LoadBuiltInAssets() override;

		FSM m_EditorFSM;

        harmony::GraphScriptImGuiEditor m_GraphScriptEditor;

	protected:
		std::vector<Ref<Panel>> p_Panels;



		Ref<ScenePanel> 		p_ScenePanel;
		Ref<EditorView> 		p_EditorView;
		EditorMainMenuBar 		p_MainMenuBar;

	private:
		std::string p_LoadedScenePath;
	};

};
