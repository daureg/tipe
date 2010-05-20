#include "facet_app.h"
Vector4 *p1= new Vector4(1.0f,2.0f,3.0f,1.0f);
Material m=Material(White,White,3.0f);
FacetApp::FacetApp():m_facet(Vector4(1.0f,2.0f,3.0f,1.0f),Vector4(1.0f,2.0f,3.0f,1.0f),
		Vector4(1.0f,2.0f,3.0f,1.0f),Vector4(1.0f,2.0f,3.0f,1.0f),Material(White,White,3.0f),Material(White,White,3.0f),Material(White,White,3.0f),(Cam*)NULL,(std::vector<Light*>)NULL) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,RES_X,RES_Y,0);
	glPointSize(8.0f);
	glClearColor(1.0f,1.0f,1.0,0.0f);

	m_ambient = Light(AMBIENT, White, Vector4(.0f,.0f,.0f,.0f), Vector4(3.0f,.0f,.0f,.0f));
	m_lights.push_back(&m_ambient);
	m_facet.SetCam(&m_cam);
	m_facet.SetLights(m_lights);
}
FacetApp::~FacetApp() {}
void FacetApp::Draw() {
	m_frames++;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3ub(0,0,0);
	glVertex2i(50,25);
	glEnd();
	glFlush();
	SDL_GL_SwapBuffers();
}


