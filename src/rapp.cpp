#include "rapp.h"
Rapp::Rapp():m_png("map.png") {
	const Uint8 *tb = m_png.Read();
	printf("%d\n",tb[58]);
}
int Rapp::Run() {return 1;}
Rapp::~Rapp() {}
