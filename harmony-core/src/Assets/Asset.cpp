#include "Assets/Asset.h"

harmony::Asset::Asset(AssetHandle handle) : m_Handle(handle)
{
}

harmony::AssetHandle::AssetHandle()
{
	Path = "";
	Index = UINT32_MAX;
	TypeHash = "";
}

harmony::AssetHandle::AssetHandle(std::string path, uint32_t index, std::string typeHash)
{
	Path = path;
	Index = index;
	TypeHash = typeHash;
}


bool harmony::AssetHandle::operator==(AssetHandle other)
{
	if (other.Index == Index && other.Path == Path && other.TypeHash == TypeHash)
	{
		return true;
	}
	return false;
}
