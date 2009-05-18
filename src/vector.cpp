#include "vector.h"
Vector4::Vector4(): _x(0.0f), _y(0.0f), _z(0.0f), _w(1) {}
Vector4::Vector4(float f): _x(f), _y(f), _z(f), _w(1) {}
Vector4::Vector4(float x, float y, float z, Uint8 w): _x(x), _y(y), _z(z), _w(w) {}
Vector4::~Vector4() {}

float Vector4::x() const { return _x; }
float Vector4::y() const { return _y; }
float Vector4::z() const { return _z; }
Uint8 Vector4::w() const { return _w; }

Vector4 Vector4::operator+(const Vector4 &v) {
	return Vector4(v.x()+_x, v.y()+_y, v.z()+_z, v.w()+_w);
}
Vector4 Vector4::operator-(const Vector4 &v) {
	return Vector4(v.x()-_x, v.y()-_y, v.z()-_z, v.w()-_w);
}
Vector4 Vector4::operator*(const float &f) {
	return Vector4(f*_x, f*_y, f*_z, _w);
}
Vector4 Vector4::operator*(const Vector4 &v) {
	return Vector4(_y*v.z()-_z*v.y(), _z*v.x()-_x*v.z(), _x*v.y()-_y*v.x(),_w);
}
float Vector4::operator/(const Vector4 &v) {
	return _x*v.x()+_y*v.y()+_z*v.z();
}
bool Vector4::operator==(const Vector4 &v) {
	return (cmp(_x,v.x()) && cmp(_y,v.y()) && cmp(_z,v.z()) && _w==v.w());
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
			return float(_w);
		default:
			return 0.0f;
	}
}
float Vector4::Norm() const { return std::sqrt(_x*_x+_y*_y+_z*_z);}
Vector4 Vector4::Normalize() { float f=1/std::sqrt(_x*_x+_y*_y+_z*_z);return Vector4(f*_x, f*_y, f*_z, _w);}
void Vector4::Print() const { printf("[ %f, %f, %f, %d]\n",_x,_y,_z,_w); }
