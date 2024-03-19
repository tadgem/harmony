#include <iostream>
#include "ImGui/Logger.h"
#include "ImGui/imgui.h"
#include "Core/Log.hpp"
#include "spdlog/sinks/callback_sink.h"

void harmony::ImGuiLogger::Init() {
    p_LevelInfos.emplace(log::level::level_enum::info, LevelInfo{"Info", ImVec4(0.0f, 255.0f, 0.0f, 255.0f)});
    p_LevelInfos.emplace(log::level::level_enum::warn, LevelInfo{"Warn", ImVec4(255.0f, 255.0f, 0.0f, 255.0f)});
    p_LevelInfos.emplace(log::level::level_enum::err, LevelInfo{"Error", ImVec4(255.0f, 0.0f, 0.0f, 255.0f)});
    p_LevelInfos.emplace(log::level::level_enum::debug, LevelInfo{"Debug", ImVec4(0.0f, 0.0f, 255.0f, 255.0f)});
    p_LevelInfos.emplace(log::level::level_enum::trace, LevelInfo{"Trace", ImVec4(0.0f, 255.0f, 255.0f, 255.0f)});
    p_LevelInfos.emplace(log::level::level_enum::critical, LevelInfo{"Critical", ImVec4(255.0f, 0.0f, 0.0f, 255.0f)});

    auto console = spdlog::callback_logger_mt("callback", [&](const spdlog::details::log_msg &msg) {
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
    if (ImGui::Begin("Console Log", &show,
                     ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar |
                     ImGuiWindowFlags_NoScrollWithMouse)) {
        ImVec2 currentWindowSize = ImGui::GetWindowContentRegionMax();
        float textHeight = ImGui::GetTextLineHeightWithSpacing();
        ImGuiTableFlags flags =
                ImGuiTableFlags_ScrollY | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable;
        ImVec2 outer_size = ImVec2(0.0f, 0.0f);
        const int rounded = static_cast<int>( currentWindowSize.y / textHeight - 2);
        for (int i = 0; i < rounded; i++) {
            outer_size.y += textHeight;
        }

        if (outer_size.y >= currentWindowSize.y) {
            outer_size.y = currentWindowSize.y;
        }

        if (ImGui::BeginTable("Console", 4, flags, outer_size)) {
            ImGui::TableSetupColumn("ThreadID", ImGuiTableColumnFlags_NoHide);
            ImGui::TableSetupColumn("Time", ImGuiTableColumnFlags_NoHide);
            ImGui::TableSetupColumn("Level", ImGuiTableColumnFlags_NoHide);
            ImGui::TableSetupColumn("Message", ImGuiTableColumnFlags_NoHide | ImGuiTableColumnFlags_WidthStretch);

            ImGui::TableSetupScrollFreeze(0, 1);

            ImGui::TableHeadersRow();

            static const int LOG_ENTRY_LIMIT = 200;
            int streamSize = p_Stream.size();
            int startIndex = streamSize - LOG_ENTRY_LIMIT;
            if (startIndex < 0) {
                startIndex = 0;
            }

            // ThreadID : Time : Level : Message
            for (int i = startIndex; i < streamSize; i++) {
                auto &msg = p_Stream[i];
                ImVec4 col = p_LevelInfos[msg.m_MsgLevel].m_LevelColour;
                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);
                ImGui::Text(ToString(msg.m_ThreadID).c_str());
                ImGui::TableSetColumnIndex(1);
                ImGui::Text(ToString(msg.m_Time).c_str());
                ImGui::TableSetColumnIndex(2);
                ImGui::TextColored(col, p_LevelInfos[msg.m_MsgLevel].m_LevelName.c_str());
                ImGui::TableSetColumnIndex(3);
                ImGui::TextUnformatted(msg.m_Msg.c_str());
            }

            auto scroll_y = ImGui::GetScrollY();
            auto max_y = ImGui::GetScrollMaxY();
            if (scroll_y >= max_y) {
                ImGui::SetScrollHereY(1.0f);
            }

            ImGui::EndTable();
        }
    }

    ImGui::End();

}
