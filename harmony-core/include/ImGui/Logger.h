#pragma once

#include "Core/Alias.h"
#include "Core/Log.hpp"
#include "spdlog/logger.h"
#include "ImGui/imgui.h"

namespace harmony
{
	class ImGuiLogger
	{
	public:

		struct Message
		{
			String m_Msg;
			log::level::level_enum m_MsgLevel;
			size_t m_ThreadID;
			long long m_Time;
		};
		struct LevelInfo
		{
			String m_LevelName;
			ImVec4 m_LevelColour;
		};
		ImGuiLogger() = default;
		void Init();
		void Render();

	private:
		int NUM_ELEMENTS_CLIP = 16;
		Vector<Message> p_Stream;
		HashMap<log::level::level_enum, LevelInfo> p_LevelInfos;
	};
}