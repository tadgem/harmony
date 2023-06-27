#include <optick.h>
#include "Rendering/Shaders/ShaderDataSource.h"

harmony::ShaderDataSource::ShaderDataSource(const std::string &name) : m_Name(name)
{
	OPTICK_EVENT();
}

void harmony::ShaderDataSource::OnPreUpdate(entt::registry &registry, Ref<ShaderProgram> shader)
{
	OPTICK_EVENT();
}

void harmony::ShaderDataSource::OnPostUpdate(entt::registry &registry, Ref<ShaderProgram> shader)
{
	OPTICK_EVENT();
}
