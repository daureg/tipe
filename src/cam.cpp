#include "cam.h"
Cam::Cam():m_up(Vector4(0.0f,1.0f,0.0f,0.0f)),m_look(Vector4(0.0f,0.0f,-1.0f,0.0f)),
	m_right(Vector4(1.0f,0.0f,0.0f,0.0f)) {}
Cam::Cam(Vector4 *p):m_pos(*p),m_up(Vector4(0.0f,1.0f,0.0f,0.0f)),m_look(Vector4(0.0f,0.0f,-1.0f,0.0f)),
	m_right(Vector4(1.0f,0.0f,0.0f,0.0f)) {}
void Cam::Anim(Uint16 elapsed, Input *ui)
{
	float _speed = 0.01f*(ui->IsPressed("speed") ? 10.0f : 1.0f);
	float rot_speed = 0.09f*(ui->IsPressed("speed") ? 4.0f : 1.0f); // 45 degres in 500 ms
	if (ui->IsPressed("forward"))
		m_pos = m_pos + m_look * (_speed * elapsed);
	if (ui->IsPressed("backward"))
		m_pos = m_pos - m_look * (_speed * elapsed);
	if (ui->IsPressed("up"))
		m_pos = m_pos + m_up * (_speed * elapsed);
	if (ui->IsPressed("down"))
		m_pos = m_pos - m_up * (_speed * elapsed);
	if (ui->IsPressed("left"))
		m_pos = m_pos - m_right * (_speed * elapsed);
	if (ui->IsPressed("right"))
		m_pos = m_pos + m_right * (_speed * elapsed);
	if (ui->IsPressed("look_left"))
		this->Turn(UP,rot_speed*elapsed);
	if (ui->IsPressed("look_right"))
		this->Turn(UP,-rot_speed*elapsed);
	if (ui->IsPressed("look_up"))
		this->Turn(RIGHT,rot_speed*elapsed);
	if (ui->IsPressed("look_down"))
		this->Turn(RIGHT,-rot_speed*elapsed);
}
void Cam::Look() {
	Vector4 _target = m_pos + m_look;
	gluLookAt(m_pos(1),m_pos(2),m_pos(3),_target(1),_target(2),_target(3),0,1,0);
}
Cam::~Cam() {}
void Cam::RemakeBase() {
	m_look = m_look.Normalize();
	m_up = -(m_look*m_right);
	m_up = m_up.Normalize();
	m_right = -(m_up*m_look);
	m_right = m_right.Normalize();
}
void Cam::Move(Vector4 *mvt) {m_pos = m_pos + *mvt;}
void Cam::Turn(ROTATION_AXIS around, float angle) {
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
void Cam::Draw(SDL_Surface *s) {}
void Cam::Print() const {
	printf("p:");m_pos.Print(); 
	printf("r:");m_right.Print(); 
	printf("l:");m_look.Print(); 
	printf("u:");m_up.Print();
}
