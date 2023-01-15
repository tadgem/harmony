#include "Collision/Collision.h"


/*
Transforming Axis-Aligned Bounding Boxes
by Jim Arvo
from "Graphics Gems", Academic Press, 1990
*/

// #include "GraphicsGems.h"                                     
// /* Transforms a 3D axis-aligned box via a 3x3 matrix and a translation
//  * vector and returns an axis-aligned box enclosing the result. */ 

// void Transform_Box( M, T, A, B )
// Matrix3  M;  	/* Transform matrix.             */
// Vector3  T;  	/* Translation matrix.           */
// Box3     A;  	/* The original bounding box.    */
// Box3    *B;  	/* The transformed bounding box. */
//     {
//     float  a, b;
//     float  Amin[3], Amax[3];
//     float  Bmin[3], Bmax[3];
//     int    i, j;

//     /*Copy box A into a min array and a max array for easy reference.*/

//     amin[0] = (float)a.min.x;  amax[0] = (float)a.max.x;
//     amin[1] = (float)a.min.y;  amax[1] = (float)a.max.y;
//     amin[2] = (float)a.min.z;  amax[2] = (float)a.max.z;

//     /* Take care of translation by beginning at T. */

//     Bmin[0] = Bmax[0] = (float)T.x;
//     Bmin[1] = Bmax[1] = (float)T.y;
//     Bmin[2] = Bmax[2] = (float)T.z;

//     /* Now find the extreme points by considering the product of the */
//     /* min and max with each component of M.  */

//     for( i = 0; i < 3; i++ )
//     for( j = 0; j < 3; j++ )
//         {
//         a = (float)(M.element[i][j] * Amin[j]);
//         b = (float)(M.element[i][j] * Amax[j]);
//         if( a < b ) 

//             { 
//             Bmin[i] += a; 
//             Bmax[i] += b;
//             }
//         else 
//             { 
//             Bmin[i] += b; 
//             Bmax[i] += a;
//             }
//         }

//     /* Copy the result into the new box. */

//     B->min.x = Bmin[0];  B->max.x = Bmax[0];
//     B->min.y = Bmin[1];  B->max.y = Bmax[1];
//     B->min.z = Bmin[2];  B->max.z = Bmax[2];

//     } 

void harmony::Collision::UpdateAABB(AABB& aabb, glm::mat3 matrix, glm::vec3 position)
{
	AABB original = aabb;

	float  a, b;
	glm::vec3 Amin, Amax;
	glm::vec3 Bmin, Bmax;
	int    i, j;

	Amin[0] = (float)aabb.Min.x;  
	Amax[0] = (float)aabb.Max.x;
    Amin[1] = (float)aabb.Min.y;  
	Amax[1] = (float)aabb.Max.y;
	Amin[2] = (float)aabb.Min.z;
	Amax[2] = (float)aabb.Max.z;

	Bmin[0] = Bmax[0] = (float)position.x;
	Bmin[1] = Bmax[1] = (float)position.y;
	Bmin[2] = Bmax[2] = (float)position.z;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            a = (float)(matrix[i][j] * Amin[j]);
            b = (float)(matrix[i][j] * Amax[j]);
            if (a < b)

            {
                Bmin[i] += a;
                Bmax[i] += b;
            }
            else
            {
                Bmin[i] += b;
                Bmax[i] += a;
            }
        }
    }

    aabb.Min.x = Bmin[0];  
    aabb.Max.x = Bmax[0];
    aabb.Min.y = Bmin[1];  
    aabb.Max.y = Bmax[1];
    aabb.Min.z = Bmin[2];  
    aabb.Max.z = Bmax[2];
}

bool harmony::Collision::Intersects(AABB& a, AABB& b)
{
    if (a.Min.x <= b.Min.x && a.Max.x >= b.Max.x)
    {
        return false;
    }

    if (a.Max.x <= b.Min.x || a.Min.x >= b.Max.x)
    {
        return false;
    }

    if (a.Min.y <= b.Min.y && a.Max.y >= b.Max.y)
    {
        return false;
    }

    if (a.Max.y <= b.Min.y || a.Min.y >= b.Max.y)
    {
        return false;
    }

    if (a.Min.z <= b.Min.z && a.Max.z >= b.Max.z)
    {
        return false;
    }

    if (a.Max.z <= b.Min.z || a.Min.z >= b.Max.z)
    {
        return false;
    }

    return true;
}

