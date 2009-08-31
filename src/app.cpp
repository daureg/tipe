#include "app.h"
Uint32 start = 0;
Uint32 m_frames = 0; 
App::App():m_frames(0){
	SDL_Init(SDL_INIT_VIDEO);
	m_screen = SDL_SetVideoMode(RES_X,RES_Y, 32, SDL_OPENGL);
	SDL_WM_SetCaption("TIPE", NULL);
	m_draw_object.reserve(15);
	m_anim_object.reserve(15);
	if (glewInit() == GLEW_OK)
		printf("GL_NV_texgen_emboss is : %s\n",(GLEW_NV_texgen_emboss) ? "OK" : "MISSING");
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
		m_input.ProcessKeyboard(event.key);
		if (m_input.IsPressed("quit"))
			return 0;
		// TODO screenshot
		Draw();
		last=newer;
	}
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
void App::Draw() {
	m_frames++;
	SDL_FillRect(m_screen, NULL, SDL_MapRGBA(m_screen->format, 255, 255, 255,0));
	SDL_UpdateRect(m_screen, 0, 0, 0, 0);
	SDL_Flip(m_screen);
}
