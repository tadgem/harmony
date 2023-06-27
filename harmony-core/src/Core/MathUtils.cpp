#include <optick.h>
#include "Core/MathsUtils.h"

glm::vec3 harmony::MathsUtils::CalculateForwardVector(const glm::vec3 &euler)
{
	OPTICK_EVENT();
	// pitch = x
	// yaw = y
	// (cos(pitch)cos(yaw), cos(pitch)sin(yaw), sin(pitch))
	return glm::vec3(
			glm::cos(glm::radians(euler.x)) * glm::cos(glm::radians(euler.y)),
			glm::cos(glm::radians(euler.x)) * glm::sin(glm::radians(euler.y)),
			glm::sin(glm::radians(euler.x))
	);
}

glm::vec3 harmony::MathsUtils::CalculateRightVector(const glm::vec3 &euler)
{
	OPTICK_EVENT();
	// pitch = x
	// yaw = y
	// (cos(yaw), 0.0, -sin(yaw))
	return glm::vec3(
			glm::cos(glm::radians(euler.x)),
			0.0f,
			-glm::sin(glm::radians(euler.x))
	);
}

glm::vec3 harmony::MathsUtils::CalculateUpVector(const glm::vec3 &forward, const glm::vec3 &right)
{
	OPTICK_EVENT();
	return glm::cross(forward, right);
}

glm::vec3 harmony::MathsUtils::CalculateForwardVector(const glm::quat &rot)
{
	OPTICK_EVENT();
	return glm::rotate(glm::inverse(rot), glm::vec3(0.0, 0.0, -1.0));
}

glm::vec3 harmony::MathsUtils::CalculateRightVector(const glm::quat &rot)
{
	OPTICK_EVENT();
	return glm::rotate(glm::inverse(rot), glm::vec3(1.0, 0.0, 0.0));
}

glm::vec3 harmony::MathsUtils::CalculateUpVector(const glm::quat &rot)
{
	OPTICK_EVENT();
	return glm::vec3(0.0, 1.0, 0.0);
}
