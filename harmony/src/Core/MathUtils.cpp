#include "Core/MathsUtils.h"

glm::vec3 harmony::MathsUtils::CalculateForwardVector(const glm::vec3& euler)
{
	// pitch = x
	// yaw = y
	// (cos(pitch)cos(yaw), cos(pitch)sin(yaw), sin(pitch))
	return glm::vec3(
		glm::cos(glm::radians(euler.x)) * glm::sin(glm::radians(euler.y)),
		-glm::sin(glm::radians(euler.x)),
		glm::cos(glm::radians(euler.x) * glm::cos(glm::radians(euler.y)))
		);
}

glm::vec3 harmony::MathsUtils::CalculateRightVector(const glm::vec3& euler)
{
	// pitch = x
	// yaw = y
	// (cos(yaw), 0.0, -sin(yaw))
	return glm::vec3(
		glm::cos(glm::radians(euler.x)),
		0.0f,
		-glm::sin(glm::radians(euler.x))
	);
}

glm::vec3 harmony::MathsUtils::CalculateUpVector(const glm::vec3& forward, const glm::vec3& right)
{
	return glm::cross(forward, right);
}