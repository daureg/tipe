#ifndef __PAPP
#define __PAPP
#include "wpng.h"
#include "perlin.h"
class Papp {
	public:
		Papp();
		virtual ~Papp();
		bool Run();
	private:
		Wpng m_png;
		Uint8 *m_t;
		Perlin m_perlin;
};
#endif
