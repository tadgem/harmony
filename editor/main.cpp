#include "EditorApplication.h"
#include "Core/Log.hpp"
#include "ImGui/ImGuiFileDialog.h"
#include "ImGui/imgui.h"
#include "Rendering/Model.h"
#include "AssimpModelAssetFactory.h"
#include "Assets/TextureAssetFactory.h"

int main()
{
	harmony::Editor app;
	app.m_AssetManager.AddAssetFactory(harmony::CreateRef<harmony::AssimpModelAssetFactory>());
	app.m_AssetManager.AddAssetFactory(harmony::CreateRef<harmony::TextureAssetFactory>());
	
	app.Init();
	
	app.m_AssetManager.LoadAsset<harmony::Model>("sponza/sponza.obj");
	app.m_AssetManager.LoadAsset<harmony::Texture>("test.png");

	app.Run([&]()
	{
		if (ImGui::Begin("Sample"))
		{
                    
		}
		ImGui::End();
	});
}