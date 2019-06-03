#include <windows.h>

#include "glew.h" // OpenGL extension
// Standard OpenGL header
#include <GL/gl.h>

#include "Gut.h"
#include "GutWin32.h"
#include "GutModel_OpenGL.h"
#include "render_data.h"

static Matrix4x4 g_projection_matrix;

static CGutModel_OpenGL g_Model_OpenGL;

bool InitResourceOpenGL(void)
{
	// 投影矩陣
	g_projection_matrix = GutMatrixPerspectiveRH_OpenGL(g_fFOV, 1.0f, 0.1f, 100.0f);
	// 設定視角轉換矩陣
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf( (float *) &g_projection_matrix);
	glMatrixMode(GL_MODELVIEW);	

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	CGutModel::SetTexturePath("../../textures/");

	g_Model_OpenGL.ConvertToOpenGLModel(&g_Model);

	return true;
}

bool ReleaseResourceOpenGL(void)
{
	return true;
}

// callback function. 視窗大小改變時會被呼叫, 並傳入新的視窗大小.
void ResizeWindowOpenGL(int width, int height)
{
	// 使用新的視窗大小做為新的繪圖解析度
	glViewport(0, 0, width, height);
	// 投影矩陣, 重設水平跟垂直方向的視角.
	float aspect = (float) height / (float) width;
	g_projection_matrix = GutMatrixPerspectiveRH_OpenGL(g_fFOV, aspect, 0.1f, 100.0f);
	// 設定視角轉換矩陣
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf( (float *) &g_projection_matrix);
}

static void RenderModelOpenGL(bool mirror, Vector4 *pPlane)
{
	Matrix4x4 view_matrix = g_Control.GetViewMatrix();
	Matrix4x4 world_matrix = g_Control.GetObjectMatrix();

	glMatrixMode(GL_MODELVIEW);

	if ( mirror )
	{
		if ( g_bClip )
		{
			// 先套入鏡頭矩陣, clipplane的設定會轉換到鏡頭座標系上
			glLoadMatrixf( (float *) &view_matrix);
			// 把反射效果