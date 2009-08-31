#ifndef __UTILS
#define __UTILS
#include <cmath>
#include <GL/gl.h>
#include "const.h"

void Screenshot(SDL_Surface *s=NULL);

inline int Clamp(int value,int min, int max) {
	if (value > max)
		return max;
	if (value < min)
		return min;
	return value;
}
inline float Clamp(float value,float min, float max) {
	if (value > max)
		return max;
	if (value < min)
		return min;
	return value;
}
inline int Random(int min, int max) {
	return int((rand()/float(RAND_MAX-1))*(max-min)+min);
}
inline float Random(float min, float max) {
	return (rand()/float(RAND_MAX-1))*(max-min)+min;
}
inline float RadToDeg(float a) { return 180.0f*a/M_PI; }
inline float DegToRad(float a) { return a*M_PI/180.0f; }
inline bool cmp(float a, float b) {
	if (a > b-EPSILON && a < b+EPSILON)
		return true;
	else
		return false;
}
inline void Swap(float *t,Uint8 r1,Uint8 c1,Uint8 r2,Uint8 c2) {
	float tmp = t[r1*4+c1];
	t[r1*4+c1] = t[r2*4+c2];
	t[r2*4+c2] = tmp;
}
inline void Swap(Uint8 *t,Uint8 a,Uint8 b) {
	Uint8 tmp = t[a];
	t[a] = t[b];
	t[b] = tmp;
}
#endif
