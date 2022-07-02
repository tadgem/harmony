#pragma once
#include "Core/Program.h"
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
		void InitializePipelines();
		void InitializeViews();

		void RunEditor();
		void UpdateEditor();

	protected:
		Ref<EditorView> p_EditorView;
		Ref<Pipeline> p_DebugPipeline;
		Ref<Pipeline> p_TexturedMeshPipeline;
	};

};
