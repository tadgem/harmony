#include <iostream>
#include "ImGui/Logger.h"
#include "ImGui/imgui.h"
#include "Core/Log.hpp"
#include "spdlog/sinks/callback_sink.h"
void harmony::ImGuiLogger::Init()
{
    p_LevelInfos.emplace(log::level::level_enum::info, LevelInfo{"Info", ImVec4(0.0f, 255.0f, 0.0f, 255.0f)});
    p_LevelInfos.emplace(log::level::level_enum::warn, LevelInfo{"Warn", ImVec4(255.0f, 255.0f, 0.0f, 255.0f)});
    p_LevelInfos.emplace(log::level::level_enum::err, LevelInfo{"Error", ImVec4(255.0f, 0.0f, 0.0f, 255.0f)});
    p_LevelInfos.emplace(log::level::level_enum::debug, LevelInfo{"Debug", ImVec4(0.0f, 0.0f, 255.0f, 255.0f)});
    p_LevelInfos.emplace(log::level::level_enum::trace, LevelInfo{"Trace", ImVec4(0.0f, 255.0f, 255.0f, 255.0f)});
    p_LevelInfos.emplace(log::level::level_enum::critical, LevelInfo{"Critical", ImVec4(255.0f, 0.0f, 0.0f, 255.0f)});

    auto console = spdlog::callback_logger_mt("callback", [&](const spdlog::details::log_msg & msg) {
       Message message;
       message.m_Msg = String(msg.payload.begin(), msg.payload.end());
       message.m_MsgLevel = msg.level;
       message.m_ThreadID = msg.thread_id;
       message.m_Time = msg.time.time_since_epoch().count();
       p_Stream.emplace_back(message);
    });
    spdlog::set_default_logger(console);
    harmony::log::info("Redirecting Output.");
}

void harmony::ImGuiLogger::Render() {

    bool show = true;
    if(ImGui::Begin("Console Log", &show,  ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse))
    {
        ImVec2 currentWindowSize = ImGui::GetWindowSize();
        float textHeight = ImGui::GetTextLineHeightWithSpacing();
        ImGuiTableFlags flags = ImGuiTableFlags_ScrollY | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_NoKeepColumnsVisible;
        ImVec2 outer_size = ImVec2(0.0f, 0.0f);

        int rounded = ((int) currentWindowSize.y / textHeight) - 3;
        for(int i = 0; i < rounded; i++)
        {
            outer_size.y += textHeight;
        }

        if(ImGui::BeginTable("Console", 4, flags, outer_size))
        {
            ImGui::TableSetupColumn("ThreadID", ImGuiTableColumnFlags_NoHide);
            ImGui::TableSetupColumn("Time", ImGuiTableColumnFlags_NoHide);
            ImGui::TableSetupColumn("Level", ImGuiTableColumnFlags_NoHide);
            ImGui::TableSetupColumn("Message", ImGuiTableColumnFlags_NoHide);

            ImGui::TableSetupScrollFreeze(0, 1);

            ImGui::TableHeadersRow();

            // ThreadID : Time : Level : Message
            for(auto msg : p_Stream)
            {
                ImVec4 col = p_LevelInfos[msg.m_MsgLevel].m_LevelColour;
                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);
                ImGui::Text(std::to_string(msg.m_ThreadID).c_str());
                ImGui::TableSetColumnIndex(1);
                ImGui::Text(std::to_string(msg.m_Time).c_str());
                ImGui::TableSetColumnIndex(2);
                ImGui::TextColored(col,p_LevelInfos[msg.m_MsgLevel].m_LevelName.c_str());
                ImGui::TableSetColumnIndex(3);
                ImGui::TextColored(col, msg.m_Msg.c_str());
            }

            ImGui::EndTable();
            if(ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
            {
                ImGui::SetScrollHereY(1.0f);
            }
        }
    }

    ImGui::End();

}
