#pragma once
#include "Core/Program.h"
#include "EditorPanel.h"
#include "EditorMenu.h"
#include "MainIncludes.h"

namespace harmony
{
	class Editor : public Program
	{
	public:
		Editor();
		void AddAssetTypeNames();
		void AddAssetFactories();
		void AddProgramComponents();
		void AddSystems();

		void AddEditorPanels();

		void InitializePipelines();
		void InitializeViews();

		void RunEditor();
		void UpdateEditor();
		void GlobalDockspace();

		virtual void LoadBuiltInAssets() override;
	protected:
		std::vector<Ref<Panel>> p_Panels;
		Ref<ScenePanel> p_ScenePanel;
		Ref<EditorView> p_EditorView;
		Ref<Pipeline> p_DebugPipeline;
		Ref<Pipeline> p_TexturedMeshPipeline;
		Ref<Pipeline> p_NormalPipeline;
		Ref<Pipeline> p_VectorGraphicsPipeline;
		EditorMainMenuBar p_MainMenuBar;
	};

};
