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
// $Log: bumpvects.h,v $
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

#ifndef BUMPVECTS_H
#define BUMPVECTS_H
#pragma once

#include "mathlib.h"

#define OO_SQRT_3 0.57735025882720947f

#define NUM_BUMP_VECTS 3

const Vector g_localBumpBasis[NUM_BUMP_VECTS] = {
	Vector( 0.81649661064147949f, 0.0f, OO_SQRT_3 ),
	Vector(  -0.40824833512306213f, 0.70710676908493042f, OO_SQRT_3 ),
	Vector(  -0.40824821591377258f, -0.7071068286895752f, OO_SQRT_3 )
};

void GetBumpNormals( const Vector& sVect, const Vector& tVect, const Vector& flatNormal, 
					 const Vector& phongNormal, Vector bumpNormals[NUM_BUMP_VECTS] );

#endif // BUMPVECTS_H
