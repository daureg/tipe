#ifndef __CONF
#define __CONF
#include <SDL.h>

const Uint16 RES_X = 800;
const Uint16 RES_Y = 600;
const Uint16 SIZE=(RES_X > RES_Y) ? RES_X : RES_Y;
const Uint16 INF16=(2<<15)-1;
const Uint16 MAP_SIZE=256;
enum option {
	ORES_X,
	ORES_Y
};

class Conf {
	public:
		Conf();
		~Conf();
		Uint16 GetIntOption(int);
	private:
		Uint16 m_res_x;
		Uint16 m_res_y;
};

#endif
