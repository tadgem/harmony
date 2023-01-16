#include "Profiler.h"

void harmony::ProfilerPanel::OnImGui()
{

	if (ImGui::Begin("Profiler"))
	{
		auto results = Instrumentor::GetResults();
		for (auto& [name, result] : results)
		{
			float time = (float) ((result.End - (float) result.Start) / 1000.0f);
			std::string i = " : " + std::to_string(time);
			ImGui::Text("%f : %s", time, name.c_str());
		}
	}
	ImGui::End();

}
