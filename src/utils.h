#ifndef __UTILS
#define __UTILS

#include "conf.h"

const float EPSILON = 0.0005f;

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
	return (rand()/float(RAND_MAX-1))*(max-min)+min;
}
inline bool cmp(float a, float b) {
	if (a > b-EPSILON && a < b+EPSILON)
		return true;
	else
		return false;
}
#endif
