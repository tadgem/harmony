#include "ECS/TransformSystem.h"
#include "ECS/TransformComponent.h"
#include "Core/Memory.h"

#include "Core/Time.h"
#include "Core/Utils.h"
#include "Core/Log.hpp"
#include <mutex>
#include <execution>
#include <optick.h>
#include "Core/Thread.h"
#include "ECS/Entity.h"

void ValidateAngles(glm::vec3 &input)
{
	OPTICK_EVENT();

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
	OPTICK_EVENT();
}

void harmony::TransformSystem::Init(entt::registry &registry)
{
	OPTICK_EVENT();
	auto transformView = registry.view<TransformComponent>();
	glm::mat4 modelMatrix = glm::mat4(1.0);
	for (auto [entity, transform]: transformView.each())
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

void harmony::TransformSystem::Update(entt::registry &registry)
{

	OPTICK_EVENT();
}

void harmony::TransformSystem::Render(entt::registry &registry)
{
	OPTICK_EVENT();
	OPTICK_EVENT("Build Transform View");
	auto transformView = registry.view<EntityData, TransformComponent>();
	OPTICK_EVENT("Build group transform vectors");
	static const uint8_t NUM_GROUPS = 4;
	std::vector<TransformComponent *> transformGroups[NUM_GROUPS];
	size_t numTransforms = transformView.size_hint();
	uint32_t groupSize = numTransforms / NUM_GROUPS;

	if (transformView.size_hint() % NUM_GROUPS != 0)
	{
		groupSize++;
	}
	if (groupSize < MINIMUM_GROUP_SIZE)
	{
		groupSize = MINIMUM_GROUP_SIZE;
	}

	uint32_t groupIndex = 0;
	uint32_t groupCount = 0;
	uint32_t totalTransformsToProcess = 0;
	glm::mat4 modelMatrix = glm::mat4(1.0);
	for (auto [entity, data, transform]: transformView.each())
	{
		totalTransformsToProcess++;
		if (transform.Scale != transform.LastScale)
		{
			transform.UpdateCollision = true;
		}
		if (transform.Position != transform.LastPosition)
		{
			transform.UpdateCollision = true;
		}

		if (transform.Euler != transform.LastEuler)
		{
			transform.UpdateCollision = true;
		}

		transformGroups[groupIndex].push_back(&transform);

		groupCount++;

		if (groupCount >= groupSize)
		{
			groupIndex++;
			groupCount = 0;
		}
	}

	if (totalTransformsToProcess == 0)
	{
		return;
	}

	bool useMT = true;

	if (totalTransformsToProcess < groupSize)
	{
		useMT = false;
	}
	if (groupSize < MINIMUM_GROUP_SIZE)
	{
		useMT = false;
	}

	OPTICK_TAG("Number of transforms to process", totalTransformsToProcess);
	if (useMT)
	{
		OPTICK_EVENT("Build group lambdas")
		int emptyGroups = NUM_GROUPS - (groupIndex + 1);
		std::vector<std::future<void>> futures;
		for (int i = 0; i < NUM_GROUPS - emptyGroups; i++)
		{
			std::vector<TransformComponent *> tVec = transformGroups[i];
			futures.emplace_back(ThreadPool.submit(
					[tVec]()
					{
						for (int t = 0; t < tVec.size(); t++)
						{
							TransformComponent *transform = tVec[t];
							UpdateTransformComponent(transform);
						}
					}
			));
		}
		OPTICK_EVENT("Wait for futures to complete");
		for (int i = futures.size() - 1; i >= 0; i--)
		{
			futures[i].wait();
		}
	}
	else
	{
		const int FIRST_GROUP_INDEX = 0;
		OPTICK_EVENT("Too few transforms for threading, ST instead.")
		for (int i = 0; i < transformGroups[FIRST_GROUP_INDEX].size(); i++)
		{
			UpdateTransformComponent(transformGroups[FIRST_GROUP_INDEX][i]);
		}
	}

	Vector<glm::mat4> matrices;
	for (auto [entity, data, transform]: transformView.each())
	{
		matrices.clear();
		transform.LastPosition = transform.Position;
		transform.LastScale = transform.Scale;
		transform.LastEuler = transform.Euler;

		uint32_t parent = (uint32_t) data.m_Parent;

		while (parent != UINT32_MAX)
		{
			if (parent == UINT32_MAX)
			{
				break;
			}
			if(!registry.any_of<TransformComponent>((entt::entity)parent))
			{
				data.m_Parent = (entt::entity)UINT32_MAX;
				parent = (uint32_t) data.m_Parent;
				continue;
			}
			auto &t = registry.get<TransformComponent>((entt::entity) parent);
			auto &data = registry.get<EntityData>((entt::entity) parent);
			matrices.emplace_back(t.LocalModel);
			parent = (uint32_t) data.m_Parent;
		}
		if (matrices.empty())
		{
			transform.Model = transform.LocalModel;
			continue;
		}

		glm::mat4 m = matrices[matrices.size() - 1];

		for (int i = matrices.size() - 2; i >= 0; i--)
		{
			m *= matrices[i];
		}

		transform.Model = m * transform.LocalModel;

	}
}

void harmony::TransformSystem::Cleanup(entt::registry &registry)
{
	OPTICK_EVENT();
}

nlohmann::json harmony::TransformSystem::SerializeSystem(entt::registry &registry)
{
	OPTICK_EVENT();
	nlohmann::json j;
	auto view = registry.view<TransformComponent>();

	for (auto [e, t]: view.each())
	{
		j[GetEntityKey(e)] = t;
	}

	return j;
}

void harmony::TransformSystem::DeserializeSystem(entt::registry &registry, nlohmann::json systemJson)
{
	OPTICK_EVENT();
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
	OPTICK_EVENT();
}

void harmony::TransformSystem::CalculateDirectionVectors(glm::vec3 eulerDegrees, TransformComponent &transform)
{
	OPTICK_EVENT();
	// x = pitch, y = yaw, z = roll
	glm::vec3 eulerRadians = Utils::CalculateVec3Radians(eulerDegrees);
	glm::vec3 forward = glm::vec3(0.0);
	glm::vec3 right = glm::vec3(0.0);
	glm::vec3 up = glm::vec3(0.0);

	forward.x = glm::cos(eulerRadians.x) * glm::sin(eulerRadians.y);
	forward.y = -glm::sin(eulerRadians.x);
	forward.z = glm::cos(eulerRadians.x) * glm::cos(eulerRadians.y);

	right.x = glm::cos(eulerRadians.y);
	right.y = 0.0f;
	right.z = -glm::sin(eulerRadians.y);

	up.x = glm::sin(eulerRadians.x) * glm::sin(eulerRadians.y);
	up.y = glm::cos(eulerRadians.x);
	up.z = glm::sin(eulerRadians.x) * glm::cos(eulerRadians.y);

	transform.Forward = Utils::CalculateVec3Degrees(forward);
	transform.Right = Utils::CalculateVec3Degrees(right);
	transform.Up = Utils::CalculateVec3Degrees(up);

	transform.Forward = glm::normalize(transform.Forward);
	transform.Right = glm::normalize(transform.Right);
	transform.Up = glm::normalize(transform.Up);

}

void harmony::TransformSystem::UpdateTransformComponent(harmony::TransformComponent *transform)
{
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
		transform->LocalModel = finalMat;
		transform->Rotation = rot;
	}

	CalculateDirectionVectors(transform->Euler, *transform);
}
