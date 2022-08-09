#include "EditorApplication.h"
#include "Rendering/Shapes.h"
#include "ECS/MeshSystem.h"
#include "ECS/MaterialSystem.h"
#include "Core/Time.h"
#include "Core/Input.h"
#include "ShaderHotReload.h"
#include "Assets/ShaderSourceAssetFactory.h"
#include "LuaScriptAssetFactory.h"

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
	m_AssetManager.AddAssetTypeName<ShaderSourceAsset>();
	m_AssetManager.AddAssetTypeName<ShaderStage>();
}

void harmony::Editor::AddAssetFactories()
{
	m_AssetManager.AddAssetFactory(CreateRef<TextureAssetFactory>(m_Renderer));
	m_AssetManager.AddAssetFactory(CreateRef<AssimpModelAssetFactory>(m_Renderer));
	m_AssetManager.AddAssetFactory(CreateRef<ShaderStageBinaryAssetFactory>(m_Renderer));
	m_AssetManager.AddAssetFactory(CreateRef<ShaderSourceAssetFactory>());
	m_AssetManager.AddAssetFactory(CreateRef<LuaScriptAssetFactory>());
}

void harmony::Editor::AddProgramComponents()
{
	AddProgramComponent<ShaderHotReload>(*this);
}

void harmony::Editor::AddSystems()
{
	AddSystem<TransformSystem>();
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
	p_Panels.emplace_back(inspector);
}

void harmony::Editor::InitializePipelines()
{
	p_DebugPipeline = CreateRef<DebugDrawPipeline>(GfxDebug::Channel::Editor);
	p_TexturedMeshPipeline = CreateRef<Pipeline>(PipelineHandle::New("Textured Mesh"));
	p_NormalPipeline = CreateRef<Pipeline>(PipelineHandle::New("Mesh Normals"));
	p_VectorGraphicsPipeline = CreateRef<VectorPipeline>();
	
	p_NormalPipeline->AddPipelineStage<PipelineStage>("NormalStage", PipelineStage::Type::PrimaryDraw, m_Renderer.GetShader("Normal"));
	p_TexturedMeshPipeline->AddPipelineStage<PipelineStage>("TexturedMeshStage", PipelineStage::Type::PrimaryDraw, m_Renderer.GetShader("TexturedMesh"));
	
	m_Renderer.AddPipeline(p_DebugPipeline, true);
	m_Renderer.AddPipeline(p_TexturedMeshPipeline, true);
	m_Renderer.AddPipeline(p_NormalPipeline, true);
	m_Renderer.AddPipeline(p_VectorGraphicsPipeline, true);
}

void harmony::Editor::InitializeViews()
{
	auto viewWr = m_Renderer.CreateView<EditorView>(*this, p_ScenePanel);

	m_Renderer.AddViewPipeline(viewWr, p_DebugPipeline);
	m_Renderer.AddViewPipeline(viewWr, p_NormalPipeline);
	m_Renderer.AddViewPipeline(viewWr, p_TexturedMeshPipeline);
	m_Renderer.AddViewPipeline(viewWr, p_VectorGraphicsPipeline);
	m_Renderer.SetViewActive(viewWr, true);

	p_EditorView = viewWr.lock();
}

void harmony::Editor::RunEditor()
{
	Init();
	m_Renderer.Init();
	InitializePipelines();
	InitializeViews();

	LoadProject("../../projects/Test/Test.harmonyproj");
	auto callback = [&]()
	{
		UpdateEditor();
	};

	Run(callback);
}

void harmony::Editor::UpdateEditor()
{
	GfxDebug::Get()->setColor(GfxDebug::Channel::Editor, 0xfffffff);
	GfxDebug::Get()->drawGrid(GfxDebug::Channel::Editor, Axis::Enum::Y, bx::Vec3(0.0f, 0.0f, 0.0f), 1000);
	
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
