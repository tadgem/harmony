#include "Core/Utils.h"
#include <fstream>
#include <filesystem>
#include "Core/Profile.hpp"
#include "bgfx/bgfx.h"
std::string harmony::Utils::LoadStringFromPath(const std::string& path)
{
	HARMONY_PROFILE_FUNCTION()
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

nlohmann::json harmony::Utils::LoadJsonFromPath(const std::string& path)
{
	HARMONY_PROFILE_FUNCTION()
	std::string str = LoadStringFromPath(path);
	nlohmann::json json = nlohmann::json::parse(str);
	return json;
}

std::vector<uint8_t> harmony::Utils::LoadBinaryFromPath(const std::string& path)
{
	HARMONY_PROFILE_FUNCTION()

	std::ifstream binary_input_stream = std::ifstream(path, std::ios::binary);
	std::vector<uint8_t> data(std::istreambuf_iterator<char>(binary_input_stream), {});

	return data;
}
std::vector<uint8_t>* harmony::Utils::LoadBinaryFromPathHeap(const std::string& path)
{
	HARMONY_PROFILE_FUNCTION()

	std::ifstream binary_input_stream = std::ifstream(path, std::ios::binary);
	auto data = new std::vector<uint8_t>(std::istreambuf_iterator<char>(binary_input_stream), {});

	return data;
}
std::string harmony::Utils::GetFilePathDirectory(const std::string& path)
{
	std::size_t found = path.find_last_of("/\\");
	return path.substr(0, found);
}
int harmony::Utils::EncodeRGBA(char r, char g, char b, char a)
{
	HARMONY_PROFILE_FUNCTION()
	return ((r << 24) | ((g & 255) << 16) | ((b & 255) << 8) | (a & 255));
}
void harmony::Utils::TrimString(std::string& str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
		return !std::isspace(ch);
		}));
}
void harmony::Utils::SaveStringToPath(const std::string& str, const std::string& path)
{
	HARMONY_PROFILE_FUNCTION()
	std::ofstream outputFile = std::ofstream(path);
	outputFile << str;
	outputFile.close();
}

void harmony::Utils::SaveJsonToPath(nlohmann::json& json, const std::string& path)
{
	HARMONY_PROFILE_FUNCTION()
	std::string jsonContent = json.dump();
	SaveStringToPath(jsonContent, path);

}

float harmony::Utils::GetIntAsFloat(int i)
{
	float f;
	memcpy(&f, &i, sizeof(float));

	return f;
}

float harmony::Utils::GetUintAsFloat(unsigned int i)
{
	float f;
	memcpy(&f, &i, sizeof(float));

	return f;
}