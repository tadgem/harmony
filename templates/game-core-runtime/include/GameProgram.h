#pragma once

#include "RuntimeProgram.h"

namespace harmony {
    class GameProgram : public RuntimeProgram {
    public:
        GameProgram();

        inline static const std::string GameName = "Game";
    };
}