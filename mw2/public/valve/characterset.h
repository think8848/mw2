//=========== (C) Copyright 1999 Valve, L.L.C. All rights reserved. ===========
//
// The copyright to the contents herein is the property of Valve, L.L.C.
// The contents may be used and/or copied only with the written permission of
// Valve, L.L.C., or in accordance with the terms and conditions stipulated in
// the agreement/contract under which the contents have been supplied.
//
// Purpose: Shared code for parsing / searching for characters in a string
//			using lookup tables
//
// $Workfile:     $
// $Date: 2004/12/02 04:29:08 $
//
//-----------------------------------------------------------------------------
// $Log: characterset.h,v $
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

#ifndef CHARACTERSET_H
#define CHARACTERSET_H
#pragma once

typedef struct characterset_s
{
	char set[256];
} characterset_t;


// This is essentially a strpbrk() using a precalculated lookup table
//-----------------------------------------------------------------------------
// Purpose: builds a simple lookup table of a group of important characters
// Input  : *pSetBuffer - pointer to the buffer for the group
//			*pSetString - list of characters to flag
//-----------------------------------------------------------------------------
extern void CharacterSetBuild( characterset_t *pSetBuffer, const char *pSetString );


//-----------------------------------------------------------------------------
// Purpose: 
// Input  : *pSetBuffer - pre-build group buffer
//			character - character to lookup
// Output : int - 1 if the character was in the set
//-----------------------------------------------------------------------------
#define IN_CHARACTERSET( SetBuffer, character )		((SetBuffer).set[(character)])


#endif // CHARACTERSET_H
