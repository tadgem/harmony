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
    return false;
}

bool harmony::Collision::Intersects(Sphere& a, Sphere& b)
{
    return false;
}

bool harmony::Collision::Intersects(AABB& a, Sphere& b)
{
    return false;
}

bool harmony::Collision::Intersects(Sphere& a, AABB& b)
{
    return Intersects(b,a);
}
