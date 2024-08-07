//=========== (C) Copyright 1999 Valve, L.L.C. All rights reserved. ===========
//
// The copyright to the contents herein is the property of Valve, L.L.C.
// The contents may be used and/or copied only with the written permission of
// Valve, L.L.C., or in accordance with the terms and conditions stipulated in
// the agreement/contract under which the contents have been supplied.
//
// $Header: /home/cvsroot/mythwar/src_main/public/valve/materialsystem/shaderapidx8.h,v 1.2 2005/03/12 15:25:58 andy Exp $
// $NoKeywords: $
//
// The dx8 implementation of the shader API
//=============================================================================

#ifndef SHADERAPIDX8_H
#define SHADERAPIDX8_H

#include "ShaderAPI.h"
#include "locald3dtypes.h"

//-----------------------------------------------------------------------------
// Forward declarations
//-----------------------------------------------------------------------------

class IMeshDX8;
class CMeshBuilder;
struct ShadowState_t;
class IMaterialInternal;


//-----------------------------------------------------------------------------
// State that matters to buffered meshes... (for debugging only)
//-----------------------------------------------------------------------------

struct BufferedState_t
{
	D3DXMATRIX m_Transform[3];
	D3DVIEWPORT m_Viewport;
	int m_BoundTexture[8];
	void *m_VertexShader;
	void *m_PixelShader;
};

//-----------------------------------------------------------------------------
// The DX8 shader API
//-----------------------------------------------------------------------------

class IShaderAPIDX8 : public IShaderAPI
{
public:
	// Draws the mesh
	virtual void DrawMesh( IMeshDX8* pMesh ) = 0;

	// modifies the vertex data when necessary
	virtual void ModifyVertexData( ) = 0;

	// Gets the current buffered state... (debug only)
	virtual void GetBufferedState( BufferedState_t& state ) = 0;

	// Gets the current backface cull state....
	virtual D3DCULL GetCullMode() const = 0;

	// Gets the window size
	virtual void GetWindowSize( int& width, int& height ) const = 0;

	// Measures fill rate
	virtual void ComputeFillRate() = 0;

	// Selection mode methods
	virtual bool IsInSelectionMode() const = 0;

	// We hit somefin in selection mode
	virtual void RegisterSelectionHit( float minz, float maxz ) = 0;

	// Get the currently bound material
	virtual IMaterialInternal* GetBoundMaterial() = 0;

	// used to determine if we're deactivated
	virtual bool IsDeactivated() const = 0;

	// These methods are called by the transition table
	// They depend on dynamic state so can't exist inside the transition table
	virtual void ApplyZBias( const ShadowState_t& shaderState ) = 0;
	virtual void ApplyTextureEnable( const ShadowState_t& state, int stage ) = 0;
	virtual void ApplyCullEnable( bool bEnable ) = 0;
	virtual void SetVertexBlendState( int numBones ) = 0;
	virtual void SetVertexShaderConstantC1( float overbright ) = 0;

	virtual int GetActualNumTextureUnits() const = 0;
	virtual bool IsRenderingMesh() const = 0;

	//////////////////////////////////////////////////////////////////////////	
	// add by Andy
	virtual void SetTextureStageState( int stage, D3DTEXTURESTAGESTATETYPE state, DWORD val ) = 0;
	
	virtual void SetRenderState( D3DRENDERSTATETYPE state, DWORD val ) = 0;

	virtual void CommitStateChanges() = 0;

	virtual HRESULT CreateDXTexture(int width, int height, int mip, 
		ImageFormat format, void **ppTex) = 0;

	virtual IDirect3D *getD3D() = 0;

	virtual IDirect3DDevice *getD3DDevice() = 0;

	virtual HRESULT drawLine(DWORD dwColor, RECT rect) = 0;
		
	virtual HRESULT draw3DLine(DWORD dwColor, float fPos1[3], float fPos2[3]) = 0;

	virtual HRESULT drawLineRect(D3DCOLOR dwColor, RECT rect, DWORD size) = 0;
	
	virtual HRESULT rectangleBlt(RECT *pDest, D3DCOLOR dwColor) = 0;

	virtual HRESULT Blt2D(LPVOID pTex, RECT *pSrc, RECT *pDest, D3DCOLOR dwColor) = 0;
};

#endif // SHADERAPIDX8_H
