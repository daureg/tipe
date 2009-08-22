#include "line.h"
Line::Line(): m_pos_x1(0),m_pos_y1(0),m_pos_x2(0),m_pos_y2(0),m_red(255),m_blue(0),m_green(0),m_alpha(255) {}
Line::Line( Uint16 x1, Uint16 y1, Uint16 x2, Uint16 y2,
		Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha):
	m_pos_x1(Clamp(x1,0,2000)),m_pos_y1(Clamp(y1,0,2000)),
	m_pos_x2(Clamp(x2,0,2000)),m_pos_y2(Clamp(y2,0,2000)),
	m_red(Clamp(red,0,255)),m_blue(Clamp(blue,0,255)),m_green(Clamp(green,0,255)),
	m_alpha(Clamp(alpha,0,255)) {}
	Line::~Line() {}
Uint16 Line::GetPosX1() const { return m_pos_x1; }
Uint16 Line::GetPosY1() const { return m_pos_y1; }
Uint16 Line::GetPosX2() const { return m_pos_x2; }
Uint16 Line::GetPosY2() const { return m_pos_y2; }
Uint8 Line::GetRed() const { return m_red; }
Uint8 Line::GetBlue() const { return m_green; }
Uint8 Line::GetGreen() const { return m_blue; }
Uint8 Line::GetAlpha() const { return m_alpha; }
void Line::SetPosX1(Uint16 x) { m_pos_x1 = x; }
void Line::SetPosY1(Uint16 y) { m_pos_y1 = y; }
void Line::SetPosX2(Uint16 x) { m_pos_x2 = x; }
void Line::SetPosY2(Uint16 y) { m_pos_y2 = y; }
void Line::SetRed(Uint8 r) { m_red = r; }
void Line::SetBlue(Uint8 b) { m_blue = b; }
void Line::SetGreen(Uint8 g) { m_green = g; }
void Line::SetAlpha(Uint8 a) { m_alpha = a; }
void Line::Draw(SDL_Surface* screen) {
//aalineRGBA(screen,m_pos_x1,m_pos_y1,m_pos_x2,m_pos_y2,m_red,m_green,m_blue,m_alpha);
	Sint16 dx,dy,cumul,x,y,xinc,yinc,i;
	x = m_pos_x1;
	y = m_pos_y1;
	dx = m_pos_x2 - m_pos_x1;
	dy = m_pos_y2 - m_pos_y1;
	xinc = ( dx > 0 ) ? 1 : -1;
	yinc = ( dy > 0 ) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	pixelRGBA(screen,x,y,m_red,m_green,m_blue,m_alpha);
	if ( dx > dy ) {
		cumul = dx / 2;
		for (i = 0; i < dx; i++) {
			x += xinc;
			cumul += dy;
			if (cumul >= dx) {
				cumul -= dx;
				y += yinc;
			}
			pixelRGBA(screen,x,y,m_red,m_green,m_blue,m_alpha);
		} 
	}
	else {
		cumul = dy / 2;
		for (i = 0; i < dy; i++) {
			y += yinc;
			cumul += dx;
			if (cumul > dy) {
				cumul -= dy;
				x += xinc; 
			}
			pixelRGBA(screen,x,y,m_red,m_green,m_blue,m_alpha); 
		} 
	}
}
void Line::Anim(Uint16 elapsed, user_input* ui) { }
void Line::Input(user_input* ui) {}
