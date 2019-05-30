#include "Vector4.h"
#include "render_data.h"
#include "gut.h"

int g_iWindowWidth = 512;
int g_iWindowHeight = 512;

float g_fOrthoSize = 5.0f;
float g_fOrthoWidth = g_fOrthoSize;
float g_fOrthoHeight = g_fOrthoSize;

// ���Y��m
Vector4 g_eye(0.0f, 0.0f, 2.0f); 
// ���Y��Ǫ��I
Vector4 g_lookat(0.0f, 0.0f, 0.0f); 
// ���Y���W�誺��V
Vector4 g_up(0.0f, 1.0f, 0.0f); 
// ���Y�ഫ�x�}
Matrix4x4 g_view_matrix;
// �������x�}
Matrix4x4 g_world_matrix;

const float g_fSize = 0.8f;
// �x�Ϊ�4�ӳ��I
// Position, Texcoord
Vertex_VT g_Quad[4] =
{
	{{-g_fSize, -g_fSize, 0.0f}, {0.0f, 1.0f}},
	{{ g_fSize, -g_fSize, 0.0f}, {1.0f, 1.0f}},
	{{-g_fSize,  g_fSize, 0.0f}, {0.0f, 0.0f}},
	{{ g_fSize,  g_fSize, 0.0f}, {1.0f, 0.0f}}
};

int g_iMode = 1;

bool g_bStencil = true;