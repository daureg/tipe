#include "matrix.h"
Matrix::Matrix() { Zero(); }
Matrix::Matrix(const Matrix &m) {m.GetCoeff(m_coeff);}
Matrix::Matrix(const float f) {
	for (Uint8 i=0; i<16; i++)
			m_coeff[i] = f;
}
Matrix::Matrix(float *t) { SetCoeff(t);}
Matrix::~Matrix() {}
Matrix Matrix::operator+(const Matrix &m) {
	float tmp[16];
	Uint8 i,j;
	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
			tmp[4*i+j] = m_coeff[4*i+j]+m(i+1,j+1);
	return Matrix(tmp);
}

Matrix Matrix::operator-(const Matrix &m) {
	float tmp[16];
	Uint8 i,j;
	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
			tmp[4*i+j] = m_coeff[4*i+j]-m(i+1,j+1);
	return Matrix(tmp);
}

Matrix Matrix::operator*(const Matrix &m) {
	float tmp[16],t=0.0f;
	Uint8 i,j,k;
	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
		{
			for (k=0; k<4; k++)
				t+=m_coeff[4*i+k]*m(k+1,j+1);
			tmp[4*i+j]=t;
			t=0.0f;
		}
	return Matrix(tmp);
}

Vector4 Matrix::operator*(const Vector4 &v) {
	float tmp[4];
	float t;
	Uint8 i,j;
	for (i=0; i<4; i++)
	{
		t=0.0f;
		for (j=0; j<4; j++)
			t+=m_coeff[4*i+j]*v(j+1);
		tmp[i]=t;
	}
	return Vector4(tmp[0],tmp[1],tmp[2],tmp[3]);
}
Matrix Matrix::operator*(const float &f) {
	float tmp[16];
	for (Uint8 i=0; i<16; i++)
			tmp[i] = m_coeff[i]*f;
	return Matrix(tmp);
}
float Matrix::operator() (Uint8 r, Uint8 c) const { return m_coeff[4*(r-1)+c-1]; }
void Matrix::GetCoeff(float *t) const {for (Uint8 i=0;i<4*4;i++) t[i]=m_coeff[i];}
void Matrix::SetCoeff(float *t) {for (Uint8 i=0;i<4*4;i++) m_coeff[i]=t[i];}
bool Matrix::LUP(Matrix &L, Matrix &U, Uint8 P[4]) const {
	float a[16];
	float l[16] = {0.0f};
	float u[16] = {0.0f};
	float p;
	Uint8 i,k2,j;
	GetCoeff(a); //Copy the current Matrix data into a
	P[0]=0;P[1]=1;P[2]=2;P[3]=3;
	l[0]=1.0f;l[5]=1.0f;l[10]=1.0f;l[15]=1.0f;
	for (Uint8 k = 0; k < 4; k++) {
		p=0.0f;
		for (i = k; i < 4; i++)
			if (abs(a[4*i+k])>p) {
				p=abs(a[4*i+k]);
				k2=i;
			}
		if (cmp(p,0.0f))
			return false; // non-inversible
		Swap(P,k,k2);
		for (i = 0; i < 4; i++) {
			Swap(a,k,i,k2,i);
			if ( k > i && k2 > i)
				Swap(l,k,i,k2,i);
		}

		for (j=k;j<4;j++)
			u[4*k+j]=a[4*k+j];
		for (i = k+1; i < 4; i++) {
			l[4*i+k] = a[4*i+k]/a[4*k+k];
			for (j=k+1;j<4;j++)
				a[4*i+j]-=l[4*i+k]*u[4*k+j];
		}	
	}
	L.SetCoeff(l);
	U.SetCoeff(u);
	return true;
}
Matrix Matrix::Transpose() const {
	float a[16];
	for (Uint8 i=0; i<4; i++)
		for (Uint8 j=0; j<4; j++)
			a[i*4+j] = m_coeff[j*4+i];
	return Matrix(a);
}

Matrix Matrix::Null() { return Matrix(); }
Matrix Matrix::Identity() {
	float tmp[16];
	for (Uint8 i=0; i<16; i++)
		(i%5) ? tmp[i]=.0f : tmp[i]=1.0f;
	return Matrix(tmp);
}
Matrix Matrix::Random() {
	float tmp[16];
	for (Uint8 i=0; i<16; i++)
		tmp[i]=::Random(0.0f,5.0f);
	return Matrix(tmp);
}
Matrix Matrix::Scale(float f) {
	return Matrix::Identity()*f;
}
Matrix Matrix::Translate(Vector4 *v) {
	float tmp[16];
	for (Uint8 i=0; i<15; i++)
		((1+i)%4) ? ((i%5) ? tmp[i]=0.0f : tmp[i]=1.0f) : tmp[i]=(*v)((1+i)/4);
	tmp[15]=1.0f;
	return Matrix(tmp);
}
Matrix Matrix::RotationAxis(Vector4* axis, float r) {
	Vector4 ax = axis->Normalize();
	float x=ax(1);
	float y=ax(2);
	float z=ax(3);
	float p[16] = {0.0f};
	p[0]=x*x; p[1]=x*y; p[2]=x*z; p[3]=0.0f;
	p[4]=y*x; p[5]=y*y; p[6]=y*z; p[7]=0.0f;
	p[8]=z*x; p[9]=z*y; p[10]=z*z; p[11]=0.0f;
	p[12]=.0f;p[13]=.0f;p[14]=.0f;p[15]=1.0f;
	Matrix P=Matrix(p);
	p[0]=0.0f; p[1]=-z;   p[2]=y;     p[3]=0.0f;
	p[4]=z;	   p[5]=0.0f; p[6]=-x;    p[7]=0.0f;
	p[8]=-y;   p[9]=x;    p[10]=0.0f; p[11]=0.0f;
	p[15]=0.0f;
	Matrix Q=Matrix(p);
	return P + (Matrix::Identity() - P)*cosf(r) + Q*sinf(r);
}

void Matrix::Print() {
	Uint8 i;
	for (i=0; i<16; i++)
		((1+i)%4) ? printf("%.4f ",m_coeff[i]) : printf("%.4f\n",m_coeff[i]);
}
void Matrix::Zero() {
	for (Uint8 i=0; i<16; i++)
		m_coeff[i]=0.0f;
}
