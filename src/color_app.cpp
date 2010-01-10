#include "color_app.h"
ColorApp::ColorApp():m_rouge(0.8f,1.0f,0.0f),m_jaune(0.6f,0.0f,0.0f) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,RES_X,RES_Y,0);
	m_test = m_rouge + m_jaune;
	m_test.Print();
}
ColorApp::~ColorApp() {}
void ColorApp::Draw() {
	m_frames++;
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glColor3f(m_test(1),m_test(2),m_test(3));
	glBegin(GL_TRIANGLES);
	glVertex2i(460,150);
	glVertex2i(60,150);
	glVertex2i(260,450);
	glEnd();
	glColor3f(.8f+.6f,1.0f,0.0f);
	glBegin(GL_TRIANGLES);
	glVertex2i(330,450);
	glVertex2i(730,450);
	glVertex2i(530,150);
	glEnd();
	glFlush();
	SDL_GL_SwapBuffers();
}
