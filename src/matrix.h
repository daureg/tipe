#ifndef __MATRIX
#define __MATRIX
#include "vector.h"
class Matrix {
	public:
		Matrix(const float);
		Matrix(float a[4],float b[4],float c[4],float d[4]);
		~Matrix();

		Matrix operator+(const Matrix &m);
		Matrix operator-(const Matrix &m);
		Matrix operator*(const Matrix &m);
		Matrix operator*(const float &f);
		Vector4 operator*(const Vector4 &v);
		float operator()(Uint8, Uint8) const;

		static Matrix Identity();
		static Matrix RotationAxis(Vector4, float);

		void Print();
	private:
		float m_coeff[16];
};
#endif
