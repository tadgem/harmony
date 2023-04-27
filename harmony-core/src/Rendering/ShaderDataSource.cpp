#include "Rendering/ShaderDataSource.h"

harmony::ShaderDataSource::ShaderDataSource(const std::string &name) : m_Name(name) {

}

void harmony::ShaderDataSource::OnPreUpdate(entt::registry &registry, Ref<ShaderProgram> shader) {
}

void harmony::ShaderDataSource::OnPostUpdate(entt::registry &registry, Ref<ShaderProgram> shader) {
}
