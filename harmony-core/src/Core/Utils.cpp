#include "Core/Utils.h"

#include "STL/IO.h"
#include "STL/FileSystem.h"
#include "STL/Algorithm.h"
#include <optick.h>

#include "bx/platform.h"


harmony::String harmony::Utils::LoadStringFromPath(const String &path) {
    OPTICK_EVENT();
    String finalPath = GetCleanPlatformPath(path);

    IfStream inputFile = IfStream(finalPath, Ios::in | Ios::binary);

    if (!inputFile.is_open()) {
        return String();
    }

    if (!FileSystem::exists(finalPath)) {
        return String();
    }

    size_t fileSize = FileSystem::file_size(finalPath);
    String content(fileSize, '\0');
    inputFile.read(content.data(), fileSize);

    inputFile.close();
    return content;
}

harmony::Json harmony::Utils::LoadJsonFromPath(const String &path) {
    OPTICK_EVENT();
    String str = LoadStringFromPath(path);
    Json json = Json::parse(str);
    return json;
}

harmony::Vector<uint8_t> harmony::Utils::LoadBinaryFromPath(const String &path) {
    OPTICK_EVENT();

    IfStream binary_input_stream = IfStream(path, Ios::binary);
    Vector<uint8_t> data(IStreamBufIterator<char>(binary_input_stream), {});

    return data;
}

harmony::Vector<uint8_t> *harmony::Utils::LoadBinaryFromPathHeap(const String &path) {
    OPTICK_EVENT();

    IfStream binary_input_stream = IfStream(path, Ios::binary);
    auto data = new Vector<uint8_t>(IStreamBufIterator<char>(binary_input_stream), {});

    return data;
}

harmony::String harmony::Utils::GetFilePathDirectory(const String &path) {
    OPTICK_EVENT();
    size_t found = path.find_last_of("/\\");
    return path.substr(0, found);
}

int harmony::Utils::EncodeRGBA(char r, char g, char b, char a) {
    OPTICK_EVENT();
    return ((r << 24) | ((g & 255) << 16) | ((b & 255) << 8) | (a & 255));
}

void harmony::Utils::TrimString(String &str) {
    OPTICK_EVENT();
    str.erase(str.begin(), FindIf(str.begin(), str.end(), [](unsigned char ch) {
        return !(ch == ' ');
    }));
}

void harmony::Utils::SaveStringToPath(const String &str, const String &path) {
    OPTICK_EVENT();
    OfStream outputFile = OfStream(path);
    outputFile << str;
    outputFile.close();
}

void harmony::Utils::SaveJsonToPath(Json &json, const String &path) {
    OPTICK_EVENT();
    String jsonContent = json.dump();
    SaveStringToPath(jsonContent, path);

}

float harmony::Utils::GetIntAsFloat(int i) {
    OPTICK_EVENT();
    float f;
    memcpy(&f, &i, sizeof(float));

    return f;
}

float harmony::Utils::GetUintAsFloat(unsigned int i) {
    OPTICK_EVENT();
    float f;
    memcpy(&f, &i, sizeof(float));

    return f;
}

glm::vec3 harmony::Utils::CalculateVec3Radians(glm::vec3 eulerDegrees) {
    OPTICK_EVENT();
    return glm::vec3(glm::radians(eulerDegrees.x), glm::radians(eulerDegrees.y), glm::radians(eulerDegrees.z));
}

glm::vec3 harmony::Utils::CalculateVec3Degrees(glm::vec3 eulerRadians) {
    OPTICK_EVENT();
    return glm::vec3(glm::degrees(eulerRadians.x), glm::degrees(eulerRadians.y), glm::degrees(eulerRadians.z));
}

glm::quat harmony::Utils::CalculateRotationQuat(glm::vec3 eulerDegrees) {
    OPTICK_EVENT();
    glm::vec3 eulerRadians = CalculateVec3Radians(eulerDegrees);
    glm::quat xRotation = glm::angleAxis(eulerRadians.x, glm::vec3(1, 0, 0));
    glm::quat yRotation = glm::angleAxis(eulerRadians.y, glm::vec3(0, 1, 0));
    glm::quat zRotation = glm::angleAxis(eulerRadians.z, glm::vec3(0, 0, 1));

    return zRotation * yRotation * xRotation;
}

bool harmony::Utils::FileExists(const String &filepath) {
    OPTICK_EVENT();
    return FileSystem::exists(filepath);
}

harmony::String harmony::Utils::GetCleanPlatformPath(const String &path) {
    String finalPath = path;
#if !(BX_PLATFORM_WINDOWS)
    finalPath = "./" + path;
    const String find = "\\";
    const String replace = "/";

    String::size_type n = 0;
    while ( ( n = finalPath.find( find) ) != String::npos )
    {
        finalPath.replace( n, find.size(), replace );
        n += replace.size();
    }
#endif
    return finalPath;
}

