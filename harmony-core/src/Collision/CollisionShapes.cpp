#include <optick.h>
#include "Collision/CollisionShapes.h"

harmony::RayHit::RayHit(glm::vec4 position, float distance) : Position(position), Distance(distance)
{
	OPTICK_EVENT();
}
