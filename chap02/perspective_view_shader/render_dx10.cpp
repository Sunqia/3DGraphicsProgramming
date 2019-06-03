#ifdef _ENABLE_DX10_

#include "Gut.h"
#include "render_data.h"

static ID3D10Device			*g_pDevice = NULL;
static ID3D10InputLayout	*g_pVertexLayout = NULL;
static ID3D10Buffer			*g_pVertexBuffer = NULL;
static ID3D10Buffer			*g_pConstantBuffer = NULL;
static ID3D10VertexShader	*g_pVertexShader = NULL;
static ID3D10PixelShader	*g_pPixelShader = NULL;

bool InitResourceDX10(void)
{
	g_pDevice = GutGetGraphicsDeviceDX10();
	ID3D10Blob *pVSCode = NULL;

	// `