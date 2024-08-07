//======== (C) Copyright 1999, 2000 Valve, L.L.C. All rights reserved. ========
//
// The copyright to the contents herein is the property of Valve, L.L.C.
// The contents may be used and/or copied only with the written permission of
// Valve, L.L.C., or in accordance with the terms and conditions stipulated in
// the agreement/contract under which the contents have been supplied.
//
// Purpose: Common collision utility methods
//
// $Header: /home/cvsroot/mythwar/src_main/public/valve/collisionutils.h,v 1.2 2005/03/12 15:25:58 andy Exp $
// $NoKeywords: $
//=============================================================================

#ifndef COLLISIONUTILS_H
#define COLLISIONUTILS_H

//-----------------------------------------------------------------------------
// forward declarations
//-----------------------------------------------------------------------------

struct Ray_t;
class Vector;
class Vector2D;
class Vector4D;
struct cplane_t;
class QAngle;

//-----------------------------------------------------------------------------
//
// IntersectRayWithTriangle
//
// Intersects a ray with a triangle, returns distance t along ray.
// t will be less than zero if no intersection occurred
// oneSided will cull collisions which approach the triangle from the back
// side, assuming the vertices are specified in counter-clockwise order
// The vertices need not be specified in that order if oneSided is not used
//
//-----------------------------------------------------------------------------
float IntersectRayWithTriangle( const Ray_t& ray, 
		                        const Vector& v1, const Vector& v2, const Vector& v3, 
								bool oneSided );

//-----------------------------------------------------------------------------
//
// ComputeIntersectionBarycentricCoordinates
//
// Figures out the barycentric coordinates (u,v) where a ray hits a 
// triangle. Note that this will ignore the ray extents, and it also ignores
// the ray length. Note that the edge from v1->v2 represents u (v2: u = 1), 
// and the edge from v1->v3 represents v (v3: v = 1). It returns false
// if the ray is parallel to the triangle (or when t is specified if t is less
// than zero).
//
//-----------------------------------------------------------------------------
bool ComputeIntersectionBarycentricCoordinates( const Ray_t& ray, 
		const Vector& v1, const Vector& v2, const Vector& v3, float& u, float& v,
		float *t = 0 );

//-----------------------------------------------------------------------------
//
// IntersectRayWithRay
//
// Returns whether or not there was an intersection.  The "t" paramter is the
// distance along ray0 and the "s" parameter is the distance along ray1.  If 
// the two lines to not intersect the "t" and "s" represent the closest approach.
// "t" and "s" will not change if the rays are parallel.
//
//-----------------------------------------------------------------------------

bool IntersectRayWithRay( const Ray_t &ray0, const Ray_t &ray1, float &t, float &s );


//-----------------------------------------------------------------------------
//
// IntersectRayWithPlane
//
// Intersects a ray with a plane, returns distance t along ray.
// t will be less than zero the intersection occurs in the opposite direction of the ray.
//
//-----------------------------------------------------------------------------

float IntersectRayWithPlane( const Ray_t& ray, const cplane_t& plane ); 
float IntersectRayWithPlane( const Vector& org, const Vector& dir, const cplane_t& plane );
float IntersectRayWithPlane( const Vector& org, const Vector& dir, const Vector& normal, float dist );

// This version intersects a ray with an axis-aligned plane
float IntersectRayWithAAPlane( const Vector& vecStart, const Vector& vecEnd, int nAxis, float flSign, float flDist );

//-----------------------------------------------------------------------------
// IntersectRayWithBox
//
// Purpose: Computes the intersection of a ray with a box (AABB)
// Output : Returns true if there is an intersection
//			t contains the parameter along the ray (0.0-1.0)
//			hitside contains the index of the side hit (0-2 mins x-z, 3-5 maxs x-z)
//			startsolid is true if the ray started inside the box
//-----------------------------------------------------------------------------
bool IntersectRayWithBox( const Vector &rayStart, const Vector &rayDelta, const Vector &boxMins, const Vector &boxMaxs, float epsilon, float &t, int &hitside, bool &startsolid );

//-----------------------------------------------------------------------------
// 
// IsSphereIntersectingSphere
//
// returns true if there's an intersection between sphere and sphere
//
//-----------------------------------------------------------------------------
bool IsSphereIntersectingSphere( const Vector& center1, float radius1, 
								 const Vector& center2, float radius2 );

//-----------------------------------------------------------------------------
// 
// IsBoxIntersectingSphere
//
// returns true if there's an intersection between box and sphere
//
//-----------------------------------------------------------------------------
bool IsBoxIntersectingSphere( const Vector& boxMin, const Vector& boxMax, 
						      const Vector& center, float radius );

bool IsBoxIntersectingSphereExtents( const Vector& boxCenter, const Vector& boxHalfDiag, 
									const Vector& center, float radius );

//-----------------------------------------------------------------------------
// 
// IsCircleIntersectingRectangle
//
// returns true if there's an intersection between rectangle and circle
//
//-----------------------------------------------------------------------------
bool IsCircleIntersectingRectangle( const Vector2D& boxMin, const Vector2D& boxMax, 
						      const Vector2D& center, float radius );


//-----------------------------------------------------------------------------
// 
// IsBoxIntersectingBox
//
// returns true if there's an intersection between two boxes
//
//-----------------------------------------------------------------------------
bool IsBoxIntersectingBox( const Vector& boxMin1, const Vector& boxMax1, 
						   const Vector& boxMin2, const Vector& boxMax2 );

