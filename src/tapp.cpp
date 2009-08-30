#include "tapp.h"
Tapp::Tapp(Conf *c):App(c) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,c->GetIntOption(ORES_X),c->GetIntOption(ORES_Y),0);
	m_l1 = new Uint16[SIZE];
	m_l2 = new Uint16[SIZE];
	m_l3 = new Uint16[SIZE];
	Uint16 t[6]={700,500,650,400,550,450};
	for (Uint8 j = 0; j < NBTR; j++) {
		for (Uint8 i = 0; i < 3; i++) {
			t[2*i]=Random(10,c->GetIntOption(ORES_X)-10);
			t[2*i+1]=Random(10,c->GetIntOption(ORES_Y)-10);
		}
		m_trs[j].SetPoint(t,m_l1,m_l2,m_l3);
	}

}
Tapp::~Tapp() {	
	delete [] m_l1;
	delete [] m_l2;
	delete [] m_l3;
}
void Tapp::Draw() {
	m_frames++;
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );
	glPushMatrix();
	for (Uint8 i = 0; i < NBTR; i++)
	       	m_trs[i].DrawGL(5*i);
	glPopMatrix();
	glFlush();
	SDL_GL_SwapBuffers();
}
