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
