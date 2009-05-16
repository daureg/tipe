#ifndef __CONF
#define __CONF
#include <SDL.h>

const Uint16 RES_X = 800;
const Uint16 RES_Y = 600;
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
