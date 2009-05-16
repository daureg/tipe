#ifndef __INPUT
#define __INPUT
#include <SDL.h>
struct cmd {
	bool active;
	Uint32 time;
};
struct user_input {
	cmd north;
	cmd south;
	cmd west;
	cmd east;
};
#endif
