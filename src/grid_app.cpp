#include "grid_app.h"
GridApp::GridApp():m_cam(&Vector4(0,0,5,0)),m_grid(32) {
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(70,(double)RES_X/RES_Y,.1f,100);
	glEnable(GL_DEPTH_TEST);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	AddAnimObject(&m_cam);
}

GridApp::~GridApp() {
}
void GridApp::Draw() {
	m_frames++;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	m_cam.Look();
	m_grid.Draw(NULL);
	glFlush();
	SDL_GL_SwapBuffers();

}
