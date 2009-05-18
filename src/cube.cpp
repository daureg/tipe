#include "cube.h"
Cube::Cube():m_size(1.0f) {
	Vector4 v=Vector4(0.0f);
	m_center=v;
	m_coord.reserve(8);
	Build();
	Uint16 x,y;
	for (int i=0; i<8; i++)
	{
		m_cam->Projection(m_coord[i],x,y);
		m_points[i].SetPosX(x);
		m_points[i].SetPosX(y);
	}
}
Cube::Cube(Vector4 c, Uint16 s, Cam *cam):m_center(c),m_size(s),m_cam(cam) {
	m_coord.reserve(8);
	Build();
	Uint16 x,y;
	for (int i=0; i<8; i++)
	{
		m_cam->Projection(m_coord[i],x,y);
		m_points[i].SetPosX(x);
		m_points[i].SetPosX(y);
	}
}
Cube::~Cube() {}

Vector4 Cube::GetCenter() const { return m_center; }
Uint16 Cube::GetSize() const { return m_size; }
void Cube::SetCenter(Vector4 p) { m_center=p; }
void Cube::SetSize(Uint16 s) { m_size = s; }
void Cube::SetCam(Cam *c) { m_cam = c;}

void Cube::Build() {
	static float a=1.0f;
	m_coord[0]=Vector4(a,a,-a,1);
	m_coord[1]=Vector4(a,-a,-a,1);
	m_coord[2]=Vector4(a,-a,a,1);
	m_coord[3]=Vector4(a,a,a,1);
	m_coord[4]=Vector4(-a,a,-a,1);
	m_coord[5]=Vector4(-a,-a,-a,1);
	m_coord[6]=Vector4(-a,-a,a,1);
	m_coord[7]=Vector4(-a,a,a,1);
}
void Cube::Draw(SDL_Surface *screen) {
	Uint16 x,y;
	static int count = 0;
	count++;
	for (int i=0; i<8; i++)
	{
		if (count%300==0)
		{
			m_cam->Projection(m_coord[i],x,y);
			m_points[i].SetPosX(x);
			m_points[i].SetPosY(y);
			//printf("point %d (%d,%d)\n",i,m_points[i].GetPosX(),m_points[i].GetPosY());
		}
		m_points[i].Draw(screen);
	}
}
void Cube::Anim(Uint16 elapsed,user_input* ui) {}
void Cube::Input(user_input* ui) {}
