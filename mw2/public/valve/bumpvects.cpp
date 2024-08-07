//=========== (C) Copyright 1999 Valve, L.L.C. All rights reserved. ===========
//
// The copyright to the contents herein is the property of Valve, L.L.C.
// The contents may be used and/or copied only with the written permission of
// Valve, L.L.C., or in accordance with the terms and conditions stipulated in
// the agreement/contract under which the contents have been supplied.
//
// Purpose: 
//
// $Workfile:     $
// $Date: 2004/12/02 04:29:08 $
//
//-----------------------------------------------------------------------------
// $Log: bumpvects.cpp,v $
// Revision 1.1  2004/12/02 04:29:08  andy
// *** empty log message ***
//
// Revision 1.1  2004/11/12 12:36:02  andy
// *** empty log message ***
//
// Revision 1.1  2004/04/16 02:25:07  bob
// *** empty log message ***
//
// Revision 1.2  2004/03/07 09:36:40  andy
// *** empty log message ***
//
//
// $NoKeywords: $
//=============================================================================

#ifdef QUIVER
#include "r_local.h"
#endif
#include "bumpvects.h"
#include "vector.h"
#include <assert.h>

// z is coming out of the face.

void GetBumpNormals( const Vector& sVect, const Vector& tVect, const Vector& flatNormal, 
					 const Vector& phongNormal, Vector bumpNormals[NUM_BUMP_VECTS] )
{
	Vector tmpNormal;
	bool leftHanded;
	int i;

	assert( NUM_BUMP_VECTS == 3 );
	
	// Are we left or right handed?
	CrossProduct( sVect, tVect, tmpNormal );
	if( DotProduct( flatNormal, tmpNormal ) < 0.0f )
	{
		leftHanded = true;
	}
	else
	{
		leftHanded = false;
	}

	// Build a basis for the face around the phong normal
	matrix3x4_t smoothBasis;
	CrossProduct( phongNormal.Base(), sVect.Base(), smoothBasis[1] );
	VectorNormalize( smoothBasis[1] );
	CrossProduct( smoothBasis[1], phongNormal.Base(), smoothBasis[0] );
	VectorNormalize( smoothBasis[0] );
	VectorCopy( phongNormal.Base(), smoothBasis[2] );
	
	if( leftHanded )
	{
		VectorNegate( smoothBasis[1] );
	}
	
	// move the g_localBumpBasis into world space to create bumpNormals
	for( i = 0; i < 3; i++ )
	{
		VectorIRotate( g_localBumpBasis[i], smoothBasis, bumpNormals[i] );
	}
}
