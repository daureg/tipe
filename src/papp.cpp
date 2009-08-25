#include "papp.h"
Papp::Papp():m_png("perlin.png"),m_perlin(256,5,0.7f) {
	m_t = new Uint8[PICTURE_SIZE*PICTURE_SIZE];
	for (int i=0;i<PICTURE_SIZE;i++)
		for (int j=0;j<PICTURE_SIZE;j++)
			m_t[256*i+j]=220*m_perlin.Noise(i,j);
}
bool Papp::Run() {return m_png.Write(m_t);}
Papp::~Papp() {delete [] m_t;}
