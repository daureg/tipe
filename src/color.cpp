#include "color.h"

Color::Color():_r(1.0f),_g(1.0f),_b(1.0f) {}
Color::Color(Uint8 c):_r(Clamp(c/255.0f,0.0f,1.0f)),_g(Clamp(c/255.0f,0.0f,1.0f)),
	_b(Clamp(c/255.0f,0.0f,1.0f)) {}
Color::Color(float f):_r(Clamp(f,0.0f,1.0f)),_g(Clamp(f,0.0f,1.0f)),_b(Clamp(f,0.0f,1.0f)) {}
Color::Color(Uint8 r, Uint8 g, Uint8 b):_r(Clamp(r/255.0f,0.0f,1.0f)),_g(Clamp(g/255.0f,0.0f,1.0f)),
	_b(Clamp(b/255.0f,0.0f,1.0f)) {}
Color::Color(float r, float g, float b):_r(Clamp(r,0.0f,1.0f)),_g(Clamp(g,0.0f,1.0f)),_b(Clamp(b,0.0f,1.0f)) {}
Color::Color(const Color &c) { 
	_r=c(1);
	_g=c(2);
	_b=c(3);
}
Color::~Color() {}

void Color::Change(Uint8 r, Uint8 g, Uint8 b) { 
	_r=Clamp(r/255.0f,0.0f,1.0f);
	_g=Clamp(g/255.0f,0.0f,1.0f);
	_b=Clamp(b/255.0f,0.0f,1.0f);
}
void Color::Change(float r, float g, float b) {
	_r=Clamp(r,0.0f,1.0f);
	_g=Clamp(g,0.0f,1.0f);
	_b=Clamp(b,0.0f,1.0f);
}

Color Color::operator+(const Color &v) const { return Color(1.0f*(v(1)+_r), 1.0f*(v(2)+_g), 1.0f*(v(3)+_b)); }
Color Color::operator-(const Color &v) const { return Color(_r-v(1),_g-v(2),_b-v(3)); }
Color Color::operator*(const float &f) const { return Color(f*_r, f*_g, f*_b); }
bool Color::operator==(const Color &v) const { return (cmp(_r,v(1)) && cmp(_g,v(2)) && cmp(_b,v(3))); }
bool Color::operator!=(const Color &v) const { return !(cmp(_r,v(1)) && cmp(_g,v(2)) && cmp(_b,v(3))); }

float Color::operator() (Uint8 c) const {
       switch (Clamp(c,1,3)) {
	       case 1: return _r; break;
	       case 2: return _g; break;
	       case 3: return _b; break;
       }
}
void Color::Print() const { printf("[%.3f, %.3f, %.3f]\n",_r,_g,_b); }
