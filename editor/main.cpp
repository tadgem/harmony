#include "EditorApplication.h"
#include "Core/Log.hpp"
#include "ImGui/ImGuiFileDialog.h"
#include "ImGui/imgui.h"
#include "Rendering/Model.h"
#include "AssimpModelAssetFactory.h"
int main()
{
	harmony::Editor app;
	app.m_AssetManager.AddAssetFactory(harmony::CreateRef<harmony::AssimpModelAssetFactory>());
	app.m_AssetManager.LoadAsset<harmony::Model>("sponza/sponza.obj");
	app.Init();

	app.Run([&]()
	{
		if (ImGui::Begin("Sample"))
		{
                    
		}
		ImGui::End();
	});
}