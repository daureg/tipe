#include "camera_app.h"

CameraApp::CameraApp():m_cam(&Vector4(0,0,5,0)) {
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(70,(double)RES_X/RES_Y,.1f,100);
	glEnable(GL_DEPTH_TEST);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	m_vert = new float[N_VERTS*V_SIZE];
	m_vert[0]=1.0f; m_vert[1]=1.0f; m_vert[2]=1.0f; m_vert[3]=-1.0f; m_vert[4]=1.0f; m_vert[5]=1.0f; m_vert[6]=-1.0f; m_vert[7]=-1.0f; m_vert[8]=1.0f; m_vert[9]=1.0f; m_vert[10]=-1.0f; m_vert[11]=1.0f; m_vert[12]=1.0f; m_vert[13]=1.0f; m_vert[14]=-1.0f; m_vert[15]=-1.0f; m_vert[16]=1.0f; m_vert[17]=-1.0f; m_vert[18]=-1.0f; m_vert[19]=-1.0f; m_vert[20]=-1.0f; m_vert[21]=1.0f; m_vert[22]=-1.0f; m_vert[23]=-1.0f;
	m_col = new unsigned char[N_VERTS*C_SIZE];
	m_col[0]=255; m_col[1]=0; m_col[2]=0; m_col[3]=255; m_col[4]=0; m_col[5]=0; m_col[6]=255; m_col[7]=0; m_col[8]=0; m_col[9]=255; m_col[10]=0; m_col[11]=0; m_col[12]=0; m_col[13]=0; m_col[14]=255; m_col[15]=0; m_col[16]=0; m_col[17]=255; m_col[18]=0; m_col[19]=0; m_col[20]=255; m_col[21]=0; m_col[22]=0; m_col[23]=255;
	m_idx = new unsigned char[NUM_VERTICES];
	m_idx[0]=0; m_idx[1]=1; m_idx[2]=2; m_idx[3]=0; m_idx[4]=2; m_idx[5]=3; m_idx[6]=4; m_idx[7]=0; m_idx[8]=3; m_idx[9]=4; m_idx[10]=3; m_idx[11]=7; m_idx[12]=5; m_idx[13]=4; m_idx[14]=7; m_idx[15]=5; m_idx[16]=7; m_idx[17]=6; m_idx[18]=1; m_idx[19]=5; m_idx[20]=6; m_idx[21]=1; m_idx[22]=6; m_idx[23]=2; m_idx[24]=4; m_idx[25]=5; m_idx[26]=1; m_idx[27]=4; m_idx[28]=1; m_idx[29]=0; m_idx[30]=2; m_idx[31]=6; m_idx[32]=7; m_idx[33]=2; m_idx[34]=7; m_idx[35]=3;
	AddAnimObject(&m_cam);
}

CameraApp::~CameraApp() {
	delete [] m_vert;
	delete [] m_col;
	delete [] m_idx;
}
void CameraApp::Draw() {
	m_frames++;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	m_cam.Look();
	/* activation des tableaux de sommets */
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        
        /* envoie des donnees */
        glVertexPointer(V_SIZE, GL_FLOAT, 0, m_vert);
        glColorPointer(C_SIZE, GL_UNSIGNED_BYTE, 0, m_col);
        
        /* rendu indice */
        glDrawElements(GL_TRIANGLES, NUM_VERTICES, GL_UNSIGNED_BYTE, m_idx);
        
        /* desactivation des tableaux de sommet */
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);

	glFlush();
	SDL_GL_SwapBuffers();

}
