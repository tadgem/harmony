#include "RuntimeProgram.h"
#include "AssimpModelAssetFactory.h"
#include "Assets/FontAssetFactory.h"
#include "Rendering/Views/RuntimeView.h"
#include "Rendering/ShaderDataSources/BlinnPhongDataSource.h"
#include "Rendering/Shapes.h"
#include "Core/FSM.h"
#include "ECS/LightSystem.h"
#include "LuaProgramComponent.h"
#include "LuaSystem.h";
#include "LuaScriptAssetFactory.h";
#include "ECS/SimpleCollisionSystem.h"

harmony::RuntimeProgram::RuntimeProgram(const std::string& name) : Program(name)
{
	AddAssetTypeNames();
	AddAssetFactories();
	AddProgramComponents();
	AddSystems();
	AddPipelineStageRenderers();
	AddShaderDataSources();
	AddPostProcessStages();

	// TODO: Need some way of tracking max view ids.
	p_PresentViewId = (bgfx::ViewId)255;
}

void harmony::RuntimeProgram::Run()
{
	HARMONY_PROFILE_FUNCTION()

	Init();
	m_Renderer.Init();
	
	AddPipelineDrawStages();

	InitializePipelines();
	InitializeViews();

	PreRunInit();

	SDL_SetRelativeMouseMode(SDL_TRUE);

	while (p_Run)
	{
		OnRuntimeUpdate();
	}
}

void harmony::RuntimeProgram::Run(const std::string& projectPath)
{
	HARMONY_PROFILE_FUNCTION()
	Init();
	m_Renderer.Init();

	AddPipelineDrawStages();

	InitializePipelines();
	InitializeViews();

	PreRunInit();

	SDL_SetRelativeMouseMode(SDL_TRUE);

	LoadProject(projectPath);
	OpenScene(0);

	ResizeApplicationWindow(p_WindowWidth, p_WindowHeight);

	while (p_Run)
	{
		OnRuntimeUpdate();
	}
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
	m_AssetManager.AddAssetFactory(CreateRef<FontAssetFactory>());
	m_AssetManager.AddAssetFactory(CreateRef<LuaScriptAssetFactory>());

}

void harmony::RuntimeProgram::AddProgramComponents()
{
	p_LuaProgramComponent = AddProgramComponent<LuaProgramComponent>().lock();
}

void harmony::RuntimeProgram::AddSystems()
{
	AddSystem<TransformSystem>();
	AddSystem<CameraSystem>();
	AddSystem<MaterialSystem>(m_Renderer, m_AssetManager);
	AddSystem<MeshSystem>(m_AssetManager);
	AddSystem<LightSystem>();
	p_LuaSystem = AddSystem<LuaSystem>(m_AssetManager, p_LuaProgramComponent).lock();
	p_SimpleCollisionSystem = AddSystem<SimpleCollisionSystem>(m_AssetManager).lock();
}

void harmony::RuntimeProgram::AddPipelineStageRenderers()
{
	m_Renderer.AddPipelineStageRenderer(CreateRef<MeshRenderer>());
}

void harmony::RuntimeProgram::AddPipelineDrawStages()
{
	Ref<PipelineDrawStage> normalStage = CreateRef<PipelineDrawStage>(
		"NormalStage",
		PipelineDrawStage::Type::PrimaryDraw,
		m_Renderer.GetShader("Normal"),
		m_Renderer.GetPipelineStageRenderer("MeshRenderer"),
		(Attachment::Type)(Attachment::Type::RGBA16F | Attachment::Type::Depth32F)
	);

	Ref<PipelineDrawStage> texturedMeshStage = CreateRef<PipelineDrawStage>(
		"TexturedMeshStage",
		PipelineDrawStage::Type::PrimaryDraw,
		m_Renderer.GetShader("TexturedMesh"),
		m_Renderer.GetPipelineStageRenderer("MeshRenderer"),
		(Attachment::Type)(Attachment::Type::RGBA16F | Attachment::Type::Depth32F)
		);

	Ref<PipelineDrawStage> blinnPhongStage = CreateRef<PipelineDrawStage>(
		"BlinnPhongTextured",
		PipelineDrawStage::Type::PrimaryDraw,
		m_Renderer.GetShader("BlinnPhongTextured"),
		m_Renderer.GetPipelineStageRenderer("MeshRenderer"),
		(Attachment::Type)(Attachment::Type::RGBA16F | Attachment::Type::Depth32F)
		);


	blinnPhongStage->AddShaderDataSource(m_Renderer.GetShaderDataSource("BlinnPhong"));
	m_Renderer.AddPipelineDrawStage(normalStage);
	m_Renderer.AddPipelineDrawStage(texturedMeshStage);
	m_Renderer.AddPipelineDrawStage(blinnPhongStage);
}

