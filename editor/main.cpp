#include "EditorApplication.h"
#include "Core/Log.hpp"
#include "ImGui/ImGuiFileDialog.h"
#include "ImGui/imgui.h"
#include "Rendering/Model.h"
#include "AssimpModelAssetFactory.h"
#include "Assets/TextureAssetFactory.h"
#include "ECS/TransformSystem.h"
#include "ECS/TileMapSystem.h"
#include "ImGui/icons_font_awesome.h"
int main()
{
	using namespace harmony;
	Editor app;
	app.m_AssetManager.AddAssetFactory(CreateRef<AssimpModelAssetFactory>());
	app.m_AssetManager.AddAssetFactory(CreateRef<TextureAssetFactory>());
	app.AddSystem<TransformSystem>();
	app.AddSystem<TileMapSystem>();
	app.Init();
	
	// app.m_AssetManager.LoadAsset<Model>("sponza/sponza.obj");
	auto imageAssetsRefCollection = app.m_AssetManager.LoadAsset<Texture>("dungeon.png");

	WeakRef<Texture> tex = GetDerivedRef<Asset, Texture>(imageAssetsRefCollection[0]);
	app.m_Renderer.SubmitTextureToGPU(tex);

	app.Run([&]()
	{
#if HARMONY_DEBUG
			if (ImGui::Begin("Me Window"))
			{
				ImGui::Text("SomeText");
				ImGui::Text(ICON_FA_MUSIC);
			}
			ImGui::End();
		app.m_AssetManager.OnImGui();
#endif
	});
}