bool IsBoxIntersectingBoxExtents( const Vector& boxCenter1, const Vector& boxHalfDiagonal1, 
						   const Vector& boxCenter2, const Vector& boxHalfDiagonal2 );


//-----------------------------------------------------------------------------
// 
// IsBoxIntersectingRay
//
// returns true if there's an intersection between box and ray
//
//-----------------------------------------------------------------------------
bool IsBoxIntersectingRay( const Vector& boxMin, const Vector& boxMax, 
						   const Vector& origin, const Vector& delta );


//-----------------------------------------------------------------------------
// 
// IsPointInBox
//
// returns true if the point is in the box
//
//-----------------------------------------------------------------------------
bool IsPointInBox( const Vector& pt, const Vector& boxMin, const Vector& boxMax );


//-----------------------------------------------------------------------------
// Purpose: returns true if pt intersects the truncated cone
// origin - cone tip, axis unit cone axis, cosAngle - cosine of cone axis to surface angle
//-----------------------------------------------------------------------------
bool IsPointInCone( const Vector &pt, const Vector &origin, const Vector &axis, float cosAngle, float length );

//-----------------------------------------------------------------------------
// Intersects a plane with a triangle (using barycentric definition)
// The return value, in pIntersection, is an array of barycentric coordinates 
// describing at most 2 intersection points. 
// The return value is the number of intersection points
//-----------------------------------------------------------------------------
int IntersectTriangleWithPlaneBarycentric( const Vector& org, const Vector& edgeU, const Vector& edgeV, 
										   const Vector4D& plane, Vector2D* pIntersection );

//-----------------------------------------------------------------------------
// 
// SeparatingAxisAABoxTriangle
//
// Test for an intersection (overlap) between an axial-aligned bounding 
// box (AABB) and a triangle.
//
// Triangle points are in counter-clockwise order with the normal facing "out."
//
// Using the "Separating-Axis Theorem" to test for intersections between
// a triangle and an axial-aligned bounding box (AABB).
// 1. 4 Face Plane Tests - these are defined by the axial planes (x,y,z) making 
//                         up the AABB and the triangle plane
// 2. 9 Edge Planes Tests - the 3 edges of the triangle crossed with all 3 axial 
//                          planes (x, y, z)
//
//-----------------------------------------------------------------------------
bool SeparatingAxisAABoxTriangle( const Vector &boxCenter, const Vector &boxExtents,
				   		          const Vector &v1, const Vector &v2, const Vector &v3,
						          const Vector &planeNormal, float planeDist );


//-----------------------------------------------------------------------------
//
// PointInQuadBarycentric
//
//	Given a point and a quad in a plane return the u and v (barycentric) positions
//  of the point relative to the quad.  The points (v1,v2,v3,v4) should be given
//  in a counter-clockwise order with v1 acting as the primary corner (u=0, v=0).
//  Thus, u0 = v2 - v1, and v0 = v4 - v1.
//
//-----------------------------------------------------------------------------

enum QuadBarycentricRetval_t
{
	BARY_QUADRATIC_FALSE					= 0,
	BARY_QUADRATIC_TRUE						= 1,
	BARY_QUADRATIC_NEGATIVE_DISCRIMINANT	= 2
};

QuadBarycentricRetval_t PointInQuadToBarycentric( const Vector &v1, const Vector &v2, 
	const Vector &v3, const Vector &v4, const Vector &point, Vector2D &uv );


void PointInQuadFromBarycentric( const Vector &v1, const Vector &v2, const Vector &v3, const Vector &v4,
								 const Vector2D &uv, Vector &point );
void TexCoordInQuadFromBarycentric( const Vector2D &v1, const Vector2D &v2, const Vector2D &v3, const Vector2D &v4,
								    const Vector2D &uv, Vector2D &texCoord );


//-----------------------------------------------------------------------------
// Compute point from barycentric specification
// Edge u goes from v0 to v1, edge v goes from v0 to v2
//-----------------------------------------------------------------------------

void ComputePointFromBarycentric( const Vector& v0, const Vector& v1, const Vector& v2, 
								 float u, float v, Vector& pt );
void ComputePointFromBarycentric( const Vector2D& v0, const Vector2D& v1, const Vector2D& v2, 
								 float u, float v, Vector2D& pt );


//-----------------------------------------------------------------------------
// Compute a separating plane between two boxes (expensive!)
// Returns false if no separating plane exists
//-----------------------------------------------------------------------------
bool ComputeSeparatingPlane( const Vector& org1, QAngle const& angles1, const Vector& min1, const Vector& max1, 
	const Vector& org2, QAngle const& angles2, const Vector& min2, const Vector& max2, 
	float tolerance, cplane_t* pPlane );



#if 0
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool SeparatingAxisAABoxSweptTriangle( const Vector &boxStart, const Vector &boxEnd,
								       const Vector &boxExtents, const Vector &v1,
								       const Vector &v2, const Vector &v3,
								       const Vector &triNormal, float triDist,
								       bool bStartOutside );

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float IntersectAABoxSweptTriangle( const Vector &boxStart, const Vector &boxEnd,
								   const Vector &boxExtents, const Vector &v1,
								   const Vector &v2, const Vector &v3,
								   const Vector &triNormal, float triDist,
								   bool bStartOutside );
#endif

#endif // COLLISIONUTILS_H