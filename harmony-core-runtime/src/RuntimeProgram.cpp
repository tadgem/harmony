#include "RuntimeProgram.h"
#include "AssimpModelAssetFactory.h"
#include "Rendering/Views/RuntimeView.h"
#include "Core/FSM.h"

harmony::RuntimeProgram::RuntimeProgram(const std::string& name) : Program(name)
{

}

void harmony::RuntimeProgram::AddAssetTypeNames()
{
	m_AssetManager.AddAssetTypeName<Mesh>();
	m_AssetManager.AddAssetTypeName<Model>();
	m_AssetManager.AddAssetTypeName<Texture>();
	m_AssetManager.AddAssetTypeName<ShaderStage>();
}

void harmony::RuntimeProgram::AddAssetFactories()
{
	m_AssetManager.AddAssetFactory(CreateRef<TextureAssetFactory>(m_Renderer));
	m_AssetManager.AddAssetFactory(CreateRef<ShaderStageBinaryAssetFactory>(m_Renderer));
	m_AssetManager.AddAssetFactory(CreateRef<AssimpModelAssetFactory>(m_Renderer));
}

void harmony::RuntimeProgram::AddProgramComponents()
{
	
}

void harmony::RuntimeProgram::AddSystems()
{
	AddSystem<TransformSystem>();
	AddSystem<CameraSystem>();
	AddSystem<MaterialSystem>(m_Renderer, m_AssetManager);
	AddSystem<MeshSystem>(m_AssetManager);
}

void harmony::RuntimeProgram::AddPipelineStageRenderers()
{
	m_Renderer.AddPipelineStageRenderer(CreateRef<MeshRenderer>());
}

void harmony::RuntimeProgram::InitializePipelines()
{
	p_ForwardPipeline			= CreateRef<Pipeline>(PipelineHandle("Forward Pipeline"), Pipeline::Type::Surface);
	p_VectorGraphicsPipeline	= CreateRef<VectorPipeline>(VectorGraphics::Layer::One);
	p_DebugPipeline = CreateRef<DebugDrawPipeline>(GfxDebug::Channel::Editor);

	p_ForwardPipeline->AddPipelineStage<PipelineStage>("NormalStage1",
		PipelineStage::Type::PrimaryDraw,
		m_Renderer.GetShader("Normal"),
		m_Renderer.GetPipelineStageRenderer("MeshRenderer"),
		(Attachment::Type)(Attachment::Type::RGBA16F | Attachment::Type::Depth32F));
	p_ForwardPipeline->AddPipelineStage<PipelineStage>("TexturedMeshStage",
		PipelineStage::Type::PrimaryDraw,
		m_Renderer.GetShader("TexturedMesh"),
		m_Renderer.GetPipelineStageRenderer("MeshRenderer"),
		(Attachment::Type)(Attachment::Type::RGBA16F | Attachment::Type::Depth32F));

	m_Renderer.AddPipeline(p_DebugPipeline);
	m_Renderer.AddPipeline(p_ForwardPipeline);
	m_Renderer.AddPipeline(p_VectorGraphicsPipeline);
}

void harmony::RuntimeProgram::InitializeViews()
{
	auto runtimeViewWr = m_Renderer.CreateView<RuntimeView>(*this);

	m_Renderer.AddViewPipeline(runtimeViewWr, p_ForwardPipeline);
	m_Renderer.AddViewPipeline(runtimeViewWr, p_VectorGraphicsPipeline);
	m_Renderer.SetViewActive(runtimeViewWr, true);
}

int harmony::RuntimeProgram::OnRuntimeUpdate()
{
	UpdateTimeVariables();

	HandleSDLEvent();

	RunRendererPreUpdate();

	RunProgramComponentUpdate();

	RunSystemUpdate();

	RunRendererPostUpdate();

	RunProgramComponentRender();

	RunSystemRender();

	bgfx::frame();

	return FSM::NO_TRIGGER;
}
