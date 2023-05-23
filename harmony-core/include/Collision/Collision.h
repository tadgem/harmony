#pragma once

#include "Collision/CollisionShapes.h"

namespace harmony {
    class Collision {
    public:

        static AABB UpdateAABB(AABB aabb, glm::mat3 matrix, glm::vec3 position);

        // Intersection Tests
        static bool Intersects(AABB a, AABB b);

        static bool Intersects(Sphere a, Sphere b);

        static bool Intersects(AABB a, Sphere b);

        static bool Intersects(Sphere a, AABB b);

        static bool Intersects(AABB a, glm::vec3 b);

        static RayHit Intersects(Ray r, AABB aabb);

        static RayHit Intersects(Ray r, Sphere aabb);
    };
}