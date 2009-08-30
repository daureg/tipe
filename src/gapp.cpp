#include "gapp.h"

Gapp::Gapp(Conf *c):App(c),m_cam(Vector4(0,0,5,0)),
		_r(Vector4(1.0f,0.0f,0.0f,0.0f)),_p(Vector4(0.0f,0.0f,5.0f,0.0f)),_l(Vector4(0.0f,0.0f,-1.0f,0.0f)) {
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(70,(double)c->GetIntOption(ORES_X)/c->GetIntOption(ORES_Y),.1f,100);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	/* nombre de sommets */



}

Gapp::~Gapp() {}
bool Gapp::GetInput(SDL_Event* event) {
	switch(event->type)
	{
		case SDL_QUIT:
			return true;
		case SDL_KEYDOWN:
			switch (event->key.keysym.sym)
			{
				case SDLK_F12:
					SDL_SaveBMP(m_screen,"screenshot.bmp");
					break;
				case SDLK_ESCAPE:
					return true;
				default :
					m_cam.OnKeyboard(event->key);
			}
			break;
		case SDL_KEYUP:
			m_cam.OnKeyboard(event->key);
			break;
		case SDL_MOUSEMOTION:
			m_cam.OnMouseMotion(event->motion);
			break;
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEBUTTONDOWN:
			m_cam.OnMouseButton(event->button);
			break;
	}
	return false;
}
int Gapp::Run() {
	static Uint32 last=0,newer=0;
	static SDL_Event event;
	const Uint32 time_per_frame = 1000/FPS;

	Uint32 last_time,current_time,elapsed_time; //for time animation
	Uint32 start_time,stop_time; //for frame limit;
	//start = SDL_GetTicks();
	last_time = SDL_GetTicks();
	while (true) {
		newer=SDL_GetTicks();
		start_time = SDL_GetTicks();
		SDL_PollEvent(&event);
		//if (event.type==SDL_KEYDOWN)
			if (GetInput(&event))
				return 0;
		//SDL_Delay(20);
		current_time = SDL_GetTicks();
		elapsed_time = current_time - last_time;
		last_time = current_time;

		m_cam.animate(elapsed_time);
		Draw();
		_p = _p - (_r*0.01f);
		/*
		_l = _l + _r*.001f;
		_l.Normalize();
		*/

		stop_time = SDL_GetTicks();
		if ((stop_time - last_time) < time_per_frame)
		{
			SDL_Delay(time_per_frame - (stop_time - last_time));
		}

	}
}
void Gapp::Draw() {
	m_frames++;
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );

	m_cam.look();

	glBegin(GL_QUADS);
	glColor3ub(255,0,0); glVertex3d(1,1,1); glVertex3d(1,1,-1); glVertex3d(-1,1,-1); glVertex3d(-1,1,1); glColor3ub(0,255,0); glVertex3d(1,-1,1); glVertex3d(1,-1,-1); glVertex3d(1,1,-1); glVertex3d(1,1,1); glColor3ub(0,0,255); glVertex3d(-1,-1,1); glVertex3d(-1,-1,-1); glVertex3d(1,-1,-1); glVertex3d(1,-1,1); glColor3ub(255,255,0); glVertex3d(-1,1,1); glVertex3d(-1,1,-1); glVertex3d(-1,-1,-1); glVertex3d(-1,-1,1); glColor3ub(0,255,255); glVertex3d(1,1,-1); glVertex3d(1,-1,-1); glVertex3d(-1,-1,-1); glVertex3d(-1,1,-1); glColor3ub(255,0,255); glVertex3d(1,-1,1); glVertex3d(1,1,1); glVertex3d(-1,1,1); glVertex3d(-1,-1,1);
	glEnd();

	glFlush();
	SDL_GL_SwapBuffers();

}
