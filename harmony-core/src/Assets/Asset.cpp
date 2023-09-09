#include "Assets/Asset.h"
#include "optick.h"

harmony::Asset::Asset(AssetHandle handle) : m_Handle(handle) {
}

harmony::AssetHandle::AssetHandle() {
    OPTICK_EVENT();
    Path = "";
    Index = UINT32_MAX;
    TypeHash = GetTypeHash<AssetHandle>();
}

harmony::AssetHandle::AssetHandle(std::string path, uint32_t index, HashString typeHash) {
    OPTICK_EVENT();
    Path = path;
    Index = index;
    TypeHash = typeHash;
}

bool harmony::AssetHandle::operator==(AssetHandle other) {
    OPTICK_EVENT();
    if (other.Index == Index && other.Path == Path && other.TypeHash == TypeHash) {
        return true;
    }
    return false;
}
