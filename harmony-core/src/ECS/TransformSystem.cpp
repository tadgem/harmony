#include "ECS/TransformSystem.h"
#include "ECS/TransformComponent.h"
#include "Core/Memory.h"
#include "Core/Profile.hpp"
#include "Core/Time.h"
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
    
        transform.Rotation      = CalculateRotationQuat(transform.Euler);
        glm::mat4 localRotation = glm::mat4_cast(transform.Rotation);

        glm::mat4 localScale    = glm::mat4(1.0);
        localScale              = glm::scale(localScale, transform.Scale);
		transform.Model         = modelMatrix * localRotation * localScale;

        CalculateDirectionVectors(transform.Euler, transform);
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
        nlohmann::json transformJson = entry.value();
        TransformComponent tc;
        transformJson.get_to<TransformComponent>(tc);

        registry.emplace<TransformComponent>(e, tc);
    }
}

void harmony::TransformSystem::Refresh()
{
}

glm::vec3 harmony::TransformSystem::CalculateVec3Radians(glm::vec3 eulerDegrees)
{
    return glm::vec3(glm::radians(eulerDegrees.x), glm::radians(eulerDegrees.y), glm::radians(eulerDegrees.z));
}

glm::vec3 harmony::TransformSystem::CalculateVec3Degrees(glm::vec3 eulerRadians)
{
    return glm::vec3(glm::degrees(eulerRadians.x), glm::degrees(eulerRadians.y), glm::degrees(eulerRadians.z));
}

glm::quat harmony::TransformSystem::CalculateRotationQuat(glm::vec3 eulerDegrees)
{
    glm::vec3 eulerRadians = CalculateVec3Radians(eulerDegrees);

    glm::quat xRotation = glm::angleAxis(eulerRadians.x, glm::vec3(1, 0, 0));
    glm::quat yRotation = glm::angleAxis(eulerRadians.y, glm::vec3(0, 1, 0));
    glm::quat zRotation = glm::angleAxis(eulerRadians.z, glm::vec3(0, 0, 1));

    return zRotation * yRotation * xRotation;
}

void harmony::TransformSystem::CalculateDirectionVectors(glm::vec3 eulerDegrees, TransformComponent& transform)
{
    // x = pitch, y = yaw, z = roll
    glm::vec3 eulerRadians = CalculateVec3Radians(eulerDegrees);

    glm::vec3 forward   = glm::vec3(0.0);
    glm::vec3 right     = glm::vec3(0.0);
    glm::vec3 up        = glm::vec3(0.0);

    forward.x           = glm::cos(eulerRadians.x) * glm::sin(eulerRadians.y);
    forward.y           = -glm::sin(eulerRadians.x);
    forward.z           = glm::cos(eulerRadians.x) * glm::cos(eulerRadians.y);

    right.x             = glm::cos(eulerRadians.y);
    right.y             = 0.0f;
    right.z             = -glm::sin(eulerRadians.y);

    up.x                = glm::sin(eulerRadians.x) * glm::sin(eulerRadians.y);
    up.y                = glm::cos(eulerRadians.x);
    up.z                = glm::sin(eulerRadians.x) * glm::cos(eulerRadians.y);

    transform.Forward   = CalculateVec3Degrees(forward);
    transform.Right     = CalculateVec3Degrees(right);
    transform.Up        = CalculateVec3Degrees(up);

}