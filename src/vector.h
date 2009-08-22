#ifndef __VECTOR4
#define __VECTOR4
#include <cstdio>
#include <cmath>
#include "utils.h"
class Vector4 {
	public:
		Vector4();
		Vector4(float);
		Vector4(float*);
		Vector4(float,float,float,float);
		Vector4(const Vector4 &v);
		~Vector4();

		Vector4 operator-() const;

		Vector4 operator+(const Vector4 &) const;
		Vector4 operator-(const Vector4 &) const;
		Vector4 operator*(const float  &) const;
		// dot product (scalaire)
		float operator/(const Vector4 &) const;
		// cross product
		Vector4 operator*(const Vector4 &) const;
		float operator()(Uint8) const;
		bool operator==(const Vector4 &) const;
		bool operator!=(const Vector4 &) const;

		static Vector4 Null();
		
		float Component(Uint8) const;

		float Norm() const;
		Vector4 Normalize();
		void Print() const;
	private:
		float m_t[4];
};
#endif
