#include "circle.h"
Circle::Circle(): m_pos_x(0),m_pos_y(0),m_radius(5), m_red(255),m_blue(0),m_green(0), m_alpha(255) {}
Circle::Circle( Uint16 x, Uint16 y, Uint16 radius,
	       	Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha):
        m_pos_x(Clamp(x,0,2000)),m_pos_y(Clamp(y,0,2000)),m_radius(Clamp(radius,0,2000)),
	m_red(Clamp(red,0,255)),m_blue(Clamp(blue,0,255)),m_green(Clamp(green,0,255)),
	m_alpha(Clamp(alpha,0,255)) {}
Circle::~Circle() {}
Uint16 Circle::GetPosX() const { return m_pos_x; }
Uint16 Circle::GetPosY() const { return m_pos_y; }
Uint16 Circle::GetRadius() const { return m_radius; }
Uint8 Circle::GetRed() const { return m_red; }
Uint8 Circle::GetBlue() const { return m_green; }
Uint8 Circle::GetGreen() const { return m_blue; }
Uint8 Circle::GetAlpha() const { return m_alpha; }
void Circle::SetPosX(Uint16 x) { m_pos_x = x; }
void Circle::SetPosY(Uint16 y) { m_pos_y = y; }
void Circle::SetRadius(Uint16 r) { m_radius = r; }
void Circle::SetRed(Uint8 r) { m_red = r; }
void Circle::SetBlue(Uint8 b) { m_blue = b; }
void Circle::SetGreen(Uint8 g) { m_green = g; }
void Circle::SetAlpha(Uint8 a) { m_alpha = a; }

void Circle::Draw(SDL_Surface* screen) { filledCircleRGBA(screen, m_pos_x, m_pos_y,
	       m_radius, m_red,m_green,m_blue,m_alpha); }
void Circle::Anim(Uint16 elapsed, Input* ui) {}