void harmony::RuntimeProgram::AddPostProcessStages()
{

}

void harmony::RuntimeProgram::AddShaderDataSources()
{
	Ref<BlinnPhongDataSource> blinnPhong = CreateRef<BlinnPhongDataSource>();
	m_Renderer.AddShaderDataSource(blinnPhong);
}

void harmony::RuntimeProgram::InitializePipelines()
{
	p_ForwardPipeline			= CreateRef<Pipeline>(PipelineHandle("Forward Pipeline"), Pipeline::Type::Surface);
	p_VectorGraphicsPipeline	= CreateRef<VectorPipeline>(VectorGraphics::Layer::One);
	p_DebugPipeline				= CreateRef<DebugDrawPipeline>(GfxDebug::Channel::Editor);

	p_ForwardPipeline->AddPipelineStage(m_Renderer.GetPipelineDrawStage("NormalStage").lock());
	p_ForwardPipeline->AddPipelineStage(m_Renderer.GetPipelineDrawStage("TexturedMeshStage").lock());
	p_ForwardPipeline->AddPipelineStage(m_Renderer.GetPipelineDrawStage("BlinnPhongTextured").lock());

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

	p_RuntimeView = runtimeViewWr.lock();
}



void harmony::RuntimeProgram::LoadScene(const std::string& path)
{
	Program::LoadScene(path);
	RunSystemInit();
}

void harmony::RuntimeProgram::OpenScene(uint32_t index)
{
	Program::OpenScene(index);
	RunSystemInit();
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

	PresentRuntimeImage();

	Frame();

	return FSM::NO_TRIGGER;
}

void harmony::RuntimeProgram::LoadBuiltInAssets()
{
	AssetHandle cubeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Cube", CreateRef<Cube>(1.0f));
	Ref<Mesh> cube = m_AssetManager.GetAsset<Mesh>(cubeHandle).lock();
	m_Renderer.SubmitMeshToGPU(cube);
	AssetHandle planeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Plane", CreateRef<Plane>(1.0f));
	Ref<Mesh> plane = m_AssetManager.GetAsset<Mesh>(planeHandle).lock();
	m_Renderer.SubmitMeshToGPU(plane);	
}

void harmony::RuntimeProgram::ResizeApplicationWindow(int w, int h)
{
	HARMONY_PROFILE_FUNCTION()

	Program::ResizeApplicationWindow(w, h);
	bgfx::setViewRect(p_PresentViewId, 0, 0, p_WindowWidth, p_WindowHeight);

	p_RuntimeView->OnResized(p_WindowWidth, p_WindowHeight);
}

void harmony::RuntimeProgram::PresentRuntimeImage()
{
	bgfx::setViewClear(p_PresentViewId, BGFX_CLEAR_COLOR, 0);
	bgfx::setViewClear(p_PresentViewId, BGFX_CLEAR_DEPTH, 0, 1.0f);
	auto stack = m_Renderer.GetViewPipelineStack(p_RuntimeView->m_Name);
	bgfx::setTexture(0, m_Renderer.p_PresentProgramTextureHandle, stack.GetFinalImage(), BGFX_SAMPLER_POINT);
	ScreenSpaceQuad(static_cast<float>(p_WindowWidth), static_cast<float>(p_WindowHeight));
	bgfx::submit(p_PresentViewId, m_Renderer.p_PresentProgram.lock()->m_Handle);
}
