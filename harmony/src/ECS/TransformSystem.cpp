#include "ECS/TransformSystem.h"
#include "ECS/TransformComponent.h"
#include "Core/Memory.h"
#include "Core/Profile.hpp"
harmony::TransformSystem::TransformSystem() : System(GetTypeHash<TransformSystem>())
{
}

void harmony::TransformSystem::Init(entt::registry& registry)
{
}

void ValidateAngles(glm::vec3& input)
{
    HARMONY_PROFILE_FUNCTION()
    // need to perform these checks to avoid NaN values creating invalid model matrices.
    // tradeoff is that transform values are only accurate to 4 decimal places...
    // could cause jitteriness at high framerates in some cases
    if (input.x <= 0.0001f && input.x >= 0.0001f)
    {
        input.x += 0.0001f;
    }

    if (input.y <= 0.0001f && input.y >= 0.0001f)
    {
        input.y += 0.0001f;
    }

    if (input.z <= 0.0001f && input.z >= 0.0001f)
    {
        input.z += 0.0001f;
    }
}

void harmony::TransformSystem::Update(entt::registry& registry)
{
	auto transformView = registry.view<TransformComponent>();
	glm::mat4 modelMatrix = glm::mat4(1.0);

	for (auto [entity, transform] : transformView.each())
	{
		modelMatrix = glm::mat4(1.0);
		modelMatrix = glm::translate(modelMatrix, transform.Position);

        ValidateAngles(transform.Euler);
        glm::vec3 eulerRadians = glm::vec3(glm::radians(transform.Euler.x), glm::radians(transform.Euler.y), glm::radians(transform.Euler.z));

        glm::quat xRotation = glm::angleAxis(eulerRadians.x, glm::vec3(1, 0, 0));
        glm::quat yRotation = glm::angleAxis(eulerRadians.y, glm::vec3(0, 1, 0));
        glm::quat zRotation = glm::angleAxis(eulerRadians.z, glm::vec3(0, 0, 1));

        transform.Rotation = xRotation * yRotation * zRotation;
        glm::mat4 localRotation = glm::mat4_cast(transform.Rotation);

        glm::mat4 localScale = glm::mat4(1.0);
        localScale = glm::scale(localScale, transform.Scale);
		transform.Model = modelMatrix * localRotation * localScale;
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
    nlohmann::json j;

    auto view = registry.view<TransformComponent>();

    for (auto [e, t] : view.each())
    {
        j[GetEntityKey(e)] = t;
    }

    return j;
}

void harmony::TransformSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
    for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++)
    {
        entt::entity e = GetEntityFromKey(entry.key());
        TransformComponent tc = entry.value();

        registry.emplace<TransformComponent>(e, tc);
    }
}

void harmony::TransformSystem::Refresh()
{
}
