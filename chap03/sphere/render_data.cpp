#include "Gut.h"
#include "Vector4.h"
#include "render_data.h"
// 鏡頭位置
Vector4 g_eye(0.0f, 0.0f, 10.0f); 
// 鏡頭對準的點
Vector4 g_lookat(0.0f, 0.0f, 0.0f); 
// 鏡頭正上方的方向
Vector4 g_up(0.0f, 1.0f, 0.0f); 
// 鏡頭轉換矩陣
Matrix4x4 g_view_matrix;

// 球的模型
Vertex_VC *g_pSphereVertices = NULL;
unsigned short *g_pSphereIndices = NULL;

int g_iNumSphereVertices = 0;
int g_iNumSphereTriangles = 0;
int g_iNumSphereIndices = 0;

//
bool CreateSphere(	float radius,	// 半徑 
					Vertex_VC **ppVertices,		// 傳回球面的頂點
					unsigned short **ppIndices,	// 傳回球面的三角形索引
					float *color,	// 球的顏色
					int stacks,		// 緯度的切面數目
					int slices		// 徑度的切面數目
				)
{
	*ppVertices = NULL;
	*ppIndices = NULL;

	int num_vertices = (stacks+1)*(slices+1);
	int num_triangles = stacks*slices*2;
	
	Vertex_VC *pVertices = new Vertex_VC[num_vertices];
	if ( pVertices==NULL )
		return false;
	
	unsigned short *pIndices = new unsigned short[num_triangles*3];
	if ( pIndices==NULL )
	{
		delete [] pVertices;
		return false;
	}

	*ppVertices = pVertices;
	*ppIndices = pIndices;

	g_iNumSphereVertices = num_vertices;
	g_iNumSphereTriangles = num_triangles;
	g_iNumSphereIndices = num_triangles * 3;

	float default_color[] = {1.0f, 1.0f, 1.0f, 1.0f};
	if ( color==NULL )
		color = default_color;

	const float theta_start_degree = 0.0f;
	const float theta_end_degree = 360.0f;
	const float phi_start_degree = -90.0f;
	const float phi_end_degree = 90.0f;

	float ts = FastMath::DegreeToRadian(theta_start_degree);
	float te = FastMath::DegreeToRadian(theta_end_degree);
	float ps = FastMath::DegreeToRadian(phi_start_degree);
	float pe = FastMath::DegreeToRadian(phi_end_degree);

	float theta_total = te - ts;
	float phi_total = pe - ps;
	float theta_inc = theta_total/stacks;
	float phi_inc = phi_total/slices;

	int i,j;
	int index = 0;
	float theta = ts;
	
	float sin_theta, cos_theta;
	float sin_phi, cos_phi;

	for ( i=0; i<=stacks; i++ )
	{
		float phi = ps;
		FastMath::SinCos(theta, sin_theta, cos_theta);

		for ( j=0; j<=slices; j++, index++ )
		{
			FastMath::SinCos(phi, sin_phi, cos_phi);
			// vertex
			pVertices[index].m_Position[0] = radius * cos_phi * cos_theta;
			pVertices[index].m_Position[1] = radius * sin_phi;
			pVertices[index].m_Position[2] = radius * cos_phi * sin_theta;
			// Color
			float shading = (float) j / (float) slices;
			//float shading = 1.0f;
			pVertices[index].m_RGBA[0] = 255 * color[0] * shading;
			pVertices[index].m_RGBA[1] = 255 * color[1] * shading;
			pVertices[index].m_RGBA[2] = 255 * color[2] * shading;
			pVertices[index].m_RGBA[3] = 255 * color[3] * shading;
			// inc phi
			phi += phi_inc;
		}
		// inc theta
		theta += theta_inc;
	}

	int base = 0;
	index = 0;
	
	// triangle list
	for ( i=0; i<stacks; i++ )
	{
		for ( j=0; j<slices; j++ )
		{
			pIndices[index++] = base;
			pIndices[index++] = base+1;
			pIndices[index++] = base+slices+1;

			pIndices[index++] = base+1;
			pIndices[index++] = base+slices+2;
			pIndices[index++] = base+slices+1;
			
			base++;
		}
		base++;
	}

	return true;
}