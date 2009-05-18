#ifndef __CIRCLE
#define __CIRCLE
#include <SDL_gfxPrimitives.h>
#include "object.h"
#include "utils.h"
#include "input.h"

class Circle : public Object {
	public:
		Circle();
		Circle(Uint16, Uint16, Uint16, Uint8, Uint8, Uint8, Uint8);
		~Circle();
		virtual void Draw(SDL_Surface*);
		virtual void Anim(Uint16,user_input*);
		virtual void Input(user_input*);
		Uint16 GetPosX() const;
		Uint16 GetPosY() const;
		Uint16 GetRadius() const;
		Uint8 GetRed() const;
		Uint8 GetBlue() const;
		Uint8 GetGreen() const;
		Uint8 GetAlpha() const;
		void SetPosX(Uint16);
		void SetPosY(Uint16);
		void SetRadius(Uint16);
		void SetRed(Uint8);
		void SetBlue(Uint8);
		void SetGreen(Uint8);
		void SetAlpha(Uint8);
	private:
		Uint16 m_pos_x;
		Uint16 m_pos_y;
		Uint16 m_radius;
		Uint8 m_red;
		Uint8 m_blue;
		Uint8 m_green;
		Uint8 m_alpha;
};
#endif
