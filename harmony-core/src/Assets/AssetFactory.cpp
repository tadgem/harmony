#include <optick.h>
#include "Assets/AssetFactory.h"

void harmony::AssetFactory::ClearLoadedData()
{
	OPTICK_EVENT();
	p_Assets.clear();
}
