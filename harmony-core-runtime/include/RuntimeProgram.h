#pragma once 
#include "MainIncludes.h"
#include "Core/Program.h"
#include "Core/Memory.h"

namespace harmony
{
    class RuntimeProgram : public Program
    {
    public:
        RuntimeProgram(const std::string& name);

		virtual void AddAssetTypeNames();
		virtual void AddAssetFactories();
		virtual void AddProgramComponents();
		virtual void AddSystems();
		virtual void AddPipelineStageRenderers();
		virtual void InitializePipelines();
		virtual void InitializeViews();

		virtual int	 OnRuntimeUpdate();

		Ref<Pipeline> 			p_ForwardPipeline;
		Ref<Pipeline> 			p_VectorGraphicsPipeline;
		Ref<Pipeline>			p_DebugPipeline;

		Ref<MeshSystem> 		p_MeshSystem;
		Ref<TransformSystem> 	p_TransformSystem;
		Ref<CameraSystem> 		p_CameraSystem;
    };
}