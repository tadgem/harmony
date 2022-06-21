#include "Core/MathsUtils.h"

glm::vec3 harmony::MathsUtils::CalculateForwardVector(const glm::vec3& euler)
{
	// pitch = x
	// yaw = y
	// (cos(pitch)cos(yaw), cos(pitch)sin(yaw), sin(pitch))
	return glm::vec3(
		glm::cos(glm::radians(euler.x)) * glm::cos(glm::radians(euler.y)),
		glm::cos(glm::radians(euler.x)) * glm::sin(glm::radians(euler.y)),
		glm::sin(glm::radians(euler.x))
		);
}