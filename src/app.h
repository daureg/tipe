#ifndef __APP
#define __APP
#include <vector>
#include <time.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "const.h"
#include "input.h"
#include "utils.h"
#include "object.h"

class App {
	public:
		App();
		virtual ~App();
		int Run();
	protected:
		virtual void Draw();
		void AddDrawObject(Object*);
		void AddAnimObject(Object*);

		SDL_Surface *m_screen;
		Uint32 m_frames;
		Input m_input;
		std::vector<Object*> m_draw_object;
		std::vector<Object*> m_anim_object;
		Uint32 m_mode_elapsed;
};
#endif
