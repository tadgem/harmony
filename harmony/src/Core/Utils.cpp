#include "Core/Utils.h"
#include <fstream>
#include <filesystem>
#include "Core/Profile.hpp"

std::string harmony::Utils::LoadStringFromPath(const std::string& path)
{
	HARMONY_PROFILE_FUNCTION()
	std::ifstream inputFile = std::ifstream(path, std::ios::in | std::ios::binary);

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
int harmony::Utils::EncodeRGBA(char r, char g, char b, char a)
{
	HARMONY_PROFILE_FUNCTION()
	return ((r << 24) | ((g & 255) << 16) | ((b & 255) << 8) | (a & 255));
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
