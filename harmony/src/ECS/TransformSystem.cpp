#include "ECS/TransformSystem.h"
#include "ECS/TransformComponent.h"

harmony::TransformSystem::TransformSystem()
{
}

void harmony::TransformSystem::Init(entt::registry& registry)
{
}

void harmony::TransformSystem::Update(entt::registry& registry)
{
	auto transformView = registry.view<TransformComponent>();
	glm::mat4 modelMatrix = glm::mat4(1.0);

	for (auto& [entity, transform] : transformView.each())
	{
		modelMatrix = glm::mat4(1.0);
		modelMatrix = glm::translate(modelMatrix, transform.Position);
		
		transform.Model = modelMatrix;
	}
}

void harmony::TransformSystem::Render(entt::registry& registry)
{
}

void harmony::TransformSystem::Cleanup(entt::registry& registry)
{
}

nlohmann::json harmony::TransformSystem::SerializeSystem(entt::registry& registry)
{
	return nlohmann::json();
}

void harmony::TransformSystem::DeserializeSystem(entt::registry registry)
{
}
