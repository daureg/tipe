#ifndef __CONST
#define __CONST
#include <SDL.h>

const Uint16 RES_X = 800;
const Uint16 RES_Y = 600;
const Uint16 SCREEN_SIZE=(RES_X > RES_Y) ? RES_X : RES_Y;
const Uint16 INF16=(2<<15)-1;
const Uint16 MAP_SIZE=256;
const float EPSILON = 0.0005f;
#endif
