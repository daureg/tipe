#ifndef __PERLIN_APP
#define __PERLIN_APP
#include "wpng.h"
#include "perlin.h"
class PerlinApp {
	public:
		PerlinApp();
		virtual ~PerlinApp();
		bool Run();
	private:
		Wpng m_png;
		Uint8 *m_t;
		Perlin m_perlin;
};
#endif
