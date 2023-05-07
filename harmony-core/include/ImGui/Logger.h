#pragma once
#include "Core/Alias.h"
#include "Core/Log.hpp"
#include "spdlog/logger.h"

namespace harmony
{
    class ImGuiLogger
    {
    public:

        struct Message {
            String m_Msg;
            harmony::log::level::level_enum m_MsgLevel;
        };

        ImGuiLogger() = default;

        void Init();
        void Render();

    private:
        Vector<Message> p_Stream;

    };
}