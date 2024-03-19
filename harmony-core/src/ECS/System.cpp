#include <optick.h>
#include "ECS/System.h"

harmony::String harmony::System::GetEntityKey(entt::entity &entity) {
    OPTICK_EVENT();
    uint32_t handle = static_cast<uint32_t>(entity);
    return ToString(handle);
}

entt::entity harmony::System::GetEntityFromKey(const String &key) {
    OPTICK_EVENT();
    uint32_t handle = stoul(key);
    return entt::entity(handle);
}
