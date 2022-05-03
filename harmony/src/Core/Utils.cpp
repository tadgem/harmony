#include "Core/Utils.h"
#include <fstream>
#include <filesystem>

std::string harmony::Utils::LoadStringFromPath(const std::string& path)
{
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
	std::string str = LoadStringFromPath(path);
	nlohmann::json json = str;
	return str;
}

void harmony::Utils::SaveStringToPath(const std::string& str, const std::string& path)
{
	std::ofstream outputFile = std::ofstream(path);
	outputFile << str;
	outputFile.close();
}

void harmony::Utils::SaveJsonToPath(nlohmann::json& json, const std::string& path)
{
	std::string jsonContent = json.dump();
	SaveStringToPath(jsonContent, path);

}
