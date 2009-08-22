#include "vector.h"
Vector4::Vector4() { for(Uint8 i=0;i<4;i++) m_t[i]=0.0f; }
Vector4::Vector4(float f) { for(Uint8 i=0;i<4;i++) m_t[i]=f; }
Vector4::Vector4(float *t) { for(Uint8 i=0;i<4;i++) m_t[i]=t[i]; }
Vector4::Vector4(float x,float y,float z,float w){m_t[0]=x;m_t[1]=y;m_t[2]=z;m_t[3]=w;}
Vector4::Vector4(const Vector4 &v) { for(Uint8 i=0;i<4;i++) m_t[i]=v(i+1);}
Vector4::~Vector4() {}

Vector4 Vector4::operator-() const { return Vector4(-m_t[0],-m_t[1],-m_t[2],-m_t[3]); }
Vector4 Vector4::operator+(const Vector4 &v) const {
	return Vector4(v(1)+m_t[0], v(2)+m_t[1], v(3)+m_t[2], v(4)+m_t[3]);
}
Vector4 Vector4::operator-(const Vector4 &v) const {
	return Vector4(v(1)-m_t[0], v(2)-m_t[1], v(3)-m_t[2], v(4)-m_t[3]);
}
Vector4 Vector4::operator*(const float &f) const {
	return Vector4(f*m_t[0], f*m_t[1], f*m_t[2], f*m_t[3]);
}
Vector4 Vector4::operator*(const Vector4 &v) const {
	return Vector4(m_t[1]*v(3)-m_t[2]*v(2), m_t[2]*v(1)-m_t[0]*v(3), m_t[0]*v(2)-m_t[1]*v(1),m_t[3]);
}
float Vector4::operator/(const Vector4 &v) const {
	return m_t[0]*v(1)+m_t[1]*v(2)+m_t[2]*v(3);
}
bool Vector4::operator==(const Vector4 &v) const {
	return (cmp(m_t[0],v(1)) && cmp(m_t[1],v(2)) && cmp(m_t[2],v(3)) && cmp(m_t[3],v(4)));
}
bool Vector4::operator!=(const Vector4 &v) const { 
	return !(cmp(m_t[0],v(1)) && cmp(m_t[1],v(2)) && cmp(m_t[2],v(3)) && cmp(m_t[3],v(4)));
}
float Vector4::operator() (Uint8 c) const { return m_t[Clamp(c,1,4)-1]; }
float Vector4::Component(Uint8 c) const { return m_t[Clamp(c,1,4)-1]; }
float Vector4::Norm() const { return std::sqrt(m_t[0]*m_t[0]+m_t[1]*m_t[1]+m_t[2]*m_t[2]);}
Vector4 Vector4::Normalize() { 
	float f=1/std::sqrt(m_t[0]*m_t[0]+m_t[1]*m_t[1]+m_t[2]*m_t[2]);
	return Vector4(f*m_t[0], f*m_t[1], f*m_t[2], m_t[3]);
}
void Vector4::Print() const { printf("[ %f, %f, %f, %f]\n",m_t[0],m_t[1],m_t[2],m_t[3]); }
Vector4 Vector4::Null() { return Vector4(); }
