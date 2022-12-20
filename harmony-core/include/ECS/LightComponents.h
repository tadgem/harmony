#pragma once
#include "glm.hpp"

struct DirectionalLight
{
	glm::vec4 Direction;
	glm::vec4 Colour;
};

struct PointLight
{
	glm::vec4 Position;
	glm::vec4 Colour;

	float Radius;
};

struct SpotLight : PointLight
{

};