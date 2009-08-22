#include "app.h"
Uint32 start = 0;
Uint32 m_frames = 0; 
App::App(Conf *option):m_frames(0){
	SDL_Init(SDL_INIT_VIDEO);
	m_screen = SDL_SetVideoMode(option->GetIntOption(ORES_X),
			option->GetIntOption(ORES_Y), 32, SDL_OPENGL);
	SDL_WM_SetCaption("TIPE", NULL);
	m_draw_object.reserve(15);
	m_anim_object.reserve(15);
	m_input_object.reserve(15);
}
App::~App() {
	printf("FPS : %.2f\n",float(1000*m_frames)/SDL_GetTicks());
	SDL_FreeSurface(m_screen);
	SDL_Quit();
}
int App::Run() {
	static Uint32 last=m_time,newer=0;
	static SDL_Event event;
	start = SDL_GetTicks();
	while (true) {
		newer=SDL_GetTicks();
		SDL_PollEvent(&event);
		if (event.type==SDL_KEYDOWN)
			if (GetInput(&event))
				return 0;
		//SDL_Delay(300);
		Draw();
		last=newer;
	}
}
	bool App::GetInput(SDL_Event* ev) {
		switch(ev->key.keysym.sym)
		{
			case SDLK_ESCAPE:
				return true;
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
void App::Draw() {
	m_frames++;
	SDL_FillRect(m_screen, NULL, SDL_MapRGBA(m_screen->format, 255, 255, 255,0));
	SDL_UpdateRect(m_screen, 0, 0, 0, 0);
	SDL_Flip(m_screen);
}
