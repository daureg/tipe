#ifndef __PERLIN
#define __PERLIN
#include <SDL.h>
#include "utils.h"
#include <cmath>
const Uint16 PERLIN_SIZE = 256;
class Perlin {
	public:
		Perlin();
		Perlin (Uint16 size=PERLIN_SIZE, Uint8 octaves=5, float persistance=0.7f);
		virtual ~Perlin ();

		float Noise(Uint16, Uint16);
	private:
		void FillRandom();
		float InterNoise2D(Uint16, Uint16);
		static float InterCos(float, float, float);
		static float InterCos2D(float, float, float, float, float, float);

		Uint16 m_size;
		Uint8 m_octaves;
		float m_persistance;
		float *m_random;
		float *m_pcache;
		Uint8 *m_2cache;
		Uint16 m_period;
};
#endif
