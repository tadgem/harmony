#pragma once

#include "Assets/Asset.h"

namespace harmony::GraphScript {
    class GraphScriptAsset {
    public:
        explicit GraphScriptAsset(Json graphScriptJson)
                : m_JSON(graphScriptJson) {
        };

        const Json m_JSON;
    };
}; // namespace harmony::GraphScripts