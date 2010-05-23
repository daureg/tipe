#include "learning_cam.h"
LearningCam::LearningCam():m_up(Vector4(0.0f,1.0f,0.0f,0.0f)),m_look(Vector4(0.0f,0.0f,-1.0f,0.0f)),
	m_right(Vector4(1.0f,0.0f,0.0f,0.0f)),m_fov(M_PI_2),m_aspect(0.75f),m_near(1.0f),m_far(100.0f) {
	MakeProjectionMatrix();
	MakeAlignMatrix();
}
LearningCam::LearningCam(Vector4 *p):m_pos(*p),m_up(Vector4(0.0f,1.0f,0.0f,0.0f)),m_look(Vector4(0.0f,0.0f,-1.0f,0.0f)),
	m_right(Vector4(1.0f,0.0f,0.0f,0.0f)) {}
LearningCam::LearningCam(Vector4 *p, Vector4 *l, Vector4 *u, Uint8 fov, float a, float n, float f): 
	m_pos(*p),m_up(u->Normalize()),m_look(l->Normalize()), m_right(-(m_up*m_look)),
       	m_fov(DegToRad(fov)), m_aspect(a), m_near(n), m_far(f) {
	MakeProjectionMatrix();
	MakeAlignMatrix();
}
LearningCam::~LearningCam() {}
Vector4 LearningCam::Proj(Vector4 *p) { return m_full*(*p); }
void LearningCam::Move(Vector4 *mvt) {m_pos = m_pos + *mvt;}
void LearningCam::Turn(ROTATION_AXIS around, float angle) {
	Matrix m;
	angle=DegToRad(angle);
	switch (around) {
		case RIGHT:
			m = Matrix::RotationAxis(&m_right, angle);
			m_look = m*m_look;
			m_up = m*m_up;
			break;
		case LOOK:
			m = Matrix::RotationAxis(&m_look, angle);
			m_right = m*m_right;
			m_up = m*m_up;
			break;
		case UP:
			m = Matrix::RotationAxis(&m_up, angle);
			m_look = m*m_look;
			m_right = m*m_right;
			break;
	}
	RemakeBase();
}
void LearningCam::Print() {
	printf("p:");m_pos.Print(); 
	printf("r:");m_right.Print(); 
	printf("l:");m_look.Print(); 
	printf("u:");m_up.Print();
}
void LearningCam::Anim(Uint16 elapsed, Input *ui) {
	float _speed = 0.01f*(ui->IsPressed("speed") ? 10.0f : 1.0f);
	float rot_speed = 0.09f*(ui->IsPressed("speed") ? 4.0f : 1.0f); // 45 degres in 500 ms
	static int count=0;
	count++;
	if (ui->IsPressed("forward"))
		m_pos = m_pos + m_look * (_speed * elapsed);
	if (ui->IsPressed("backward"))
		m_pos = m_pos - m_look * (_speed * elapsed);
	if (ui->IsPressed("down"))
		m_pos = m_pos + m_up * (_speed * elapsed);
	if (ui->IsPressed("up"))
		m_pos = m_pos - m_up * (_speed * elapsed);
	if (ui->IsPressed("left"))
		m_pos = m_pos - m_right * (_speed * elapsed);
	if (ui->IsPressed("right"))
		m_pos = m_pos + m_right * (_speed * elapsed);
	if (ui->IsPressed("look_left"))
		Turn(UP,rot_speed*elapsed);
	if (ui->IsPressed("look_right"))
		Turn(UP,-rot_speed*elapsed);
	if (ui->IsPressed("look_down"))
		Turn(RIGHT,rot_speed*elapsed);
	if (ui->IsPressed("look_up"))
		Turn(RIGHT,-rot_speed*elapsed);
	if (count%50==0)
		RemakeBase(); //make sure the base is still orthonormal
	MakeAlignMatrix();
}
void LearningCam::RemakeBase() {
	m_look = m_look.Normalize();
	m_up = -(m_look*m_right);
	m_up = m_up.Normalize();
	m_right = -(m_up*m_look);
	m_right = m_right.Normalize();
}
void LearningCam::MakeProjectionMatrix() {
	float n = m_near;
	float f = m_far;
	float l = -n*tan(m_fov*0.5f);
	float r = -l;
	float b = m_aspect*l;
	float t = -b;
	float r11c[16];
	r11c[0] = 2*n/(r-l);
	r11c[1] = 0.0f;
	r11c[2] = 0.0f;// (r+l)/(r-l);
	r11c[3] = 0.0f;
	r11c[4] = 0.0f;
	r11c[5] = 2*n/(t-b);
	r11c[6] = 0.0f;//(t+b)/(t-b);
	r11c[7] = 0.0f;
	r11c[8] = 0.0f;
	r11c[9] = 0.0f;
	r11c[10] = (f+n)/(n-f);
	r11c[11] = (2*n*f)/(n-f);
	r11c[12] = 0.0f;
	r11c[13] = 0.0f;
	r11c[14] = -1.0f;
	r11c[15] = 0.0f;
	m_proj = Matrix(r11c);
}
void LearningCam::MakeAlignMatrix() {
	float r5ed[16];
	r5ed[0] = m_right(1);
	r5ed[1] = m_right(2);
	r5ed[2] = m_right(3);
	r5ed[3] = -m_pos(1);
	r5ed[4] = m_up(1);
	r5ed[5] = m_up(2);
	r5ed[6] = m_up(3);
	r5ed[7] = -m_pos(2);
	r5ed[8] = -m_look(1);
	r5ed[9] = -m_look(2);
	r5ed[10] = -m_look(3);
	r5ed[11] = -m_pos(3);
	r5ed[12] = 0.0f;
	r5ed[13] = 0.0f;
	r5ed[14] = 0.0f;
	r5ed[15] = 1.0f;
	m_align = Matrix(r5ed);
	m_full = m_proj * m_align;
}
void LearningCam::Draw(SDL_Surface *s) {}
Vector4 LearningCam::GetPos() const { return m_pos; }
