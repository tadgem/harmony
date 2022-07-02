#include "EditorApplication.h"

harmony::Editor::Editor() : harmony::Program("Harmony Editor")
{
	AddAssetTypeNames();
	AddAssetFactories();
	AddProgramComponents();
	AddSystems();
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
}
