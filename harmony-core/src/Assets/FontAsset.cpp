#include <optick.h>
#include "Assets/FontAsset.h"

harmony::FontAsset::FontAsset(AssetHandle &handle)
{
	OPTICK_EVENT();
	m_Handle = handle;
}

harmony::FontAsset::FontAsset()
{
	OPTICK_EVENT();
}
