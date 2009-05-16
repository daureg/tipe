#ifndef __OBJECT
#define __OBJECT
#include "input.h"
class Object {
	public:
		Object();
		~Object();
		virtual void Draw(SDL_Surface*)=0;
		virtual void Input(user_input*)=0;
		virtual void Anim(Uint16,user_input*)=0;
};
#endif
