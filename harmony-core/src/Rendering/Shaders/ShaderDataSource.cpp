#include <optick.h>
#include "Rendering/Shaders/ShaderDataSource.h"

harmony::ShaderDataSource::ShaderDataSource(const String &name) : m_Name(name) {
    OPTICK_EVENT();
}

void harmony::ShaderDataSource::OnPreUpdate(entt::registry &registry, RefCntPtr<ShaderProgram> shader) {
    OPTICK_EVENT();
}

void harmony::ShaderDataSource::OnPostUpdate(entt::registry &registry, RefCntPtr<ShaderProgram> shader) {
    OPTICK_EVENT();
}
