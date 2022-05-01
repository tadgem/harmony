#pragma once
#include "json.hpp"

namespace harmony
{
    class Asset
    {
    public:
        std::string m_AssetPath;
        size_t m_TypeHash;
        virtual ~Asset() {}
    };
};