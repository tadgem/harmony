#pragma once
#include "json.hpp"

namespace harmony
{
    struct Asset
    {
        std::string m_AssetPath;
        size_t m_TypeHash;
        virtual ~Asset() {}
    };
};