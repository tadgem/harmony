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
	
	auto imageAssetsRefCollection = app.m_AssetManager.LoadAsset<Texture>("dungeon.png");

	WeakRef<Texture> tex = GetDerivedRef<Asset, Texture>(imageAssetsRefCollection[0]);
	app.m_Renderer.SubmitTextureToGPU(tex);

	auto callback = [&]()
	{
		if (ImGui::BeginMainMenuBar())
		{

		}
		ImGui::EndMainMenuBar();
	};
	app.Run(callback);
}