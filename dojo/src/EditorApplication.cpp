#include "EditorApplication.h"

harmony::Editor::Editor() : harmony::Program("Harmony Editor"), p_MainMenuBar(*this)
{
	AddAssetTypeNames();
	AddAssetFactories();
	AddProgramComponents();
	AddSystems();

	AddEditorPanels();

	InitializePipelines();
	InitializeViews();
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
}

void harmony::Editor::AddEditorPanels()
{
	p_Panels.emplace_back(CreateRef<ScenePanel>(*this));
	p_Panels.emplace_back(CreateRef<EntityInspectorPanel>(*this));
}

void harmony::Editor::InitializePipelines()
{
	auto debugDrawPipelineWr = m_Renderer.CreatePipeline<DebugDrawPipeline>();
	auto texturedMeshPipelineWr = m_Renderer.CreatePipeline<TexturedMeshPipeline>();

	p_DebugPipeline = debugDrawPipelineWr.lock();
	p_TexturedMeshPipeline = texturedMeshPipelineWr.lock();

}

void harmony::Editor::InitializeViews()
{
	auto viewWr = m_Renderer.CreateView<EditorView>();

	m_Renderer.AddViewPipeline(viewWr, p_DebugPipeline);
	m_Renderer.AddViewPipeline(viewWr, p_TexturedMeshPipeline);
	m_Renderer.SetViewActive(viewWr, true);

	p_EditorView = viewWr.lock();
}

void harmony::Editor::RunEditor()
{
	Init();

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
	ImGui::SetNextWindowPos(viewport->Pos);
	ImGui::SetNextWindowSize(viewport->Size);
	ImGui::SetNextWindowViewport(viewport->ID);
	window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
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
	ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
	ImGui::End();
}
