#ifndef __LINE
#define __LINE
#include <SDL_gfxPrimitives.h>
#include "object.h"
#include "utils.h"
#include "input.h"

class Line : public Object {
	public:
		Line();
		Line(Uint16,Uint16,Uint16,Uint16,Uint8,Uint8,Uint8,Uint8);
		~Line();
		virtual void Draw(SDL_Surface*);
		virtual void Anim(Uint16,user_input*);
		virtual void Input(user_input*);
		Uint16 GetPosX1() const;
		Uint16 GetPosY1() const;
		Uint16 GetPosX2() const;
		Uint16 GetPosY2() const;
		Uint8 GetRed() const;
		Uint8 GetBlue() const;
		Uint8 GetGreen() const;
		Uint8 GetAlpha() const;
		void SetPosX1(Uint16);
		void SetPosY1(Uint16);
		void SetPosX2(Uint16);
		void SetPosY2(Uint16);
		void SetRed(Uint8);
		void SetBlue(Uint8);
		void SetGreen(Uint8);
		void SetAlpha(Uint8);
	private:
		Uint16 m_pos_x1;
		Uint16 m_pos_y1;
		Uint16 m_pos_x2;
		Uint16 m_pos_y2;
		Uint8 m_red;
		Uint8 m_blue;
		Uint8 m_green;
		Uint8 m_alpha;
};
#endif
