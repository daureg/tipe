#include "app.h"
App::App():m_frames(0){
	SDL_Init(SDL_INIT_VIDEO);
	m_screen = SDL_SetVideoMode(RES_X,RES_Y, 32, SDL_OPENGL);
	SDL_WM_SetCaption("TIPE", NULL);
	m_draw_object.reserve(15);
	m_anim_object.reserve(15);
	glewInit();
}
App::~App() {
	printf("FPS : %.2f\n",float(1000*m_frames)/SDL_GetTicks());
	SDL_FreeSurface(m_screen);
	SDL_Quit();
}
int App::Run() {
	static SDL_Event event;
	bool run = GLEW_ARB_vertex_buffer_object;
	Uint32 last_time,current_time,elapsed_time;
	last_time = SDL_GetTicks();
	while (run) {
		/* Get input */
		SDL_PollEvent(&event);
		m_input.ProcessKeyboard(event.key);
		/* Process generic event */
		if (m_input.IsPressed("quit"))
			return EXIT_SUCCESS;
		if (m_input.IsPressed("screenshot"))
			Screenshot();

		/* Process object event */		
		current_time = SDL_GetTicks();
		elapsed_time = current_time - last_time;
		last_time = current_time;
		Draw();
	}
	fprintf(stderr,"You don't have the GL_ARB_vertex_buffer_object extension\n");
	return EXIT_FAILURE;
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
