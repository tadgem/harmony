#include "EditorApplication.h"
#include "Rendering/Shapes.h"
#include "ECS/MeshSystem.h"
#include "ECS/MaterialSystem.h"
#include "ECS/CameraSystem.h"
#include "Core/Time.h"
#include "Core/Input.h"
#include "ShaderHotReload.h"
#include "Rendering/Views/RuntimeView.h"
#include "Assets/ShaderSourceAssetFactory.h"
harmony::Editor::Editor() : harmony::Program("Harmony Editor"), p_MainMenuBar(*this)
{
	AddAssetTypeNames();
	AddAssetFactories();
	AddProgramComponents();
	AddSystems();

	AddEditorPanels();

	m_EditorFSM.AddState(Mode::Edit,		[&]() {return OnEditUpdate(); });
	m_EditorFSM.AddStateExit(Mode::Edit, [&]() {OnEditExit(); });
	
	m_EditorFSM.AddState(Mode::Debug, 		[&]() {return OnDebugUpdate(); });
	m_EditorFSM.AddStateExit(Mode::Debug, [&]() {OnDebugExit(); });

	m_EditorFSM.AddTrigger(Trigger::Play, Mode::Edit, Mode::Debug);
	m_EditorFSM.AddTrigger(Trigger::Stop, Mode::Debug, Mode::Edit);

	m_EditorFSM.SetStartingState(Mode::Edit);

}

void harmony::Editor::AddAssetTypeNames()
{
	m_AssetManager.AddAssetTypeName<Mesh>();
	m_AssetManager.AddAssetTypeName<Model>();
	m_AssetManager.AddAssetTypeName<Texture>();
	m_AssetManager.AddAssetTypeName<ShaderSourceAsset>();
	m_AssetManager.AddAssetTypeName<ShaderStage>();
}

void harmony::Editor::AddAssetFactories()
{
	m_AssetManager.AddAssetFactory(CreateRef<TextureAssetFactory>(m_Renderer));
	m_AssetManager.AddAssetFactory(CreateRef<AssimpModelAssetFactory>(m_Renderer));
	m_AssetManager.AddAssetFactory(CreateRef<ShaderStageBinaryAssetFactory>(m_Renderer));
	m_AssetManager.AddAssetFactory(CreateRef<ShaderSourceAssetFactory>());
}

void harmony::Editor::AddProgramComponents()
{
	AddProgramComponent<ShaderHotReload>(*this);
}

void harmony::Editor::AddSystems()
{
	p_TransformSystem = AddSystem<TransformSystem>().lock();
	p_CameraSystem = AddSystem<CameraSystem>().lock();
	AddSystem<MaterialSystem>(m_Renderer, m_AssetManager);
	AddSystem<MeshSystem>(m_AssetManager);
	
}

void harmony::Editor::AddEditorPanels()
{
	p_ScenePanel = CreateRef<ScenePanel>(*this);
	Ref<AssetManagerPanel> assetManagerPanel = CreateRef<AssetManagerPanel>(*this);
	p_Panels.emplace_back(p_ScenePanel);
	p_Panels.emplace_back(assetManagerPanel);
	
	Ref<EntityInspectorPanel> inspector = CreateRef<EntityInspectorPanel>(*this, p_ScenePanel);
	inspector->AddComponentUI<TransformComponentUI>();
	inspector->AddComponentUI<MeshComponentUI>(m_AssetManager);
	inspector->AddComponentUI<MaterialComponentUI>(m_Renderer, m_AssetManager);
	inspector->AddComponentUI<CameraComponentUI>(m_Renderer);
	p_Panels.emplace_back(inspector);
}

void harmony::Editor::InitializePipelines()
{
	p_DebugPipeline = CreateRef<DebugDrawPipeline>(GfxDebug::Channel::Editor);
	p_RuntimeDebugPipeline = CreateRef<DebugDrawPipeline>(GfxDebug::Channel::Game);

	p_TexturedMeshPipeline = CreateRef<Pipeline>(PipelineHandle{ "Editor Textured Mesh" });
	
	p_NormalPipeline = CreateRef<Pipeline>(PipelineHandle{ "Editor Mesh Normals" });
	p_RuntimeTexturedMeshPipeline = CreateRef<Pipeline>(PipelineHandle{"Runtime Textured Mesh"});
	p_RuntimeNormalPipeline = CreateRef<Pipeline>(PipelineHandle{ "Runtime Mesh Normals" });
	p_VectorGraphicsPipeline = CreateRef<VectorPipeline>();
	
	p_NormalPipeline->AddPipelineStage<PipelineStage>("NormalStage1", PipelineStage::Type::PrimaryDraw, m_Renderer.GetShader("Normal"));
	
	p_TexturedMeshPipeline->AddPipelineStage<PipelineStage>("TexturedMeshStage1", PipelineStage::Type::PrimaryDraw, m_Renderer.GetShader("TexturedMesh"));
	
	p_RuntimeNormalPipeline->AddPipelineStage<PipelineStage>("NormalStage2", PipelineStage::Type::PrimaryDraw, m_Renderer.GetShader("Normal"));
	p_RuntimeTexturedMeshPipeline->AddPipelineStage<PipelineStage>("TexturedMeshStage2", PipelineStage::Type::PrimaryDraw, m_Renderer.GetShader("TexturedMesh"));


	m_Renderer.AddPipeline(p_DebugPipeline);
	m_Renderer.AddPipeline(p_RuntimeDebugPipeline);
	m_Renderer.AddPipeline(p_TexturedMeshPipeline);
	m_Renderer.AddPipeline(p_NormalPipeline);
	m_Renderer.AddPipeline(p_RuntimeTexturedMeshPipeline);
	m_Renderer.AddPipeline(p_RuntimeNormalPipeline);
	m_Renderer.AddPipeline(p_VectorGraphicsPipeline);
}

