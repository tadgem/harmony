#include "EditorApplication.h"
#include "Core/Log.hpp"
#include "ImGui/ImGuiFileDialog.h"
#include "ImGui/imgui.h"
int main()
{
	harmony::Editor app;
	app.Init();
	app.Run([&]()
	{
			if (ImGui::Begin("Sample"))
			{
                    
			}
			ImGui::End();
	});
}