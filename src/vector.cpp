#include "vector.h"
Vector4::Vector4(): _x(0.0f), _y(0.0f), _z(0.0f), _w(0.0f) {}
Vector4::Vector4(float f): _x(f), _y(f), _z(f), _w(f) {}
Vector4::Vector4(float x, float y, float z, float w): _x(x), _y(y), _z(z), _w(w) {}
Vector4::~Vector4() {}

Vector4 Vector4::operator-() const { return Vector4(-_x,-_y,-_z,-_w); }
Vector4 Vector4::operator+(const Vector4 &v) const {
	return Vector4(v(1)+_x, v(2)+_y, v(3)+_z, v(4)+_w);
}
Vector4 Vector4::operator-(const Vector4 &v) const {
	return Vector4(v(1)-_x, v(2)-_y, v(3)-_z, v(4)-_w);
}
Vector4 Vector4::operator*(const float &f) const {
	return Vector4(f*_x, f*_y, f*_z, f*_w);
}
Vector4 Vector4::operator*(const Vector4 &v) const {
	return Vector4(_y*v(3)-_z*v(2), _z*v(1)-_x*v(3), _x*v(2)-_y*v(1),_w);
}
float Vector4::operator/(const Vector4 &v) const {
	return _x*v(1)+_y*v(2)+_z*v(3);
}
bool Vector4::operator==(const Vector4 &v) const {
	return (cmp(_x,v(1)) && cmp(_y,v(2)) && cmp(_z,v(3)) && cmp(_w,v(4)));
}
bool Vector4::operator!=(const Vector4 &v) const { 
	return !(cmp(_x,v(1)) && cmp(_y,v(2)) && cmp(_z,v(3)) && cmp(_w,v(4)));
}
float Vector4::operator() (Uint8 c) const {
	switch (c) {
		case 1:
			return _x;
		case 2:
			return _y;
		case 3:
			return _z;
		case 4:
			return _w;
	}
}
float Vector4::Component(Uint8 c) const {
	switch (c) {
		case 1:
			return _x;
		case 2:
			return _y;
		case 3:
			return _z;
		case 4:
			return _w;
	}
}
float Vector4::Norm() const { return std::sqrt(_x*_x+_y*_y+_z*_z);}
Vector4 Vector4::Normalize() { 
	float f=1/std::sqrt(_x*_x+_y*_y+_z*_z);
	return Vector4(f*_x, f*_y, f*_z, _w);
}
void Vector4::Print() const { printf("[ %f, %f, %f, %f]\n",_x,_y,_z,_w); }
Vector4 Vector4::Null() { return Vector4(); }
