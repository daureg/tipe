#ifndef __COLOR
#define __COLOR
#include "utils.h"
class Color {
	public:
		Color();
		Color(Uint8);
		Color(float);
		Color(Uint8,Uint8,Uint8);
		Color(float,float,float);
		Color(const Color &v);
		virtual ~Color();

		Color operator+(const Color &) const;
		Color operator-(const Color &) const;
		Color operator*(const float &) const;
		Color operator*(const Color &) const;
		float operator()(Uint8) const;
		bool operator==(const Color &) const;
		bool operator!=(const Color &) const;
		void Print() const;

	private:
		float _r;
		float _g;
		float _b;
};
static const Color White=Color(1.0f,1.0f,1.0f);
static const Color Red=Color(1.0f,0.0f,0.0f);
static const Color Blue=Color(0.0f,0.0f,1.0f);
#endif