void harmony::Editor::InitializeViews()
{
	auto editorViewWr = m_Renderer.CreateView<EditorView>(*this, p_ScenePanel);
	auto runtimeViewWr = m_Renderer.CreateView<RuntimeView>(*this);
	m_Renderer.AddViewPipeline(editorViewWr, p_DebugPipeline);
	m_Renderer.AddViewPipeline(editorViewWr, p_NormalPipeline);
	m_Renderer.AddViewPipeline(editorViewWr, p_TexturedMeshPipeline);
	m_Renderer.SetViewActive(editorViewWr, true);

	m_Renderer.AddViewPipeline(runtimeViewWr, p_RuntimeDebugPipeline);
	m_Renderer.AddViewPipeline(runtimeViewWr, p_RuntimeNormalPipeline);
	m_Renderer.AddViewPipeline(runtimeViewWr, p_RuntimeTexturedMeshPipeline);
	m_Renderer.AddViewPipeline(runtimeViewWr, p_VectorGraphicsPipeline);
	m_Renderer.SetViewActive(runtimeViewWr, true);

	p_EditorView = editorViewWr.lock();
}

int harmony::Editor::OnEditUpdate()
{
	UpdateTimeVariables();

	HandleSDLEvent();

	ImGuiPreUpdate();

	RunRendererPreUpdate();

	RunProgramComponentUpdate();

	if (p_ActiveScene)
	{
		p_TransformSystem->Update(p_ActiveScene->m_Registry);
		p_CameraSystem->Update(p_ActiveScene->m_Registry);
	}

	RunRendererPostUpdate();

	RunProgramComponentRender();

	Input::Get()->PostFrame();

	UpdateEditor();

	ImGuiPostUpdate();

	bgfx::frame();

	return FSM::NO_TRIGGER;
}

void harmony::Editor::OnEditExit()
{
	SaveScene(p_LoadedScenePath);
}

int harmony::Editor::OnDebugUpdate()
{
	UpdateTimeVariables();

	HandleSDLEvent();

	RunRendererPreUpdate();

	ImGuiPreUpdate();

	RunProgramComponentUpdate();

	RunSystemUpdate();

	RunRendererPostUpdate();

	RunProgramComponentRender();

	RunSystemRender();

	UpdateEditor();

	Input::Get()->PostFrame();

	ImGuiPostUpdate();

	bgfx::frame();

	return FSM::NO_TRIGGER;
}

void harmony::Editor::OnDebugExit()
{
	LoadScene(p_LoadedScenePath);
}

void harmony::Editor::Run()
{
	HARMONY_PROFILE_FUNCTION()

	Init();
	m_Renderer.Init();
	InitializePipelines();
	InitializeViews();
#if HARMONY_DEBUG && BX_PLATFORM_WINDOWS
	LoadProject("../../projects/Test/Test.harmonyproj");
#endif
	
	PreRunInit();

	while (p_Run)
	{
		m_EditorFSM.Process();
	}
}

void harmony::Editor::LoadScene(const std::string& path)
{
	Program::LoadScene(path);
	p_LoadedScenePath = path;
}

void harmony::Editor::OpenScene(uint32_t index)
{
	Program::OpenScene(index);
	p_LoadedScenePath = m_Project->m_SerializedScenes[index];
}

void harmony::Editor::UpdateEditor()
{
	p_MainMenuBar.OnImGui();
	GlobalDockspace();

	m_Renderer.OnImGui();
	m_AssetManager.OnImGui();

	for (int i = 0; i < p_Panels.size(); i++)
	{
		p_Panels[i]->OnImGui();
	}

	if (VectorGraphics::GetNVGContext() == nullptr)
	{
		return;
	}

	if (!p_ActiveScene)
	{
		return;
	}
	
	//GfxDebug::Get()->setColor(GfxDebug::Channel::Editor, 0xfffffff);
	//GfxDebug::Get()->drawGrid(GfxDebug::Channel::Editor, Axis::Enum::Y, bx::Vec3(0.0f, 0.0f, 0.0f), 1000);
	
}

void harmony::Editor::GlobalDockspace()
{
	static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_PassthruCentralNode;

	ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

	ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImVec2 winPos = viewport->Pos;
	ImVec2 winSize = viewport->Size;
	//winPos.y += p_MainMenuBar.m_MenuBarSize.y;
	winSize.x = p_WindowWidth;
	winSize.y = p_WindowHeight + p_MainMenuBar.m_MenuBarSize.y;
	ImGui::SetNextWindowPos(winPos);
	ImGui::SetNextWindowSize(winSize);
	ImGui::SetNextWindowViewport(viewport->ID);

	window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;
	window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;


	// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
	if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
		window_flags |= ImGuiWindowFlags_NoBackground;

	// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
	// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive, 
	// all active windows docked into it will lose their parent and become undocked.
	// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise 
	// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
	ImGui::Begin("DockSpace", nullptr, window_flags);
	ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
	ImGui::DockSpace(dockspace_id, winSize, dockspace_flags);
	ImGui::End();
}

void harmony::Editor::LoadBuiltInAssets()
{
	AssetHandle cubeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Cube", CreateRef<Cube>(1.0f));
	Ref<Mesh> cube = m_AssetManager.GetAsset<Mesh>(cubeHandle).lock();
	m_Renderer.SubmitMeshToGPU(cube);
	AssetHandle planeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Plane", CreateRef<Plane>(1.0f));
	Ref<Mesh> plane = m_AssetManager.GetAsset<Mesh>(planeHandle).lock();
	m_Renderer.SubmitMeshToGPU(plane);
}
