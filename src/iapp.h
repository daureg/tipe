#ifndef __I2APP
#define __I2APP
#include "input.h"
#include "object.h"
#include "conf.h"
#include <vector>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
class Iapp {
	public:
		Iapp(Conf*);
		virtual ~Iapp();
		int Run();
	private:
		void Draw();
		void AddDrawObject(Object*);
		void AddAnimObject(Object*);

		SDL_Surface *m_screen;
		Uint32 m_frames;
		std::vector<Object*> m_draw_object;
		std::vector<Object*> m_anim_object;
		Input m_input;
};
#endif
