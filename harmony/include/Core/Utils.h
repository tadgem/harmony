#pragma once
#include <string>
#include "json.hpp"
namespace harmony
{
    class Utils
    {
    public:
        static std::string LoadStringFromPath(const std::string& path);
        static nlohmann::json LoadJsonFromPath(const std::string& path);
        static void SaveStringToPath(const std::string& str, const std::string& path);
        static void SaveJsonToPath(nlohmann::json& json, const std::string& path);
    };
};