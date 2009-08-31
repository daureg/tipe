#include "iapp.h"
Uint32 m_iframes = 0; 
Iapp::Iapp():m_frames(0){
	SDL_Init(SDL_INIT_VIDEO);
	m_screen = SDL_SetVideoMode(RES_X, RES_Y, 32, SDL_OPENGL);
	SDL_WM_SetCaption("Input", NULL);
	m_draw_object.reserve(15);
	m_anim_object.reserve(15);
	if (glewInit() == GLEW_OK)
		printf("GL_NV_texgen_emboss is : %s\n",(GLEW_NV_texgen_emboss) ? "OK" : "MISSING");
}
Iapp::~Iapp() {
	printf("FPS : %.2f\n",float(1000*m_iframes)/SDL_GetTicks());
	SDL_FreeSurface(m_screen);
	SDL_Quit();
}
int Iapp::Run() {
	static SDL_Event event;
	while (true) {
		SDL_PollEvent(&event);
		m_input.ProcessKeyboard(event.key);
		if (m_input.IsPressed("quit"))
			return 0;
		if (m_input.IsPressed("forward"))
			printf("En avant ! (%.2f)\n",float(1000*m_iframes)/SDL_GetTicks());
		Draw();
	}
}
void Iapp::AddDrawObject(Object* obj) {
	if (m_draw_object.size() >= m_draw_object.capacity())
		m_draw_object.reserve(m_draw_object.size()+15);
	m_draw_object.push_back(obj);
}
void Iapp::AddAnimObject(Object* obj) {
	if (m_anim_object.size() >= m_anim_object.capacity())
		m_anim_object.reserve(m_anim_object.size()+15);
	m_anim_object.push_back(obj);
}
void Iapp::Draw() {
	m_iframes++;
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );
	gluLookAt(3,4,2,0,0,0,0,0,1);
	glBegin(GL_QUADS);
	glColor3ub(255,0,0); glVertex3d(1,1,1); glVertex3d(1,1,-1); glVertex3d(-1,1,-1); glVertex3d(-1,1,1); glColor3ub(0,255,0); glVertex3d(1,-1,1); glVertex3d(1,-1,-1); glVertex3d(1,1,-1); glVertex3d(1,1,1); glColor3ub(0,0,255); glVertex3d(-1,-1,1); glVertex3d(-1,-1,-1); glVertex3d(1,-1,-1); glVertex3d(1,-1,1); glColor3ub(255,255,0); glVertex3d(-1,1,1); glVertex3d(-1,1,-1); glVertex3d(-1,-1,-1); glVertex3d(-1,-1,1); glColor3ub(0,255,255); glVertex3d(1,1,-1); glVertex3d(1,-1,-1); glVertex3d(-1,-1,-1); glVertex3d(-1,1,-1); glColor3ub(255,0,255); glVertex3d(1,-1,1); glVertex3d(1,1,1); glVertex3d(-1,1,1); glVertex3d(-1,-1,1);
	glEnd();
	glFlush();
	SDL_GL_SwapBuffers();
}
