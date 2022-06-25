#include "Assets/Asset.h"

harmony::Asset::Asset(AssetHandle handle) : m_Handle(handle)
{
}

bool harmony::AssetHandle::operator==(AssetHandle other)
{
	if (other.Index == Index && other.Path == Path && other.TypeHash == TypeHash)
	{
		return true;
	}
	return false;
}
