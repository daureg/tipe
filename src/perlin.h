#ifndef __PERLIN
#define __PERLIN
#include <SDL.h>
#include "utils.h"
#include <cmath>
const Uint16 PERLIN_SIZE = MAP_SIZE;
class Perlin {
	public:
		Perlin();
		Perlin (Uint16 size, Uint8 octaves, float persistance);
		virtual ~Perlin ();

		float Noise(Uint16, Uint16);
	//private:
		void ligne(int,bool talk=true);
		void somme();
		void FillRandom();
		float InterNoise2D(Uint16, Uint16);
		static float InterCos(float, float, float);
		static float InterCos2D(float, float, float, float, float, float);

		Uint16 m_size;
		Uint8 m_octaves;
		float m_persistance;
		float *m_random;
		float *m_pcache;
		float *m_ligne;
		Uint8 *m_2cache;
		Uint16 m_period;
};
#endif
