#ifndef __APP
#define __APP
#include "conf.h"
#include "input.h"
#include "utils.h"
#include "object.h"
#include <vector>
#include <time.h>
#include <GL/gl.h>
#include <GL/glu.h>
class App {
	public:
		App(Conf*);
		virtual ~App();
		int Run();
	protected:
		virtual void Draw();
		SDL_Surface *m_screen;
		Uint32 m_frames;
	private:
		bool GetInput(SDL_Event*);
		void AddDrawObject(Object*);
		void AddAnimObject(Object*);
		void AddInputObject(Object*);

		std::vector<Object*> m_draw_object;
		std::vector<Object*> m_anim_object;
		std::vector<Object*> m_input_object;
		user_input m_input;
		Uint32 m_time;
};
#endif
