#include "conf.h"
Conf::Conf():m_res_x(RES_X),m_res_y(RES_Y){}
Conf::~Conf(){}
Uint16 Conf::GetIntOption(int option)
{
	switch(option) {
		case ORES_X:
			return m_res_x;
		case ORES_Y:
			return m_res_y;
		default:
			return 0;
	}
}
