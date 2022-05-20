#include "Core/Program.h"
#include "Core/Log.hpp"
#include "ImGui/ImGuiFileDialog.h"
#include "ImGui/imgui.h"
int main()
{
	harmony::Program app("Harmony Sample Base");
	app.Init();
	app.Run([&]()
	{
		if (ImGui::Begin("Sample"))
		{
                    
		}
		ImGui::End();
	});
}