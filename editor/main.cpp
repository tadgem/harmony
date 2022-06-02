#include "EditorApplication.h"
#include "Core/Log.hpp"
#include "ImGui/ImGuiFileDialog.h"
#include "ImGui/imgui.h"
#include "Rendering/Model.h"
#include "AssimpModelAssetFactory.h"
#include "Assets/TextureAssetFactory.h"

int main()
{
	using namespace harmony;
	Editor app;
	app.m_AssetManager.AddAssetFactory(CreateRef<AssimpModelAssetFactory>());
	app.m_AssetManager.AddAssetFactory(CreateRef<TextureAssetFactory>());
	
	app.Init();
	
	// app.m_AssetManager.LoadAsset<Model>("sponza/sponza.obj");
	auto imageAssetsRefCollection = app.m_AssetManager.LoadAsset<Texture>("dungeon.png");

	WeakRef<Texture> tex = GetDerivedRef<Asset, Texture>(imageAssetsRefCollection[0]);
	app.m_Renderer.SubmitTextureToGPU(tex);

	app.Run([&]()
	{
#if HARMONY_DEBUG
		app.m_AssetManager.OnImGui();
#endif
	});
}