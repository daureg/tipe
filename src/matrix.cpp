#include "matrix.h"
Matrix::Matrix(const float f) {
	for (int i=0; i<16; i++)
		m_coeff[i]=f;
}
Matrix::Matrix(float l1[4],float l2[4],float l3[4],float l4[4]) {
	int i=0;
	for (i=0; i<4; i++)
		m_coeff[i]=l1[i];
	for (i=0; i<4; i++)
		m_coeff[i+4]=l2[i];
	for (i=0; i<4; i++)
		m_coeff[i+8]=l3[i];
	for (i=0; i<4; i++)
		m_coeff[i+12]=l4[i];
}
Matrix::~Matrix() {}
Matrix Matrix::operator+(const Matrix &m) {
	float tmp[4][4];
	Uint8 i,j;
	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
			tmp[i][j] = m_coeff[4*i+j]+m(i+1,j+1);
	return Matrix(tmp[0],tmp[1],tmp[2],tmp[3]);
}

Matrix Matrix::operator-(const Matrix &m) {
	float tmp[4][4];
	Uint8 i,j;
	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
			tmp[i][j] = m_coeff[4*i+j]-m(i+1,j+1);
	return Matrix(tmp[0],tmp[1],tmp[2],tmp[3]);
}

Matrix Matrix::operator*(const Matrix &m) {
	float tmp[4][4],t=0.0f;
	Uint8 i,j,k;
	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
		{
			for (k=0; k<4; k++)
				t+=m_coeff[4*k+i]*m(i+1,j+1);
			tmp[i][j]=t;
			t=0.0f;
		}
	return Matrix(tmp[0],tmp[1],tmp[2],tmp[3]);
}

Vector4 Matrix::operator*(const Vector4 &v) {
	float tmp[3],t=0.0f;
	Uint8 i,j;
	for (i=0; i<4; i++)
	{
		for (j=0; j<4; j++)
			t+=m_coeff[4*i+j]*v(j+1);
		tmp[i]=t;
		t=0.0f;
	}
	return Vector4(tmp[0],tmp[1],tmp[2],int(v(4)));
}
Matrix Matrix::operator*(const float &f) {
	float tmp[4][4];
	Uint8 i,j;
	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
			tmp[i][j] = m_coeff[4*i+j]*f;
	return Matrix(tmp[0],tmp[1],tmp[2],tmp[3]);
}

float Matrix::operator() (Uint8 r, Uint8 c) const {
	return m_coeff[4*(r-1)+c-1];
}
Matrix Matrix::Identity() {
	float tmp[4][4];
	for (Uint8 i=0; i<4; i++)
		for (Uint8 j=0; j<4; j++)
				(i==j) ? tmp[i][j]=1.0f : tmp[i][j]=0.0f;
	return Matrix(tmp[0],tmp[1],tmp[2],tmp[3]);
}
Matrix Matrix::RotationAxis(Vector4 axis, float r) {
	Vector4 ax = axis.Normalize();
	ax.Print();
	float x=ax(1);
	float y=ax(2);
	float z=ax(3);
	float a[4] = {0.0f};
	float b[4] = {0.0f};
	float c[4] = {0.0f};
	float d[4] = {0.0f,0.0f,0.0f,1.0f};
	a[0]=x*x; a[1]=x*y; a[2]=x*z; a[3]=0.0f;
	b[0]=y*x; b[1]=y*y; b[2]=y*z; b[3]=0.0f;
	c[0]=z*x; c[1]=z*y; c[2]=z*z; c[3]=0.0f;
	Matrix P=Matrix(a,b,c,d);
	a[0]=0.0f; a[1]=-z; a[2]=y; a[3]=0.0f;
	b[0]=z; b[1]=0.0f; b[2]=-x; b[3]=0.0f;
	c[0]=-y; c[1]=x; c[2]=0.0f; c[3]=0.0f;
	Matrix Q=Matrix(a,b,c,d);
	return P + (Matrix::Identity() - P)*cosf(r) + Q*sinf(r);
}

void Matrix::Print() {
	Uint8 i,j;
	for (i=0; i<4; i++)
	{
		for (j=0; j<4; j++)
			printf("%.4f ",m_coeff[4*i+j]);
		printf("\n");
	}
}
