#pragma once 
#include "MainIncludes.h"
#include "Core/Program.h"
#include "Core/Memory.h"

namespace harmony
{
	class RuntimeView;
	class LuaProgramComponent;
    class RuntimeProgram : public Program
    {
    public:
        RuntimeProgram(const std::string& name = "Runtime App");

		virtual void Run();
		virtual void Run(const std::string& projectPath);

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

		virtual void LoadScene(const std::string& path) override;
		virtual void OpenScene(uint32_t index) override;

		virtual int	 OnRuntimeUpdate();

		virtual void LoadBuiltInAssets();
		virtual void ResizeApplicationWindow(int w, int h) override;
		void PresentRuntimeImage();

		Ref<Pipeline> 				p_ForwardPipeline;
		Ref<Pipeline> 				p_VectorGraphicsPipeline;
		Ref<Pipeline>				p_DebugPipeline;
		Ref<RuntimeView>			p_RuntimeView;

		Ref<LuaProgramComponent>	p_LuaProgramComponent;

		Ref<MeshSystem> 			p_MeshSystem;
		Ref<LightSystem> 			p_LightSystem;
		Ref<TransformSystem> 		p_TransformSystem;
		Ref<CameraSystem> 			p_CameraSystem;

		bgfx::ViewId			p_PresentViewId;
    };
}