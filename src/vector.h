#ifndef __VECTOR4
#define __VECTOR4
#include <cstdio>
#include <cmath>
#include "utils.h"
class Vector4 {
	public:
		Vector4();
		Vector4(float);
		Vector4(float,float,float,Uint8);
		~Vector4();

		float x() const;
		float y() const;
		float z() const;
		Uint8 w() const;

		Vector4 operator+(const Vector4 &);
		Vector4 operator-(const Vector4 &);
		Vector4 operator*(const float  &);
		// dot product (scalaire)
		float operator/(const Vector4 &);
		// cross product
		Vector4 operator*(const Vector4 &);
		float operator()(Uint8) const;
		bool operator==(const Vector4 &);

		float Norm() const;
		Vector4 Normalize();
		void Print() const;
	private:
		float _x;
		float _y;
		float _z;
		Uint8 _w;
};
#endif
