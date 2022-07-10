#include "EditorApplication.h"
#include "Rendering/Shapes.h"
#include "ECS/MeshSystem.h"
#include "Rendering/Pipelines/NormalPipeline.h"
harmony::Editor::Editor() : harmony::Program("Harmony Editor"), p_MainMenuBar(*this)
{
	AddAssetTypeNames();
	AddAssetFactories();
	AddProgramComponents();
	AddSystems();

	AddEditorPanels();
}

void harmony::Editor::AddAssetTypeNames()
{
	m_AssetManager.AddAssetTypeName<Mesh>();
	m_AssetManager.AddAssetTypeName<Model>();
	m_AssetManager.AddAssetTypeName<Texture>();
}

void harmony::Editor::AddAssetFactories()
{
	m_AssetManager.AddAssetFactory(CreateRef<TextureAssetFactory>());
	m_AssetManager.AddAssetFactory(CreateRef<AssimpModelAssetFactory>());

}

void harmony::Editor::AddProgramComponents()
{
	AddProgramComponent<LuaProgramComponent>();
}

void harmony::Editor::AddSystems()
{
	AddSystem<TransformSystem>();
	AddSystem<MeshSystem>(m_AssetManager);
}

void harmony::Editor::AddEditorPanels()
{
	Ref<ScenePanel> scenePanel = CreateRef<ScenePanel>(*this);
	p_Panels.emplace_back(scenePanel);
	
	Ref<EntityInspectorPanel> inspector = CreateRef<EntityInspectorPanel>(*this, scenePanel);
	inspector->AddComponentUI<TransformComponentUI>();
	inspector->AddComponentUI<MeshComponentUI>(m_AssetManager);
	inspector->AddComponentUI<MaterialComponentUI>(m_Renderer);
	p_Panels.emplace_back(inspector);
}

void harmony::Editor::InitializePipelines()
{
	auto debugDrawPipelineWr = m_Renderer.CreatePipeline<DebugDrawPipeline>();
	auto texturedMeshPipelineWr = m_Renderer.CreatePipeline<TexturedMeshPipeline>();
	auto normalPipelineWr = m_Renderer.CreatePipeline<NormalPipeline>();
	p_DebugPipeline = debugDrawPipelineWr.lock();
	p_TexturedMeshPipeline = texturedMeshPipelineWr.lock();
	p_NormalPipeline = normalPipelineWr.lock();

}

void harmony::Editor::InitializeViews()
{
	auto viewWr = m_Renderer.CreateView<EditorView>();

	m_Renderer.AddViewPipeline(viewWr, p_DebugPipeline);
	m_Renderer.AddViewPipeline(viewWr, p_NormalPipeline);
	m_Renderer.AddViewPipeline(viewWr, p_TexturedMeshPipeline);
	m_Renderer.SetViewActive(viewWr, true);

	p_EditorView = viewWr.lock();
}

void harmony::Editor::RunEditor()
{
	Init();
	m_Renderer.Init();
	InitializePipelines();
	InitializeViews();

	LoadProject("D:/Test/Test.harmonyproj");
	auto callback = [&]()
	{
		UpdateEditor();
	};

	Run(callback);
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
