#pragma once

#include "Assets/Asset.h"
#include <utility>

namespace harmony::GraphScript {
    class GraphScriptAsset {
    public:
        explicit GraphScriptAsset(Json graphScriptJson)
                : m_JSON(std::move(graphScriptJson)) {
        };

        const Json m_JSON;
    };
}; // namespace harmony::GraphScript