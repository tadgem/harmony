#pragma once
#include "STL/Json.hpp"
#include "STL/String.h"
#include "Core/TypeDef.h"
#include "STL/Vector.h"
#include "glm.hpp"
#include "glm/gtc/quaternion.hpp"

namespace harmony {
    class Utils {
    public:
        static bool FileExists(const String &filepath);

        static String LoadStringFromPath(const String &path);

        static String GetCleanPlatformPath(const String &path);

        static Json LoadJsonFromPath(const String &path);

        static void SaveStringToPath(const String &str, const String &path);

        static void SaveJsonToPath(Json &json, const String &path);

        static Vector<uint8_t> LoadBinaryFromPath(const String &path);

        static Vector<uint8_t> *LoadBinaryFromPathHeap(const String &path);

        static String GetFilePathDirectory(const String &path);

        static int EncodeRGBA(char r, char g, char b, char a);

        static void TrimString(String &str);

        static float GetIntAsFloat(int i);

        static float GetUintAsFloat(unsigned int i);

        static glm::vec3 CalculateVec3Radians(glm::vec3 eulerDegrees);

        static glm::vec3 CalculateVec3Degrees(glm::vec3 eulerRadians);

        static glm::quat CalculateRotationQuat(glm::vec3 eulerDegrees);

        static String GetBgfxRendererName();
    };
};
