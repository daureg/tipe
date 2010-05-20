#include "triangle_app.h"
TriangleApp::TriangleApp() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,RES_X,RES_Y,0);
	m_l1 = new Uint16[SCREEN_SIZE];
	m_l2 = new Uint16[SCREEN_SIZE];
	m_l3 = new Uint16[SCREEN_SIZE];
	Uint16 t[6]={765,550,650,350,535,550};
	for (Uint8 j = 0; j < NBTR; j++) {
	/*	for (Uint8 i = 0; i < 3; i++) {
			t[2*i]=Random(10,RES_X-10);
			t[2*i+1]=Random(10,RES_Y-10);
		}*/
		m_trs[j].SetPoint(t,m_l1,m_l2,m_l3);
	}
	Color c1=Red;
	Color c2=Green;
	Color c3=Blue;
	m_trs[0].SetColors(&c1,&c2,&c3);
}
TriangleApp::~TriangleApp() {	
	delete [] m_l1;
	delete [] m_l2;
	delete [] m_l3;
}
void TriangleApp::Draw() {
	m_frames++;
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );
	for (Uint8 i = 0; i < NBTR; i++)
	       	m_trs[i].Draw();
	glFlush();
	SDL_GL_SwapBuffers();
}