bool harmony::Collision::Intersects(Sphere& a, Sphere& b)
{
    glm::vec3 apos = glm::vec3(a.PosR.x, a.PosR.y, a.PosR.z);
    glm::vec3 bpos = glm::vec3(b.PosR.x, b.PosR.y, b.PosR.z);

    float dist = glm::abs(glm::distance(apos, bpos));
    if (dist < (a.PosR[3] + b.PosR[3]))
    {
        return true;
    }

    return false;
}

bool harmony::Collision::Intersects(AABB& a, Sphere& b)
{
    // https://stackoverflow.com/questions/28343716/sphere-intersection-test-of-aabb
    // if (C[i] < Bmin[i]) dmin += SQR(C[i] - Bmin[i]); else
    // if (C[i] > Bmax[i]) dmin += SQR(C[i] - Bmax[i]);
    // Where Bmin stores the minima of the AABB for each axis, Bmax stores the maxima of the AABB for each axis, 
    // C is the coordinate of the sphere centerand r2 is the squared radius.
    float dmin = 0.0f;
    float r2 = b.PosR.w * b.PosR.w;
    for (int i = 0; i < 3; i++) {
        if (b.PosR[i] < a.Min[i])
        {
            float d = b.PosR[i] - a.Min[i];
            dmin += d * d;
        }
        else if (b.PosR[i] > a.Max[i])
        {
            float d = b.PosR[i] - a.Max[i];
            dmin += d * d;
        }
    }
    if (dmin <= r2)
    {
        return true;
    }
    return false;
}

bool harmony::Collision::Intersects(Sphere& a, AABB& b)
{
    return Intersects(b,a);
}

bool harmony::Collision::Intersects(AABB& a, glm::vec3& b)
{
    return b.x >= a.Min.x && b.x <= a.Max.x &&
        b.y >= a.Min.y && b.y <= a.Max.y &&
        b.z >= a.Min.z && b.x <= a.Max.z;
}

harmony::HitPosition harmony::Collision::Intersects(Ray& r, AABB& aabb)
{

    glm::vec3 tMin  = (aabb.Min - r.Origin) / r.Direction;
    glm::vec3 tMax  = (aabb.Max - r.Origin) / r.Direction;
    glm::vec3 t1    = glm::min(tMin, tMax);
    glm::vec3 t2    = glm::max(tMin, tMax);
    float tNear     = glm::max(glm::max(t1.x, t1.y), t1.z);
    float tFar      = glm::min(glm::min(t2.x, t2.y), t2.z);

    if ((tFar - tNear) > 0.0f && tNear < 0.0f && tFar < 0.0f)
    {
        glm::vec3 pos = r.Origin + (r.Direction * tFar);
        float dist = glm::distance(r.Origin, pos);
        return HitPosition(glm::vec4(pos, 1.0f));
    }

    return HitPosition(glm::vec4(glm::vec3(- 1.0), -1.0f));
}

harmony::HitPosition harmony::Collision::Intersects(Ray& r, Sphere& s)
{
    float cx = s.PosR[0];
    float cy = s.PosR[1];
    float cz = s.PosR[2];
    float px = r.Origin.x;
    float py = r.Origin.y;
    float pz = r.Origin.z;
    float vx = r.Direction.x;
    float vy = r.Direction.y;
    float vz = r.Direction.z;

    float A = vx * vx + vy * vy + vz * vz;
    float B = 2.0 * (px * vx + py * vy + pz * vz - vx * cx - vy * cy - vz * cz);
    float C = px * px - 2 * px * cx + cx * cx + py * py - 2 * py * cy + cy * cy +
        pz * pz - 2 * pz * cz + cz * cz - s.PosR[3] * s.PosR[3];

    float D = B * B - 4 * A * C;

    if (D < 0.0f || B < 0.0f)
    {
        return HitPosition(glm::vec4(glm::vec3(-1.0), -1.0f));
    }

    float t1 = (-B - glm::sqrt(D)) / (2.0 * A);

    glm::vec3 rayEnd = r.Origin + r.Direction;

    glm::vec3 solution1 = glm::vec3(r.Origin.x * (1 - t1) + t1 * rayEnd.x,
        r.Origin.y * (1 - t1) + t1 * rayEnd.y,
        r.Origin.z * (1 - t1) + t1 * rayEnd.z);

    if (D == 0.0f)
    {
        return HitPosition(glm::vec4(solution1, 1.0f));
    }

    float t2 = (-B + glm::sqrt(D)) / (2.0 * A);
    glm::vec3 solution2 = glm::vec3(r.Origin.x * (1 - t2) + t2 * rayEnd.x,
        r.Origin.y * (1 - t2) + t2 * rayEnd.y,
        r.Origin.z * (1 - t2) + t2 * rayEnd.z);

    return HitPosition(glm::vec4(solution2, 1.0f));

}
