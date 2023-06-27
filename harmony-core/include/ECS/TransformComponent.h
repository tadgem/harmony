#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "ThirdParty/json.hpp"

#include "Rendering/Shaders/ShaderUniform.h"

namespace harmony
{
	struct TransformComponent
	{
		TransformComponent()
		{
			Position = glm::vec3(0.0);
			Scale = glm::vec3(1.0);
			Euler = glm::vec3(0.0);
			Forward = glm::vec3(0.0);
			Right = glm::vec3(0.0);
			Up = glm::vec3(0.0);
			Rotation = glm::quat();
			Model = glm::mat4(1.0);
		}

		glm::vec3 Position;
		glm::vec3 Scale;
		glm::vec3 Euler;
		glm::vec3 LastPosition;
		glm::vec3 LastScale;
		glm::vec3 LastEuler;
		glm::vec3 Forward;
		glm::vec3 Right;
		glm::vec3 Up;
		glm::quat Rotation;
		glm::mat4 Model;
		glm::mat4 LocalModel;
		bool UpdateCollision;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(TransformComponent, Position, Scale, Euler, Rotation);
	};
};