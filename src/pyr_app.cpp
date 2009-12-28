#include "pyr_app.h"
PyrApp::PyrApp():m_pyr(2.0f,Vector4(0.0f,-1.0f,-3.0f,0.0f),m_cam) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,RES_X,RES_Y,0);
	glPointSize(8.0f);
	glClearColor(1.0f,1.0f,1.0,0.0f);
	AddAnimObject(&m_cam);
}
PyrApp::~PyrApp() {}
void PyrApp::Draw() {
	m_frames++;
	Vector4 temoin = Vector4(0.0f,0.0f,0.0f,1.0f);
	Vector4 rs;
	Uint16 x,y;
	rs=m_cam.Proj(&temoin);
	/*if (m_frames%2000==0)
		printf("%f\n",(m_pos-m_cam.GetPos()).Norm());*/
	x=(rs(1)/rs(4)+1)*(RES_X)/2;
	y=(rs(2)/rs(4)+1)*(RES_Y)/2;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/
	/*
	if (m_frames%2000==0) {
		m_pyr.Move(Vector4(-0.5f,0.3f,0.8f,1.0f));
		m_pyr.Scale(1.0f);
	}
	*/
	m_pyr.TDraw(&m_cam);
	glBegin(GL_POINTS);
	glColor3ub(0,0,0);
	glVertex2i(x,y);
	glEnd();
	glFlush();
	SDL_GL_SwapBuffers();
}

