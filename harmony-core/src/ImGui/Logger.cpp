#include <iostream>
#include "ImGui/Logger.h"
#include "ImGui/imgui.h"
#include "Core/Log.hpp"
#include "spdlog/sinks/callback_sink.h"
void harmony::ImGuiLogger::Init()
{
    auto console = spdlog::callback_logger_mt("callback", [&](const spdlog::details::log_msg & msg) {
       Message message;
       message.m_Msg = String(msg.payload.begin(), msg.payload.end());
       message.m_MsgLevel = msg.level;
       p_Stream.emplace_back(message);
    });
    spdlog::set_default_logger(console);
    harmony::log::info("Redirecting Output.");
}

void harmony::ImGuiLogger::Render() {

    if(ImGui::Begin("Console Log"))
    {
        for(auto msg : p_Stream)
        {
            ImGui::Text(msg.m_Msg.c_str());
        }
    }

    ImGui::End();

}
