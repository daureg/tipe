#include "perlin.h"
Perlin::Perlin():m_size(PERLIN_SIZE), m_octaves(5), m_persistance(0.3f), m_period(m_size/2) {
	this->FillRandom();
}
Perlin::Perlin(Uint16 size, Uint8 oct, float per):
	m_size(size), m_octaves(oct), m_persistance(per), m_period(size/2) {
	this->FillRandom();
}
Perlin::~Perlin() { delete [] m_random; }

float Perlin::Noise(Uint16 x, Uint16 y) {
	float perlin = 0.0f;
	for(Uint8 i = 0;i<m_octaves;i++) 
		perlin += this->InterNoise2D(x*pow(2,i),y*pow(2,i)) * pow(m_persistance, i);
	return perlin;
}
float Perlin::InterNoise2D(Uint16 x, Uint16 y) {
	Uint16 i = x/m_period;
	Uint16 j = y/m_period;
	return Perlin::InterCos2D(m_random[m_size*i+j], m_random[m_size*i+j+1],
		       	m_random[m_size*(i+1)+j], m_random[m_size*(i+1)+j+1],
			y%m_period/float(m_period), x%m_period/float(m_period));
}
float Perlin::InterCos(float a, float b, float x) {
	float k = (1 - cos(x*M_PI)) / 2;
	return a*(1-k)+b*k;
}
float Perlin::InterCos2D(float a, float b, float c, float d, float x, float y) {
	return Perlin::InterCos(InterCos(a,b,x),InterCos(c,d,x),y);
}
void Perlin::FillRandom() {
	m_random = new float[m_size*m_size];
	Uint32 max = (2<<31)-1;
	printf("Start filling random...\n");
	for (Uint32 i = 0; i<m_size*m_size; i++)
		m_random[i] = rand()/float(max);
	printf("Done !\n");
}

