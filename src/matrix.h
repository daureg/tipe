#ifndef __MATRIX
#define __MATRIX
#include <cmath>
#include "vector.h"
class Matrix {
	public:
		Matrix();
		Matrix(const Matrix &m);
		Matrix(const float);
		Matrix(float *);
		virtual ~Matrix();

		Matrix operator+(const Matrix &m);
		Matrix operator-(const Matrix &m);
		Matrix operator*(const Matrix &m);
		Matrix operator*(const float &f);
		Vector4 operator*(const Vector4 &v);
		float operator()(Uint8, Uint8) const;

		void GetCoeff(float*) const;
		void SetCoeff(float*);
		bool LUP(Matrix &L, Matrix &U, Uint8 P[4]) const;
		Matrix Transpose() const;

		static Matrix Null();
		static Matrix Identity();
		static Matrix Random();
		static Matrix Translate(Vector4*);
		static Matrix Scale(float);
		static Matrix RotationAxis(Vector4*, float);

		void Print();
	private:
		void Zero();

		float m_coeff[16];
};
#endif
