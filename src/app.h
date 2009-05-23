#ifndef __APP
#define __APP
#include "conf.h"
#include "line.h"
#include "input.h"
#include "cube.h"
#include <vector>
#include <time.h>
#include <SDL_gfxPrimitives.h>

class App {
	public:
		App(Conf*);
		~App();
		int Run();
	private:
		bool GetInput(SDL_Event*);
		void AddDrawObject(Object*);
		void AddAnimObject(Object*);
		void AddInputObject(Object*);
		std::vector<Object*> m_draw_object;
		std::vector<Object*> m_anim_object;
		std::vector<Object*> m_input_object;
		SDL_Surface *m_screen;
		user_input m_input;
		Line m_line;
		Circle m_circle;
		Uint32 m_time;
		Cube m_cube;
		Cam m_cam;
};
#endif
