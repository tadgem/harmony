#pragma once

#include <utility>
#include "Assets/Asset.h"

namespace harmony::GraphScript
{
    class GraphScriptAsset
    {
    public:
        explicit GraphScriptAsset(nlohmann::json graphScriptJson) : m_JSON(std::move(graphScriptJson)) {};

        const nlohmann::json m_JSON;
    };
};