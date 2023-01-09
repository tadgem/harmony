#include "EditorApplication.h"
#include "Rendering/Shapes.h"
#include "ECS/MaterialSystem.h"
#include "ECS/CameraSystem.h"
#include "Core/Time.h"
#include "Core/Input.h"
#include "ShaderHotReload.h"
#include "Rendering/Views/RuntimeView.h"
#include "Rendering/PipelineStageRenderers/MeshRenderer.h"
#include "Assets/ShaderSourceAssetFactory.h"
#include "AssimpModelAssetFactory.h"
#include "EditorView.h"
harmony::Editor::Editor() : harmony::RuntimeProgram("Editor"), p_MainMenuBar(*this)
{
	AddAssetTypeNames();
	AddAssetFactories();
	AddProgramComponents();
	AddSystems();
	AddPipelineStageRenderers();

	AddEditorPanels();

	m_EditorFSM.AddState(Mode::Edit, [&]() {return OnEditUpdate(); });
	m_EditorFSM.AddStateExit(Mode::Edit, [&]() {OnEditExit(); });

	m_EditorFSM.AddState(Mode::Debug, [&]() {return OnRuntimeUpdate(); });
	m_EditorFSM.AddStateExit(Mode::Debug, [&]() {OnRuntimeExit(); });

	m_EditorFSM.AddTrigger(Trigger::Play, Mode::Edit, Mode::Debug);
	m_EditorFSM.AddTrigger(Trigger::Stop, Mode::Debug, Mode::Edit);

	m_EditorFSM.SetStartingState(Mode::Edit);

}

void harmony::Editor::AddAssetTypeNames()
{
	RuntimeProgram::AddAssetTypeNames();
	m_AssetManager.AddAssetTypeName<ShaderSourceAsset>();
}

void harmony::Editor::AddAssetFactories()
{
	RuntimeProgram::AddAssetFactories();
	m_AssetManager.AddAssetFactory(CreateRef<ShaderSourceAssetFactory>());
}

void harmony::Editor::AddProgramComponents()
{
	RuntimeProgram::AddProgramComponents();
	AddProgramComponent<ShaderHotReload>(*this);
}

void harmony::Editor::AddSystems()
{
	RuntimeProgram::AddSystems();
	p_TransformSystem	= GetSystem<TransformSystem>().lock();
	p_CameraSystem		= GetSystem<CameraSystem>().lock();
	p_MeshSystem		= GetSystem<MeshSystem>().lock();

}

void harmony::Editor::AddPipelineStageRenderers()
{
	RuntimeProgram::AddPipelineStageRenderers();
}

void harmony::Editor::AddEditorPanels()
{
	p_ScenePanel = CreateRef<ScenePanel>(*this);
	p_Panels.emplace_back(p_ScenePanel);

	Ref<AssetManagerPanel> assetManagerPanel = CreateRef<AssetManagerPanel>(*this);
	p_Panels.emplace_back(assetManagerPanel);

	Ref<EntityInspectorPanel> inspector = CreateRef<EntityInspectorPanel>(*this, p_ScenePanel);
	
	inspector->AddComponentUI<TransformComponentUI>();
	inspector->AddComponentUI<MeshComponentUI>(m_AssetManager);
	inspector->AddComponentUI<MaterialComponentUI>(m_Renderer, m_AssetManager);
	inspector->AddComponentUI<CameraComponentUI>(m_Renderer);
	inspector->AddComponentUI<DirectionalLightComponentUI>();
	inspector->AddComponentUI<PointLightComponentUI>();
	inspector->AddComponentUI<SpotLightComponentUI>();

	p_Panels.emplace_back(inspector);
}

void harmony::Editor::InitializePipelines()
{
	RuntimeProgram::InitializePipelines();
}

void harmony::Editor::InitializeViews()
{
	RuntimeProgram::InitializeViews();

	auto editorViewWr = m_Renderer.CreateView<EditorView>(*this, p_ScenePanel);
	m_Renderer.AddViewPipeline(editorViewWr, p_DebugPipeline);
	m_Renderer.AddViewPipeline(editorViewWr, p_ForwardPipeline);
	m_Renderer.AddViewPipeline(editorViewWr, p_VectorGraphicsPipeline);
	m_Renderer.SetViewActive(editorViewWr, true);

	p_EditorView = editorViewWr.lock();
}

void harmony::Editor::SaveProject()
{
	Program::SaveProject();
	SaveImGuiSettings();
}

void harmony::Editor::LoadProject(const std::string& path)
{
	Program::LoadProject(path);
	LoadImGuiSettings();
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
		p_MeshSystem->Update(p_ActiveScene->m_Registry);
		p_TransformSystem->Update(p_ActiveScene->m_Registry);
		p_CameraSystem->Update(p_ActiveScene->m_Registry);


		VectorGraphics::Get()->FontSize(VectorGraphics::One, 20.0f);
		VectorGraphics::Get()->FontFace(VectorGraphics::One, "carbontype");
		VectorGraphics::Get()->FontBlur(VectorGraphics::One, 0);
		VectorGraphics::Get()->FillColor(VectorGraphics::One, nvgRGBA(220, 220, 220, 160));
		VectorGraphics::Get()->Text(VectorGraphics::One, 0.0f, 30.0f, "carbontype");
	}

	RunRendererPostUpdate();

	RunProgramComponentRender();

	Input::PostFrame();

	UpdateEditor();

	ImGuiPostUpdate();

	bgfx::frame();

	return FSM::NO_TRIGGER;
}

void harmony::Editor::OnEditExit()
{
	SaveScene(p_LoadedScenePath);
}

int harmony::Editor::OnRuntimeUpdate()
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

	Input::PostFrame();

	ImGuiPostUpdate();
	  
	bgfx::frame();

	return FSM::NO_TRIGGER;
}

void harmony::Editor::OnRuntimeExit()
{
	LoadScene(p_LoadedScenePath);
}

void harmony::Editor::Run()
{
	HARMONY_PROFILE_FUNCTION()

	Init();
	m_Renderer.Init();

	AddPipelineDrawStages();
	AddPostProcessStages();

	InitializePipelines();
	InitializeViews();
	PreRunInit();

	SetStyle();

	while (p_Run)
	{
		m_EditorFSM.Process();
	}
}

void harmony::Editor::Run(const std::string& projectPath)
{
	HARMONY_PROFILE_FUNCTION()

	Init();
	m_Renderer.Init();

	AddPipelineDrawStages();
	AddPostProcessStages();

	InitializePipelines();
	InitializeViews();

	LoadProject(projectPath);

	PreRunInit();

	SetStyle();

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
