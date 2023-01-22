#include "Profiler.h"

void harmony::ProfilerPanel::OnImGui()
{

	if (ImGui::Begin("Profiler"))
	{
		uint64_t alc = Memory::GetAllocatedMemory();
		uint64_t fre = Memory::GetFreedMemory();
		float mbs = (((float)alc-fre) / (1024.0f)) / 1024.0f;

		ImGui::Text("CPU Memory : %f MB", mbs);

		ImGui::Separator();
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
