#include "proj_app.h"
ProjApp::ProjApp():m_pos(Vector4(1.0f,0.0f,-5.0f,1.0f)) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,RES_X,RES_Y,0);
	glPointSize(10.0f);
	glClearColor(1.0f,1.0f,1.0,0.0f);
	AddAnimObject(&m_cam);
}
ProjApp::~ProjApp() {}
void ProjApp::Draw() {
	m_frames++;
	Vector4 rs;
	float d=(m_pos-m_cam.GetPos()).Norm();
	glPointSize(50.0f/d);
	Uint16 x,y;
	rs=m_cam.Proj(&m_pos);
	x=(rs(1)/rs(4)+1)*(RES_X)/2;
	y=(rs(2)/rs(4)+1)*(RES_Y)/2;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_POINTS);
	glColor3ub(255,0,0);
	glVertex2i(x,y);
	glEnd();
	glFlush();
	SDL_GL_SwapBuffers();
}

