#include "Core/Utils.h"
#include <fstream>
#include <filesystem>
#include <optick.h>

#include "bgfx/bgfx.h"

std::string harmony::Utils::LoadStringFromPath(const std::string &path)
{
	OPTICK_EVENT();
	std::string finalPath = path;
#if BX_PLATFORM_LINUX
	finalPath = "./" + path;
#endif

	std::ifstream inputFile = std::ifstream(finalPath, std::ios::in | std::ios::binary);

	if (!inputFile.is_open())
	{
		return std::string();
	}

	size_t fileSize = std::filesystem::file_size(path);
	std::string content(fileSize, '\0');
	inputFile.read(content.data(), fileSize);

	inputFile.close();
	return content;
}

nlohmann::json harmony::Utils::LoadJsonFromPath(const std::string &path)
{
	OPTICK_EVENT();
	std::string str = LoadStringFromPath(path);
	nlohmann::json json = nlohmann::json::parse(str);
	return json;
}

std::vector<uint8_t> harmony::Utils::LoadBinaryFromPath(const std::string &path)
{
	OPTICK_EVENT();

	std::ifstream binary_input_stream = std::ifstream(path, std::ios::binary);
	std::vector<uint8_t> data(std::istreambuf_iterator<char>(binary_input_stream), {});

	return data;
}

std::vector<uint8_t> *harmony::Utils::LoadBinaryFromPathHeap(const std::string &path)
{
	OPTICK_EVENT();

	std::ifstream binary_input_stream = std::ifstream(path, std::ios::binary);
	auto data = new std::vector<uint8_t>(std::istreambuf_iterator<char>(binary_input_stream), {});

	return data;
}

std::string harmony::Utils::GetFilePathDirectory(const std::string &path)
{
	OPTICK_EVENT();
	std::size_t found = path.find_last_of("/\\");
	return path.substr(0, found);
}

int harmony::Utils::EncodeRGBA(char r, char g, char b, char a)
{
	OPTICK_EVENT();
	return ((r << 24) | ((g & 255) << 16) | ((b & 255) << 8) | (a & 255));
}

void harmony::Utils::TrimString(std::string &str)
{
	OPTICK_EVENT();
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch)
	{
		return !std::isspace(ch);
	}));
}

void harmony::Utils::SaveStringToPath(const std::string &str, const std::string &path)
{
	OPTICK_EVENT();
	std::ofstream outputFile = std::ofstream(path);
	outputFile << str;
	outputFile.close();
}

void harmony::Utils::SaveJsonToPath(nlohmann::json &json, const std::string &path)
{
	OPTICK_EVENT();
	std::string jsonContent = json.dump();
	SaveStringToPath(jsonContent, path);

}

float harmony::Utils::GetIntAsFloat(int i)
{
	OPTICK_EVENT();
	float f;
	memcpy(&f, &i, sizeof(float));

	return f;
}

float harmony::Utils::GetUintAsFloat(unsigned int i)
{
	OPTICK_EVENT();
	float f;
	memcpy(&f, &i, sizeof(float));

	return f;
}

glm::vec3 harmony::Utils::CalculateVec3Radians(glm::vec3 eulerDegrees)
{
	OPTICK_EVENT();
	return glm::vec3(glm::radians(eulerDegrees.x), glm::radians(eulerDegrees.y), glm::radians(eulerDegrees.z));
}

glm::vec3 harmony::Utils::CalculateVec3Degrees(glm::vec3 eulerRadians)
{
	OPTICK_EVENT();
	return glm::vec3(glm::degrees(eulerRadians.x), glm::degrees(eulerRadians.y), glm::degrees(eulerRadians.z));
}

glm::quat harmony::Utils::CalculateRotationQuat(glm::vec3 eulerDegrees)
{
	OPTICK_EVENT();
	glm::vec3 eulerRadians = CalculateVec3Radians(eulerDegrees);
	glm::quat xRotation = glm::angleAxis(eulerRadians.x, glm::vec3(1, 0, 0));
	glm::quat yRotation = glm::angleAxis(eulerRadians.y, glm::vec3(0, 1, 0));
	glm::quat zRotation = glm::angleAxis(eulerRadians.z, glm::vec3(0, 0, 1));

	return zRotation * yRotation * xRotation;
}

bool harmony::Utils::FileExists(const std::string &filepath)
{
	OPTICK_EVENT();
	return std::filesystem::exists(filepath);
}
