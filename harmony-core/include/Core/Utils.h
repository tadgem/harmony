#pragma once
#include <string>
#include "ThirdParty/json.hpp"
#include "glm.hpp"
#include "glm/gtc/quaternion.hpp"

namespace harmony
{
    class Utils
    {
    public:
        static std::string LoadStringFromPath(const std::string& path);
        static nlohmann::json LoadJsonFromPath(const std::string& path);
        static void SaveStringToPath(const std::string& str, const std::string& path);
        static void SaveJsonToPath(nlohmann::json& json, const std::string& path);
        static std::vector<uint8_t> LoadBinaryFromPath(const std::string& path);
        static std::vector<uint8_t>* LoadBinaryFromPathHeap(const std::string& path);
        static std::string GetFilePathDirectory(const std::string& path);
        static int EncodeRGBA(char r, char g, char b, char a);
        static void TrimString(std::string& str);
        static float GetIntAsFloat(int i);
        static float GetUintAsFloat(unsigned int i);

        static glm::vec3 CalculateVec3Radians(glm::vec3 eulerDegrees);
        static glm::vec3 CalculateVec3Degrees(glm::vec3 eulerRadians);
        static glm::quat CalculateRotationQuat(glm::vec3 eulerDegrees);

        static std::string GetBgfxRendererName();
    };
};