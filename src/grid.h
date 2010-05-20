#ifndef __GRID
#define __GRID
#include <GL/glew.h>
#include "object.h"
#include "perlin.h"
#include "color.h"
#include "wpng.h"

#define BUFFER_OFFSET(a) ((char*)NULL + (a))
const Uint16 V__SIZE = 3;
const Uint16 C__SIZE = 3;

const Color SAND_BEACH=Color(1.0f,.875f,.5f);
const Color PURE_GREEN=Color(.0f,1.0f,.0f);
const Color DARK_GREEN=Color(.375f,.5f,.0f);
const Color ROCK_LIGHT=Color(.25f,.5f,.44f);
const Color SNOW=Color(1.0f,1.0f,.77f);
const Color BLACK=Color(1.0f,1.0f,1.0);

const Uint8 LEVEL1=64,LEVEL2=112,LEVEL3=146;

class Grid : public Object {
	public:
		Grid(Uint16);
		virtual ~Grid();

		void Anim(Uint16, Input*);
		void Draw(SDL_Surface*);	
	private:
		Color MakeColor(Uint16, Uint16) const;
		float MakeSlope(Uint16, Uint16);

		Wpng m_png;
		Perlin m_perlin;
		float *m_vertex;
		float *m_color;
		Uint32 *m_index;
		Uint8 *m_height;
		float *m_slope;
		float m_scale;
		float m_cellspace;
		GLuint m_buf;
		GLuint m_buf_index;
		Uint32 m_nb_vert;
		Uint32 m_nb_idx;
		float m_max_slope;
		float m_min_slope;
		Uint16 m_size;

		int m_stat[32];

};
#endif
