#include "utils.h"
void ProjectionToSDL(Uint16 ox, Uint16 oy, Uint16 &nx, Uint16 &ny) {
	nx = (RES_X/2)*(ox+1);
	ny = (RES_Y/2)*(oy+1);
}
