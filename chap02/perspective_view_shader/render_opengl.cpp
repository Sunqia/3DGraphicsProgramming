#include <windows.h>
// OpenGL extensions header
#include "glew.h"
#include "wglew.h"
// Standard OpenGL header
#include <GL/gl.h>

#include "Gut.h"
#include "render_data.h"

static GLuint g_VertexProgramID = 0;
static GLuint g_FragmentProgramID = 0;

bool InitResourceOpenGL(void)
{
	g_VertexProgramID = GutLoadVertexProgramOpenGL_ASM
		("../../shaders/vertex_transform.glvp");
	if ( g_VertexProgramID==0 )
		return false;

	g_FragmentProgramID = GutLoadFragmentProgramOpenGL_ASM
		("../../shaders/vertex_transform.glpp");
	if ( g_FragmentProgramID==0 )
		return false;

	// `