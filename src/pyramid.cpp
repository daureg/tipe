#include "pyramid.h"
Pyramid::Pyramid():m_height(1.0f) { Reset(); }
Pyramid::Pyramid(float scale, Vector4 pos, LearningCam cam):m_height(scale),m_pos(pos),m_cam(cam) {
	Reset();
	Move(m_pos);
	Scale(m_height);
}
Pyramid::~Pyramid() {}
void Pyramid::Reset() {
	m_vert[0] = 0.0f;
	m_vert[1] = 2.0f;
	m_vert[2] = 0.0f;
	m_vert[3] = 0.5f;
	m_vert[4] = -1.0f;
	m_vert[5] = -std::sqrt(3)/6.0f;
	m_vert[6] = 0.0f;
	m_vert[7] = -1.0f;
	m_vert[8] = std::sqrt(3)/3.0f;
	m_vert[9] = -0.5f;
	m_vert[10] = -1.0f;
	m_vert[11] = -std::sqrt(3)/6.0f;
	m_idx[0] = 0; m_idx[1] = 2; m_idx[2] = 1; m_idx[3] = 0; m_idx[4] = 3; m_idx[5] = 2; m_idx[6] = 0; m_idx[7] = 1; m_idx[8] = 3; m_idx[9] = 1; m_idx[10] = 2; m_idx[11] = 3;
}
void Pyramid::Move(Vector4 mvt) {
	m_pos = m_pos + mvt;
	Transform(&Matrix::Translate(&mvt));
}
void Pyramid::Scale(float s) {
	m_height*=s;
	Transform(&Matrix::Scale(s));
}
void Pyramid::Transform(Matrix *t) {
	Vector4 v;
	for (Uint8 i = 0; i < 4; i++) {
		v=*t*Vector4(m_vert[3*i],m_vert[3*i+1],m_vert[3*i+2],1.0f);
		m_vert[3*i] = v(1);
		m_vert[3*i+1] = v(2);
		m_vert[3*i+2] = v(3);
	}
}
void Pyramid::TDraw(LearningCam *cam) {
	Vector4 rs,pos;
	static Uint32 c=0;
	c++;
	Uint16 pt[8];
	static Uint8 order[9] = {0,2,1,3,2,0,3,1,0};
	Uint16 x,y;
	for (Uint8 i = 0; i < 4; i++) {
		pos=Vector4(m_vert[3*i],m_vert[3*i+1],m_vert[3*i+2],1.0f);
		rs=cam->Proj(&pos);
		x=(rs(1)/rs(4)+1)*(RES_X)/2;
		y=(rs(2)/rs(4)+1)*(RES_Y)/2;
		pt[2*i]=x;
		pt[2*i+1]=y;
		/*
		if (c%(2*1200)==0) {
			printf("%d : ",i+1);
			printf("(%d, %d) ",x,y);
			pos.Print();
			rs.Print();
		}
		*/
	}
	if (c%(2*1400)==0) {
		printf("d : %f\n", (cam->GetPos()-pos).Norm());
	//	cam->Print();
	}
	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/
	glBegin(GL_POINTS);
	glColor3ub(255,0,0);
	for (Uint8 i = 0; i < 4; i++)
		glVertex2i(pt[2*i], pt[2*i+1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3ub(0,0,255);
	for (Uint8 i = 0; i < 9; i++)
		glVertex2i(pt[2*order[i]], pt[2*order[i]+1]);
	glEnd();


}
void Pyramid::Draw(SDL_Surface *screen) {
}
void Pyramid::Anim(Uint16 elapsed, Input *ui) {}
