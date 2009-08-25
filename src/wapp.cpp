#include "wapp.h"
Wapp::Wapp():m_png("out.png") {
	m_t = new Uint8[PICTURE_SIZE*PICTURE_SIZE];
	for (int i=0;i<PICTURE_SIZE;i++)
		for (int j=0;j<PICTURE_SIZE;j++)
			m_t[256*i+j]=(i*2+j*5)%255;
}
bool Wapp::Run() {return m_png.Write(m_t);}
Wapp::~Wapp() {delete [] m_t;}
