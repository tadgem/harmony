#include "ECS/TransformSystem.h"
#include "ECS/TransformComponent.h"
#include "Core/Memory.h"
#include "Core/Profile.hpp"
#include "Core/Time.h"
#include "Core/Utils.h"
#include "Core/Log.hpp"
#include <mutex>
#include <execution>
#include "Core/Thread.h"


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

harmony::TransformSystem::TransformSystem() : System(GetTypeHash<TransformSystem>())
{
}

void harmony::TransformSystem::Init(entt::registry& registry)
{
    auto transformView = registry.view<TransformComponent>();
    glm::mat4 modelMatrix = glm::mat4(1.0);
    for (auto [entity, transform] : transformView.each())
    {
        modelMatrix = glm::mat4(1.0);
        modelMatrix = glm::translate(modelMatrix, transform.Position);
        ValidateAngles(transform.Euler);

        transform.Rotation = Utils::CalculateRotationQuat(transform.Euler);
        glm::mat4 localRotation = glm::mat4_cast(transform.Rotation);

        glm::mat4 localScale = glm::mat4(1.0);
        localScale = glm::scale(localScale, transform.Scale);
        transform.Model = modelMatrix * localRotation * localScale;

        CalculateDirectionVectors(transform.Euler, transform);

        transform.UpdateCollision = true;
    }
}


static std::mutex s_TransformMutex;

void harmony::TransformSystem::Update(entt::registry& registry)
{
    HARMONY_PROFILE_FUNCTION()
	
}

void harmony::TransformSystem::Render(entt::registry& registry)
{
    HARMONY_PROFILE_FUNCTION()
    auto transformView = registry.view<TransformComponent>();
#define MT_IMPL
#ifdef MT_IMPL

    static const uint8_t NUM_GROUPS = 4;
    std::vector<TransformComponent*> transformGroups[NUM_GROUPS];
    size_t numTransforms = transformView.size();
    uint32_t groupSize = numTransforms / NUM_GROUPS;
    if (transformView.size() % NUM_GROUPS != 0)
    {
        groupSize++;
    }
    uint32_t groupIndex = 0;
    uint32_t groupCount = 0;

    glm::mat4 modelMatrix = glm::mat4(1.0);
    for (auto [entity, transform] : transformView.each())
    {
        if (transform.Position == transform.LastPosition &&
            transform.Euler == transform.LastEuler &&
            transform.Scale == transform.LastScale)
        {
            continue;
        }
        transform.UpdateCollision = true;
        transformGroups[groupIndex].push_back(&transform);

        groupCount++;

        if (groupCount >= groupSize)
        {
            groupIndex++;
            groupCount = 0;
        }
    }
    std::vector<std::future<void>> futures;
    for (int i = 0; i < NUM_GROUPS; i++)
    {
        std::vector<TransformComponent*> tVec = transformGroups[i];
        futures.emplace_back(ThreadPool.submit(
            [tVec]()
            {
                for (int t = 0; t < tVec.size(); t++)
                {
                    TransformComponent* transform = tVec[t];
                    glm::mat4 modelMatrix = glm::mat4(1.0);
                    glm::vec3 pos = glm::vec3(0.0);
                    glm::vec3 eul = glm::vec3(0.0);
                    glm::vec3 scl = glm::vec3(0.0);

                    {
                        pos = transform->Position;
                        eul = transform->Euler;
                        scl = transform->Scale;
                    }

                    modelMatrix = glm::translate(modelMatrix, pos);
                    ValidateAngles(eul);
                    glm::quat rot = Utils::CalculateRotationQuat(eul);
                    glm::mat4 localRotation = glm::mat4_cast(rot);
                    glm::mat4 localScale = glm::mat4(1.0);
                    localScale = glm::scale(localScale, scl);
                    glm::mat4 finalMat = modelMatrix * localRotation * localScale;

                    {
                        transform->Model = finalMat;
                        transform->Rotation = rot;
                    }

                    CalculateDirectionVectors(transform->Euler, *transform);
                }
            }
        ));
    }

    while (futures.size() > 0)
    {
        for (int i = futures.size() - 1; i >= 0; i--)
        {
            if (is_ready<void>(futures[i]))
            {
                futures.erase(futures.begin() + i);
            }
        }
    }
#else
    glm::mat4 modelMatrix = glm::mat4(1.0);
    for (auto [entity, transform] : transformView.each())
    {
        modelMatrix = glm::mat4(1.0);
        modelMatrix = glm::translate(modelMatrix, transform.Position);
        ValidateAngles(transform.Euler);

        transform.Rotation = Utils::CalculateRotationQuat(transform.Euler);
        glm::mat4 localRotation = glm::mat4_cast(transform.Rotation);

        glm::mat4 localScale = glm::mat4(1.0);
        localScale = glm::scale(localScale, transform.Scale);
        transform.Model = modelMatrix * localRotation * localScale;

        CalculateDirectionVectors(transform.Euler, transform);
        }
#endif
    for (auto [entity, transform] : transformView.each())
    {
        transform.LastPosition = transform.Position;
        transform.LastScale = transform.Scale;
        transform.LastEuler = transform.Euler;
    }
}

void harmony::TransformSystem::Cleanup(entt::registry& registry)
{
    HARMONY_PROFILE_FUNCTION()
}

nlohmann::json harmony::TransformSystem::SerializeSystem(entt::registry& registry)
{
    HARMONY_PROFILE_FUNCTION()
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
    HARMONY_PROFILE_FUNCTION()
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

void harmony::TransformSystem::CalculateDirectionVectors(glm::vec3 eulerDegrees, TransformComponent& transform)
{
    HARMONY_PROFILE_FUNCTION()
    // x = pitch, y = yaw, z = roll
    glm::vec3 eulerRadians = Utils::CalculateVec3Radians(eulerDegrees);

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

    transform.Forward   = Utils::CalculateVec3Degrees(forward);
    transform.Right     = Utils::CalculateVec3Degrees(right);
    transform.Up        = Utils::CalculateVec3Degrees(up);

    transform.Forward = glm::normalize(transform.Forward);
    transform.Right = glm::normalize(transform.Right);
    transform.Up = glm::normalize(transform.Up);

}