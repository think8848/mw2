//=========== (C) Copyright 1999 Valve, L.L.C. All rights reserved. ===========
//
// The copyright to the contents herein is the property of Valve, L.L.C.
// The contents may be used and/or copied only with the written permission of
// Valve, L.L.C., or in accordance with the terms and conditions stipulated in
// the agreement/contract under which the contents have been supplied.
//
// Purpose:		A registry of strings and associated ints
//
// $Workfile:     $
// $Date: 2004/12/02 04:29:11 $
//
//-----------------------------------------------------------------------------
// $Log: stringregistry.cpp,v $
// Revision 1.1  2004/12/02 04:29:11  andy
// *** empty log message ***
//
// Revision 1.1  2004/11/12 12:36:18  andy
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

#include <stdio.h>
#include <string.h>
#include "stringregistry.h"
#include "utldict.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"


//-----------------------------------------------------------------------------
// Purpose: This class wraps the containers that do the actual work
//-----------------------------------------------------------------------------
struct StringTable_t : public CUtlDict<int, unsigned short>
{
};



//-----------------------------------------------------------------------------
// Purpose: Add null terminated string to the string registry 
// Input  :
// Output :
//-----------------------------------------------------------------------------
unsigned short CStringRegistry::AddString(const char *stringText, int stringID)
{
	return m_pStringList->Insert( stringText, stringID );
}

//-----------------------------------------------------------------------------
// Purpose: Given string text get the string ID
// Input  :	Text of string to find
// Output : Return string id or -1 if no such string exists
//-----------------------------------------------------------------------------
int	CStringRegistry::GetStringID( const char *stringText )
{
	unsigned short index = m_pStringList->Find( stringText );
	if ( m_pStringList->IsValidIndex( index ) )
	{
		return (*m_pStringList)[index];
	}

	return -1;
}

//-----------------------------------------------------------------------------
// Purpose: Given a string ID return the string text
// Input  : ID of string to find
// Output : Return string text of NULL of no such ID exists
//-----------------------------------------------------------------------------
char const *CStringRegistry::GetStringText( int stringID )
{
	int count = m_pStringList->Count();

	for( unsigned short index = 0 ; index < count ; index++ )
	{
		if ( (*m_pStringList)[index] == stringID )
		{
			return m_pStringList->GetElementName( index );
		}
	}

	return NULL;
}


//-----------------------------------------------------------------------------
// Purpose: Given a key return the string text
//-----------------------------------------------------------------------------
char const *CStringRegistry::GetStringForKey( unsigned short key )
{
	if ( !m_pStringList->IsValidIndex( key ) )
		return NULL;

	return m_pStringList->GetElementName( key );
}

//-----------------------------------------------------------------------------
// Purpose: Given a key return the string text
//-----------------------------------------------------------------------------
int CStringRegistry::GetIDForKey( unsigned short key )
{
	if ( !m_pStringList->IsValidIndex( key ) )
		return 0;

	return (*m_pStringList)[key];
}

//-----------------------------------------------------------------------------
// Purpose: Clear all strings from the string registry
//-----------------------------------------------------------------------------
void CStringRegistry::ClearStrings(void)
{
	m_pStringList->RemoveAll();
}

//-----------------------------------------------------------------------------
// Purpose: Destructor - delete the list of strings and maps
// Input  :
// Output :
//-----------------------------------------------------------------------------
CStringRegistry::~CStringRegistry(void)
{
	delete m_pStringList;
}

//-----------------------------------------------------------------------------
// Purpose: Constructor
// Input  :
// Output :
//-----------------------------------------------------------------------------
CStringRegistry::CStringRegistry(void)
{
	m_pStringList = new StringTable_t;
}
