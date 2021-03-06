#include "Vector4.h"
#include "render_data.h"
#include "gut.h"

// 鏡頭位置
Vector4 g_eye(0.0f, 0.0f, 2.0f); 
// 鏡頭對準的點
Vector4 g_lookat(0.0f, 0.0f, 0.0f); 
// 鏡頭正上方的方向
Vector4 g_up(0.0f, 1.0f, 0.0f); 
// 鏡頭轉換矩陣
Matrix4x4 g_view_matrix;
// 物件旋轉矩陣
Matrix4x4 g_world_matrix;

Vector4 g_vGlobal_AmbientLight(0.1f, 0.1f, 0.1f, 0.1f);

Vector4 g_vMaterialAmbient(1.0f, 1.0f, 1.0f, 1.0f);
Vector4 g_vMaterialDiffuse(1.0f ,1.0f, 1.0f ,1.0f);
Vector4 g_vMaterialSpecular(0.0f, 0.0f, 0.0f, 0.0f);
Vector4 g_vMaterialEmissive(0.0f, 0.0f, 0.0f, 0.0f);

Light_Info g_Lights[g_iNumLights];

int g_iNumGridVertices = 0;
int g_iNumGridIndices = 0;
int g_iNumGridTriangles = 0;

Vertex_V3N3 *g_pGridVertices = NULL;
unsigned short *g_pGridIndices = NULL;
