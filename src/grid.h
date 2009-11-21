#ifndef __GRID
#define __GRID
#include <GL/glew.h>
#include "input.h"
#include "object.h"
#include "perlin.h"
#include "wpng.h"

#define BUFFER_OFFSET(a) ((char*)NULL + (a))
const Uint16 N__VERTS = 8;
const Uint16 V__SIZE = 3;
const Uint16 C__SIZE = 3;
const Uint16 NUM__VERTICES = 36;

class Grid : public Object {
	public:
		Grid(Uint16);
		virtual ~Grid();

		void Anim(Uint16, Input*);
		void Draw(SDL_Surface*);	
	private:
		Wpng m_png;
		Perlin m_perlin;
		float *m_vertex;
		float *m_color;
		Uint8 *m_index;
		Uint8 m_heigth;
		Uint8 m_scale;
		Uint8 m_cellspace;
		GLuint m_buf;
		GLuint m_buf_index;

};
#endif /* end of include guard: __GRID */
