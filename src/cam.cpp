#include "cam.h"
Cam::Cam():m_rotx(0.0f),m_roty(0.0f),m_rotz(0.0f),m_fov(.78f){}
Cam::Cam(Vector4 pos, float x, float y, float z, float fov)
	:m_pos(pos),m_rotx(x),m_roty(y),m_rotz(z),m_fov(fov) {}/*
Cam::Cam(Vector4 p, Vector4 u, Vector4 r, Vector4 l, Vector4 fov)
	:m_pos(&p),m_up(&u),m_right(&r),m_look(&l),m_fov(fov) {}*/
Cam::~Cam() {}
Vector4 Cam::GetPos() const {return m_pos;}
float Cam::GetRotX() const {return m_rotx;}
float Cam::GetRotY() const {return m_rotz;}
float Cam::GetRotZ() const {return m_rotz;}
float Cam::GetFov() const {return m_fov;}


void Cam::SetPos(Vector4 p) {m_pos=p;}
void Cam::SetRotX(float x) {m_rotx=x;}
void Cam::SetRotY(float y) {m_roty=y;}
void Cam::SetRotZ(float z) {m_rotz=z;}

void Cam::Anim(Uint16 elapsed, user_input *ui) {}

void Cam::Projection(Vector4 pos, Uint16 &nx, Uint16 &ny) {
	//Only do the calcul if it's make sense, ie the point will
	//not be out of the screen.
	Vector4 p=pos - m_pos;
	float px,py;
	float x=m_rotx;
	float y=m_roty;
	float z=m_rotz;
	float a[4]={cosf(-z),sinf(-z),0.0f,0.0f};
	float b[4]={-sinf(-z),cosf(-z),0.0f,0.0f};
	float c[4]={0.0f,0.0f,1.0f,0.0f};
	float d[4]={0.0f,0.0f,0.0f,1.0f};
	Matrix Z=Matrix(a,b,c,d);
	a[0]=cosf(-y); a[1]=0.0f; a[2]=-sinf(-y); a[3]=0.0f; 
	b[0]=0.0f; b[1]=1.0f; b[2]=0.0f; b[3]=0.0f; 
	c[0]=sinf(-y); c[1]=0.0f; c[2]=cosf(-y); c[3]=0.0f; 
	d[0]=0.0f; d[1]=0.0f; d[2]=0.0f; d[3]=1.0f; 
	Matrix Y=Matrix(a,b,c,d);
	a[0]=1.0f; a[1]=0.0f; a[2]=0.0f; a[3]=0.0f; 
	b[0]=0.0f; b[1]=cosf(-x); b[2]=sinf(-x); b[3]=0.0f; 
	c[0]=0.0f; c[1]=-sinf(-z); c[2]=cosf(-z); c[3]=0.0f; 
	d[0]=0.0f; d[1]=0.0f; d[2]=0.0f; d[3]=1.0f; 
	Matrix X=Matrix(a,b,c,d);
	Vector4 D=X*Y*Z*p;
	float f=m_fov;
	float e=1.0f/tanf(f/2);
	px=(D(1)-m_pos(1))*(e/D(3));
	py=(D(2)-m_pos(2))*(e/D(3));
	if (px < 1.0f && px > -1.0f && py < 1.0f && py > -1.0f)
	{
		nx = int((RES_X/2)*(px+1));
		ny = int((RES_Y/2)*(py+1));
	}
	else
	{
		nx=2*RES_X;
		ny=2*RES_Y;
	}
}
