#include "app.h"
App::App(Conf *option):m_circle( 300,300,60,255,0,0,255),m_time(SDL_GetTicks()) {
	SDL_Init(SDL_INIT_VIDEO);
	//SDL_EnableKeyRepeat(10, 10);
	srand((unsigned)time(NULL));
	m_screen = SDL_SetVideoMode(option->GetIntOption(ORES_X),
			option->GetIntOption(ORES_Y), 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("TIPE", NULL);
	m_draw_object.reserve(15);
	m_anim_object.reserve(15);
	m_input_object.reserve(15);
	AddDrawObject(&m_circle);
	AddAnimObject(&m_circle);
	AddInputObject(&m_circle);
	m_input.east.active=false;
}
App::~App() {
	SDL_FreeSurface(m_screen);
	SDL_Quit();
}
int App::Run() {
	static Uint32 last=m_time,newer=0;
	static SDL_Event event;
	while (true) {
		newer=SDL_GetTicks();
		SDL_PollEvent(&event);
		if (event.type==SDL_KEYDOWN)
			if (GetInput(&event))
				return 0;
		SDL_Delay(10);
		for (size_t i = 0, size = m_anim_object.size(); i < size; ++i)
			m_draw_object[i]->Anim(newer-last,&m_input);
		SDL_FillRect(m_screen, NULL, SDL_MapRGB(m_screen->format, 255, 255, 255));
		for (size_t i = 0, size = m_draw_object.size(); i < size; ++i)
			m_draw_object[i]->Draw(m_screen);        
		/*for ( size_t i = 0, size = m_input_object.size(); i < size; ++i )
			m_draw_object[i]->Input(&m_input);*/
		SDL_Flip(m_screen);
		last=newer;
	}
}
bool App::GetInput(SDL_Event* ev) {
	switch(ev->key.keysym.sym)
	{
		case SDLK_ESCAPE:
			return true;
		case SDLK_z:
			m_input.north.active=true;
			m_input.north.time=SDL_GetTicks();
			break;
		case SDLK_s:
			m_input.south.active=true;
			m_input.south.time=SDL_GetTicks();
			break;
		case SDLK_q:
			m_input.west.active=true;
			m_input.west.time=SDL_GetTicks();
			break;
		case SDLK_d:
			m_input.east.active=true;
			m_input.east.time=SDL_GetTicks();
			break;
		case SDLK_F12:
			SDL_SaveBMP(m_screen,"screenshot.bmp");
	}
	return false;
}

void App::AddDrawObject(Object* obj) {
	if (m_draw_object.size() >= m_draw_object.capacity())
		m_draw_object.reserve(m_draw_object.size()+15);
	m_draw_object.push_back(obj);
}
void App::AddAnimObject(Object* obj) {
	if (m_anim_object.size() >= m_anim_object.capacity())
		m_anim_object.reserve(m_anim_object.size()+15);
	m_anim_object.push_back(obj);
}
void App::AddInputObject(Object* obj) {
	if (m_input_object.size() >= m_input_object.capacity())
		m_input_object.reserve(m_input_object.size()+15);
	m_input_object.push_back(obj);
}
