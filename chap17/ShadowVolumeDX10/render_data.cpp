#include "Vector4.h"
#include "render_data.h"
#include "gut.h"
#include "GutModel.h"

// camera object
CGutUserControl g_Control;
// model object
CGutModel g_Box;
CGutModel g_Box_shadowvolume;
CGutModel g_Wall;
// shadowvolume object
CGutShadowVolume g_ShadowVolume;
// camera fov
float g_fFOV = 45.0f;
//
const float fQuadSize = 4.0f;
const float fQuadZ = -2.0f;
//
bool g_bDrawShadowVolume = false;
bool g_bDirectionalLight = true;

Vertex_V3T2 g_Quad[4] =
{
	{{-fQuadSize, -fQuadSize, fQuadZ}, {0.0f, 1.0f}},
	{{ fQuadSize, -fQuadSize, fQuadZ}, {1.0f, 1.0f}},
	{{-fQuadSize,  fQuadSize, fQuadZ}, {0.0f, 0.0f}},
	{{ fQuadSize,  fQuadSize, fQuadZ}, {1.0f, 0.0f}}
};

Vertex_V3T2 g_FullScreenQuad[4] =
{
	{{-1, -1, 0}, {0.0f, 1.0f}},
	{{ 1, -1, 0}, {1.0f, 1.0f}},
	{{-1,  1, 0}, {0.0f, 0.0f}},
	{{ 1,  1, 0}, {1.0f, 0.0f}}
};
