#ifndef __UTILS
#define __UTILS
#include "conf.h"
void ProjectionToSDL(Uint16,Uint16,Uint16,Uint16);
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
	return int((rand()/RAND_MAX)*(max-min)+min);
}
inline float Random(float min, float max) {
	return float((rand()/RAND_MAX)*(max-min)+min);
}
#endif
