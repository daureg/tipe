#include "cube.h"
Cube::Cube():m_size(1.0f) {
	Vector4 v=Vector4(0.0f);
	m_center=v;
	m_coord.reserve(8);
	Build();
}
Cube::Cube(Vector4 c, Uint16 s, Cam *cam):m_center(c),m_size(s),m_cam(cam) {
	m_coord.reserve(8);
	Build();
}
Cube::~Cube() {}

Vector4 Cube::GetCenter() const { return m_center; }
Uint16 Cube::GetSize() const { return m_size; }
void Cube::SetCenter(Vector4 p) { m_center=p; }
void Cube::SetSize(Uint16 s) { m_size = s; }
void Cube::SetCam(Cam *c) { m_cam = c;}

void Cube::Build() {
	static float a=1.0f;
	Uint16 x,y;
	m_coord[0]=Vector4(a,a,-a,1);
	m_coord[1]=Vector4(a,-a,-a,1);
	m_coord[2]=Vector4(a,-a,a,1);
	m_coord[3]=Vector4(a,a,a,1);
	m_coord[4]=Vector4(-a,a,-a,1);
	m_coord[5]=Vector4(-a,-a,-a,1);
	m_coord[6]=Vector4(-a,-a,a,1);
	m_coord[7]=Vector4(-a,a,a,1);
	for (int i=0; i<8; i++)
	{
		//m_cam->Projection(m_coord[i],x,y);
		m_points[i].SetPosX(x);
		m_points[i].SetPosX(y);
	}
	m_aux_lines[0]=0;m_aux_lines[1]=1;
	m_aux_lines[2]=1;m_aux_lines[3]=2;
	m_aux_lines[4]=2;m_aux_lines[5]=3;
	m_aux_lines[6]=3;m_aux_lines[7]=0;

	m_aux_lines[8]=0;m_aux_lines[9]=4;
	m_aux_lines[10]=1;m_aux_lines[11]=5;
	m_aux_lines[12]=2;m_aux_lines[13]=6;
	m_aux_lines[14]=3;m_aux_lines[15]=7;

	m_aux_lines[16]=4;m_aux_lines[17]=5;
	m_aux_lines[18]=5;m_aux_lines[19]=6;
	m_aux_lines[20]=6;m_aux_lines[21]=7;
	m_aux_lines[22]=7;m_aux_lines[23]=4;
}
void Cube::Draw(SDL_Surface *screen) {
	Uint16 x,y;
	static int count = 99;
	count++;
	if (count%100==0)
	{
		for (int i=0; i<8; i++)
		{
		//m_cam->Projection(m_coord[i],x,y);
		m_points[i].SetPosX(x);
		m_points[i].SetPosY(y);
		m_points[i].Draw(screen);
		}
		for (int i=0; i<12; i++)
		{
			m_lines[i].SetPosX1(m_points[m_aux_lines[2*i]].GetPosX());
			m_lines[i].SetPosY1(m_points[m_aux_lines[2*i]].GetPosY());
			m_lines[i].SetPosX2(m_points[m_aux_lines[2*i+1]].GetPosX());
			m_lines[i].SetPosY2(m_points[m_aux_lines[2*i+1]].GetPosY());
			m_lines[i].Draw(screen);
		}

	}
}
void Cube::Anim(Uint16 elapsed,user_input* ui) {}
void Cube::Input(user_input* ui) {}
